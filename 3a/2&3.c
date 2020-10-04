#include <stdio.h>
#include <stdlib.h>
int main()
{

    FILE * fPtr;
    char ch;
    int characters, words, lines;
    fPtr = fopen("TEST-for-3.txt", "r");
    if(fPtr == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
        exit(EXIT_FAILURE);
    }

    printf("File opened successfully. Reading file contents character by character. \n\n");
    do
    {
        ch = fgetc(fPtr);

        putchar(ch);

         characters = words = lines = 0;
    while ((ch = fgetc(fPtr)) != EOF)
    {
        characters++;

        if (ch == '\n' || ch == '\0')
            lines++;

        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            words++;
    }

    if (characters > 0)
    {
        words++;
        lines++;
    }

    printf("\n");
    printf("Total characters = %d\n", characters);
    printf("Total words      = %d\n", words);
    printf("Total lines      = %d\n", lines);


    } while(ch != EOF);


    fclose(fPtr);
    return 0;
}
