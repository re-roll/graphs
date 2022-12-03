#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    FILE *f;
    char text;

    if (argc < 2)
    {
        fprintf(stderr, "Enter at least one text file\n");
        return 1;
    }

    int i = 1;
    while (i < argc)
    {
        f = fopen(argv[i], "r");
        do
        {
            text = fgetc(f);
            //printf("%c", text);
        } while (text != EOF);
        //printf("\n");
        
        if (f == NULL)
        {
            fprintf(stderr, "There is no such file\n");
            return 2;
        }

        //Ряд функций из граф.ц
        int graph = 0;

        fclose(f);

        if (graphIsReady(graph))
        {
            i++;
        }      
    }
    
    return 0;
}