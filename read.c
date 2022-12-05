#include "graph.h"

int readFile(int argc, char *argv[]) {
    FILE *f;

    if (argc < 2)
    {
        fprintf(stderr, "Enter at least one text file\n");
        return 1;
    }

    int i = 1;
    while (i < argc)
    {
        f = fopen(argv[i], "r");

        char string[STR_MAX];
        int V = 0; 

        int f_i = 0;
        int s_i = 0;

        int cnt = 0;
        
        TGraph graph;

        if (f == NULL)
        {
            fprintf(stderr, "There is no such file\n");
            return 2;
        }

        while (fscanf(f, "%s", &string[0]) == 1)
        {
            f_i = cnt;
            int len = strlen(string);
            V = len/2+1;
            initGraph(&graph, V);

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
        fclose(f);
        i++;  
    }
    return 0;
}