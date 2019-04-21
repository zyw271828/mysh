#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PROGRAM_NAME "mysh"

int main(int argc, char *argv[])
{
    char input[1000];
    char *cmds;
    char *cmd[100][1000];

    chdir(getenv("HOME"));

    while (1)
    {
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));
        if (strcmp(cwd, getenv("HOME")) == 0)
        {
            printf("~");
        }
        else
        {
            // TODO: Replace $HOME with '~'
            printf("%s", cwd);
        }
        printf("$ ");

        // TODO: Auto-completion through tab by using getchar()
        // FIXME: Infinite loop when Ctrl-D is pressed
        fgets(input, 1000, stdin);
        cmds = strtok(input, " \n");

        for (int i = 0; cmds != NULL; i++)
        {
            (*cmd)[i] = cmds;
            (*cmd)[i + 1] = NULL;
            cmds = strtok(NULL, " \n");
        }

        if (strcmp((*cmd)[0], "cd") == 0)
        {
            if ((*cmd)[1] == NULL) // Execute in `cd`
            {
                chdir(getenv("HOME"));
            }
            else // Execute in `cd DIR`
            {
                if (chdir((*cmd)[1]) != 0)
                {
                    printf("cd");
                    printf(": cannot change directory to \'");
                    printf("%s\'\n", (*cmd)[1]);
                }
            }
        }
        else if (strcmp((*cmd)[0], "pwd") == 0)
        {
            printf("%s\n", cwd);
        }
    }
    return 0;
}