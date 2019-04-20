#include <stdio.h>
#include <string.h>

#define PROGRAM_NAME "cat"

int put_file(char *file_name);

int main(int argc, char *argv[])
{
    char c;

    if (argv[1] == NULL || strcmp(argv[1], "-") == 0 || strcmp(argv[1], "--") == 0) // Execute in `cat`
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
            if (put_file(argv[i]) != 0)
            {
                printf(PROGRAM_NAME);
                printf(": %s: No such file or directory\n", argv[i]);
            }
        }
    }
    return 0;
}

int put_file(char *file_name)
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
        return 0;
    }
    else
    {
        return -1;
    }
}