#include "graph.h"

#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    FILE *f;
    char c;

    if (argc < 2)
    {
        fprintf(stderr, "Enter at least one text file\n");
        return 1;
    }
    int i = 1;
    while (i < argc)
    {
        f = fopen(argv[i], "r");
        while ((c = fgetc(f)) != EOF)
        {
            if (c != '-') 
                readGraph(c);
        }
        
        if (f == NULL)
        {
            fprintf(stderr, "There is no such file\n");
            return 2;
        }

        fclose(f);
        
        i++;  
    }
    
    return 0;
}