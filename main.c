#include "graph.h"

#include <stdio.h>
#include <stdbool.h>

#define STR_MAX 100

int main(int argc, char *argv[]) {
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
        int src;

        while (fscanf(f, "%s", &string[0]) == 1)
        {
            printf("read: %s\n", string);
            src = string[0] - 48;
            //sscanf(string, "%d-", &dest);
            printf("source: %d\n", src);
        }       
        if (f == NULL)
        {
            fprintf(stderr, "There is no such file\n");
            return 2;
        }
        fclose(f);

        printf("\n");
        i++;  
    }
    
    return 0;
}