#include "graph.h"

#include <stdio.h>
#include <stdbool.h>

#define BUFF_MAX 50

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
            char buff[BUFF_MAX];
            int i = 0;
            if (c != '-')
            {
                buff[i] = c;
                i++;

                buff[i] = 0;
                readNode(buff);
            }
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