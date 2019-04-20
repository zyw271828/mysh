#include <stdio.h>

#define PROGRAM_NAME "rm"

int main(int argc, char *argv[])
{
    if (argv[1] == NULL) // Execute in `rm`
    {
        printf(PROGRAM_NAME);
        printf(": missing operand\n");
    }
    else // Execute in `rm FILE`
    {
        for (int i = 1; i < argc; i++)
        {
            if (remove(argv[i]) != 0)
            {
                printf(PROGRAM_NAME);
                printf(": cannot remove \'");
                printf("%s\'\n", argv[i]);
            }
        }
    }
    return 0;
}