#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>

#define PROGRAM_NAME "ls"
#define MAX_PATH_LEN 1024

int print_permission(char path[], struct dirent *dir);

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
                print_permission(argv[1], dir);
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
                    print_permission(argv[i], dir);
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

int print_permission(char path[], struct dirent *dir)
{
    char buf[MAX_PATH_LEN];
    struct stat sb;

    if (path != NULL)
    {
        sprintf(buf, "%s/%s", path, dir->d_name);
    }
    else
    {
        sprintf(buf, "%s", dir->d_name);
    }

    if (lstat(buf, &sb) == -1)
    {
        printf("           ");
        return -1;
    }
    else
    {
        printf((S_ISDIR(sb.st_mode)) ? "d" : "-");
        printf((sb.st_mode & S_IRUSR) ? "r" : "-");
        printf((sb.st_mode & S_IWUSR) ? "w" : "-");
        printf((sb.st_mode & S_IXUSR) ? "x" : "-");
        printf((sb.st_mode & S_IRGRP) ? "r" : "-");
        printf((sb.st_mode & S_IWGRP) ? "w" : "-");
        printf((sb.st_mode & S_IXGRP) ? "x" : "-");
        printf((sb.st_mode & S_IROTH) ? "r" : "-");
        printf((sb.st_mode & S_IWOTH) ? "w" : "-");
        printf((sb.st_mode & S_IXOTH) ? "x" : "-");
        printf(" ");
        return 0;
    }
}