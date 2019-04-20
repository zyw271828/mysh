#include <stdio.h>

#define PROGRAM_NAME "cat"

void put_file(char *file_name);

int main(int argc, char *argv[])
{
    char c;

    if (argv[1] == NULL) // Execute in `cat`
    {
        while ((c = getchar()) != EOF)
        {
            putchar(c);
        }
    }
    else // Execute in `cat FILE`
    {
        for (int i = 1; i < argc; i++)
        {
            put_file(argv[i]);
        }
    }
    return 0;
}

void put_file(char *file_name)
{
    int c;
    FILE *file;

    file = fopen(file_name, "r");
    if (file)
    {
        while ((c = getc(file)) != EOF)
        {
            putchar(c);
        }
        fclose(file);
    }
}