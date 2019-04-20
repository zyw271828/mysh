#include <dirent.h>
#include <stdio.h>

#define PROGRAM_NAME "ls"

int main(int argc, char *argv[])
{
    DIR *d;
    struct dirent *dir;

    if (argv[1] == NULL) // Execute in `ls`
    {
        d = opendir(".");
    }
    else // Execute in `ls DIR`
    {
        d = opendir(argv[1]);
    }

    if (d) // Open directory successfully
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
    else // Can not open directory
    {
        printf("Can not open directory %s\n", argv[1]);
    }
    return 0;
}