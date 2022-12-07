#include "graph.h"


/*Function check mistackes of the arguments*/
void handleErrs (int code, char *string) {
    fprintf(stderr, string);
    exit(code);
}


/*Function reads file. In the input It's reading our files and works with them.*/
void readFile (int argc, char *argv[]) {
    FILE *f;

    if (argc < 2) /*checking text file existence in command line*/ 
        handleErrs(1, "Enter at least one text file\n");

    int i = 1; 
    while (i < argc) /*cycle for reading text files from standart input in course*/
    {
        int V = 0;
        char string[STR_MAX];

        int f_i = 0;
        int s_i = 0;

        int cnt = 0;
        
        f = fopen(argv[i], "r");
//counting nodes in the graph
        while (fgets(string, STR_MAX, f)) 
            V++;
        //comeback to the start of the file
        rewind(f); 
        //creating an object type TGraph
        TGraph graph; 
        TPath path;
        initGraph(&graph, V);

        if (f == NULL)
            handleErrs(2, "There is no such file\n");
        //reading matrix
        while (fscanf(f, "%s", &string[0]) == 1)
        {
            f_i = cnt;
            int len = strlen(string);

            for (int e_cnt = 0; e_cnt < len; e_cnt++)
            {
                if (((e_cnt % 2) == 0) && ((string[e_cnt] - 48) == 1))
                {
                    s_i = e_cnt/2;
                    insertConn(&graph, f_i, s_i); //pass index with 1 
                }
            }
            cnt++;
        }
        printGraph(&graph, V, i);
        cycle(&graph, &path, V);
        fclose(f);
        i++;  
        freeGrap(&graph, V);
        freePath(&path);
    }
    
}