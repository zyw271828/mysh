#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PROGRAM_NAME "mysh"
#define MYSH "/path/to/mysh/"
#define MAX_ARGV_NUM 100
#define MAX_ARGV_LEN 1000
#define MAX_PATH_LEN 1024

int call_cmd(char *cmd_argv[]);

int main(int argc, char *argv[])
{
    char input[(MAX_ARGV_NUM) * (MAX_ARGV_LEN)];
    char *cmds;
    char cmd[MAX_ARGV_NUM][MAX_ARGV_LEN];
    char *cmdp[MAX_ARGV_NUM][MAX_ARGV_LEN];

    chdir(getenv("HOME"));

    while (1)
    {
        // Print shell prompt
        char cwd[MAX_PATH_LEN];
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
        // Convert input to argv array and store it in cmd
        // cmdp are pointers to each argv
        fgets(input, (MAX_ARGV_NUM) * (MAX_ARGV_LEN), stdin);
        cmds = strtok(input, " \n");
        int cmd_argc = 0;

        for (cmd_argc = 0; cmds != NULL; cmd_argc++)
        {
            strcpy(cmd[cmd_argc], cmds);
            (*cmdp)[cmd_argc] = cmd[cmd_argc];
            (*cmdp)[cmd_argc + 1] = NULL; // Must be terminated by a null pointer
            cmds = strtok(NULL, " \n");
        }

        // Find the command to be executed
        if (strcmp(cmd[0], "cd") == 0)
        {
            if (cmd[1] == NULL || cmd[1][0] == '\0' || strcmp(cmd[1], "~") == 0) // Execute in `cd` or `cd ~`
            {
                chdir(getenv("HOME"));
            }
            else // Execute in `cd DIR`
            {
                if (chdir(cmd[1]) != 0)
                {
                    printf("cd");
                    printf(": cannot change directory to \'");
                    printf("%s\'\n", cmd[1]);
                }
            }
        }
        else if (strcmp(cmd[0], "pwd") == 0)
        {
            printf("%s\n", cwd);
        }
        else if (strcmp(cmd[0], "ls") == 0)
        {
            (*cmdp)[0] = MYSH "ls";
            call_cmd(cmdp[0]);
        }
        else if (strcmp(cmd[0], "echo") == 0)
        {
            (*cmdp)[0] = MYSH "echo";
            call_cmd(cmdp[0]);
        }
        else if (strcmp(cmd[0], "cat") == 0)
        {
            (*cmdp)[0] = MYSH "cat";
            call_cmd(cmdp[0]);
        }
        else if (strcmp(cmd[0], "mkdir") == 0)
        {
            (*cmdp)[0] = MYSH "mkdir";
            call_cmd(cmdp[0]);
        }
        else if (strcmp(cmd[0], "rm") == 0)
        {
            (*cmdp)[0] = MYSH "rm";
            call_cmd(cmdp[0]);
        }
        else if (strcmp(cmd[0], "cd") == 0)
        {
            (*cmdp)[0] = MYSH "cd";
            call_cmd(cmdp[0]);
        }
        else if (strcmp(cmd[0], "wc") == 0)
        {
            (*cmdp)[0] = MYSH "wc";
            call_cmd(cmdp[0]);
        }
        else
        {
            printf("%s: command not found\n", cmd[0]);
        }

        // Clean up the argv array
        for (int i = 0; i < cmd_argc; i++)
        {
            cmd[i][0] = '\0';
        }
    }
    return 0;
}

int call_cmd(char *cmd_argv[])
{
    pid_t parent = getpid();
    pid_t pid = fork();

    if (pid == -1)
    {
        printf("Error, failed to fork()\n");
    }
    else if (pid > 0) // Parent process
    {
        int status;
        waitpid(pid, &status, 0);
    }
    else // Child process
    {
        execv(cmd_argv[0], cmd_argv);
        _exit(EXIT_FAILURE);
    }
}