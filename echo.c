#include <stdio.h>
#include <stdlib.h>

#define PROGRAM_NAME "echo"

void put_string(char *str);

int main(int argc, char *argv[])
{
    if (argv[1] == NULL) // Execute in `echo`
    {
        printf("\n");
    }
    else // Execute in `echo STR`
    {
        for (int i = 1; i < argc; i++)
        {
            put_string(argv[i]);
            if (i != argc - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

void put_string(char *str)
{
    while (*str)
    {
        if (*str == '\\') // May be an escape character
        {
            *str++;
            switch (*str)
            {
            case 'a':
                *str = '\a';
                break;
            case 'b':
                *str = '\b';
                break;
            case 'c':
                exit(0);
            case 'e':
                *str = '\x1B';
                break;
            case 'f':
                *str = '\f';
                break;
            case 'n':
                *str = '\n';
                break;
            case 'r':
                *str = '\r';
                break;
            case 't':
                *str = '\t';
                break;
            case 'v':
                *str = '\v';
                break;
            case '\\':
                break;
            default: // Not an escape character
                putchar('\\');
                break;
            }
            putchar(*str);
            str++;
        }
        else // Not an escape character
        {
            putchar(*str);
            str++;
        }
    }
}