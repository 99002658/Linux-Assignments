#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr1, *fptr2;
    char filename[100], c;

    printf("Enter the filename to open for reading \n");
    scanf("%s", filename);

    // Open one file for reading
    fptr1 = fopen(filename, "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s \n", filename);
        exit(0);
    }

    printf("Enter the filename to open for writing \n");
    scanf("%s", filename);

    // Open another file for writing
    fptr2 = fopen(filename, "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file %s \n", filename);
        exit(0);
    }

    // Read and write contents from file
    c = fgetc(fptr1);
    while (c != EOF)
    {
        fputc(c, fptr2); //writes character by charecter
        c = fgetc(fptr1); //reads character by charecter
    }

    printf("\nContents copied to %s\n", filename);

    fclose(fptr1);
    fclose(fptr2);
    return 0;
}
