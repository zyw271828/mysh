#include <dirent.h>
#include <stdio.h>

#define PROGRAM_NAME "ls"

int main(int argc, char *argv[])
{
    DIR *d;
    struct dirent *dir;

    if (argv[1] == NULL) // Execute in `ls`
    {
        if ((d = opendir(".")) != NULL) // Open directory successfully
        {
            while ((dir = readdir(d)) != NULL)
            {
                printf("%s\n", dir->d_name);
            }
            closedir(d);
        }
        else // Can not open directory
        {
            printf(PROGRAM_NAME);
            printf(": cannot open directory \'");
            printf("%s\'\n", argv[1]);
        }
    }
    else // Execute in `ls DIR`
    {
        for (int i = 1; i < argc; i++)
        {
            if ((d = opendir(argv[i])) != NULL) // Open directory successfully
            {
                printf("%s:\n", argv[i]);
                while ((dir = readdir(d)) != NULL)
                {
                    printf("%s\n", dir->d_name);
                }
                closedir(d);
                if (i < argc - 1)
                {
                    printf("\n");
                }
            }
            else // Can not open directory
            {
                printf(PROGRAM_NAME);
                printf(": cannot open directory \'");
                printf("%s\'\n", argv[i]);
            }
        }
    }
    return 0;
}