#include <stdio.h>
#include <string.h>

#define PROGRAM_NAME "man"

int main(int argc, char *argv[])
{
    int mnf = 0;

    if (argv[1] == NULL) // Execute in `man`
    {
        printf("You can try the following commands:\n");
        printf("       ls, echo, cat, mkdir, rm, cd, pwd, wc\n");
        printf("\nOr use `man [CMD]...` to view the command manual.\n");
        printf("       For example: `man ls`\n");
    }
    else // Execute in `man CMD`
    {
        for (int i = 1; i < argc; i++)
        {
            // Find the command manual that needs to be printed
            if (strcmp(argv[i], "cd") == 0)
            {
            }
            else if (strcmp(argv[i], "pwd") == 0)
            {
            }
            else if (strcmp(argv[i], "ls") == 0)
            {
            }
            else if (strcmp(argv[i], "echo") == 0)
            {
            }
            else if (strcmp(argv[i], "cat") == 0)
            {
            }
            else if (strcmp(argv[i], "mkdir") == 0)
            {
            }
            else if (strcmp(argv[i], "rm") == 0)
            {
            }
            else if (strcmp(argv[i], "cd") == 0)
            {
            }
            else if (strcmp(argv[i], "wc") == 0)
            {
            }
            else if (strcmp(argv[i], "man") == 0)
            {
            }
            else
            {
                mnf = 1;
                printf("%s: manual not found\n", argv[i]);
            }
        }

        if (mnf)
        {
            printf("\nYou can try the following commands:\n");
            printf("       ls, echo, cat, mkdir, rm, cd, pwd, wc\n");
            printf("\nOr use `man [CMD]...` to view the command manual.\n");
            printf("       For example: `man ls`\n");
            mnf = 0;
        }
    }
    return 0;
}