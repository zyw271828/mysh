#include <stdio.h>
#include <sys/stat.h>

#define PROGRAM_NAME "mkdir"

int main(int argc, char *argv[])
{
    if (argv[1] == NULL) // Execute in `mkdir`
    {
        printf(PROGRAM_NAME);
        printf(": missing operand\n");
    }
    else // Execute in `mkdir DIR`
    {
        struct stat st = {0};

        if (stat(argv[1], &st) == -1) // No directory with the same name
        {
            if (mkdir(argv[1], 0700) != 0)
            {
                printf(PROGRAM_NAME);
                printf(": cannot create directory \'");
                printf("%s\': No such file or directory\n", argv[1]);
            }
        }
        else // A directory with the same name exists
        {
            printf(PROGRAM_NAME);
            printf(": cannot create directory \'");
            printf("%s\': File exists\n", argv[1]);
        }
    }
    return 0;
}