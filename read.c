#include "graph.h"

void handleErrs (int code, char *string) {
    fprintf(stderr, string);
    exit(code);
}

void readFile (int argc, char *argv[]) {
    FILE *f;

    if (argc < 2)
        handleErrs(1, "Enter at least one text file\n");

    int i = 1;
    while (i < argc)
    {
        int V = 4;
        char string[STR_MAX];

        int f_i = 0;
        int s_i = 0;

        int cnt = 0;
        
        f = fopen(argv[i], "r");
        
        TGraph graph;
        initGraph(&graph, V);

        if (f == NULL)
            handleErrs(2, "There is no such file\n");
        
        while (fscanf(f, "%s", &string[0]) == 1)
        {
            f_i = cnt;
            int len = strlen(string);
            V = len/2+1;

            for (int e_cnt = 0; e_cnt < len; e_cnt++)
            {
                if (((e_cnt % 2) == 0) && ((string[e_cnt] - 48) == 1))
                {
                    s_i = e_cnt/2;
                    insertConn(&graph, f_i, s_i);
                }
            }
            cnt++;
        }
        printGraph(&graph, V, i);
        fclose(f);
        i++;  
    }
}