#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

#define PROGRAM_NAME "ls"
#define MAX_PATH_LEN 1024

int print_file_status(char path[], struct dirent *dir);

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
                print_file_status(argv[1], dir);
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
                    print_file_status(argv[i], dir);
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

int print_file_status(char path[], struct dirent *dir)
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
        for (int i = 0; i < (11 + 5 + 11 + 11 + 11 + 14); i++)
        {
            putchar(' ');
        }
        return -1;
    }
    else
    {
        // Print permissions
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

        // Print number of links
        printf("%4ld ", sb.st_nlink);

        // Print owner name
        struct passwd *pw = getpwuid(sb.st_uid);
        printf("%10s ", pw->pw_name);

        // Print owner group
        struct group *gr = getgrgid(sb.st_gid);
        printf("%10s ", gr->gr_name);

        // Print file size
        printf("%10ld ", sb.st_size);

        // Print time of last modification
        struct tm lt;
        localtime_r(&sb.st_mtime, &lt);
        char timebuf[80];
        strftime(timebuf, sizeof(timebuf), "%b  %d %H:%M", &lt);
        printf("%s ", timebuf);
        return 0;
    }
}