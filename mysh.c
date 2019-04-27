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

int call_cmd(char *cmd_argv[], int background);

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
        // Convert input to argv array and store it in cmd
        // cmdp are pointers to each argv
        if ((fgets(input, (MAX_ARGV_NUM) * (MAX_ARGV_LEN), stdin)) == NULL)
        {
            printf("exit\n");
            exit(0);
        }
        if (strcmp(input, "\n") == 0)
        {
            continue;
        }

        cmds = strtok(input, " \n");
        int cmd_argc = 0;

        for (cmd_argc = 0; cmds != NULL; cmd_argc++)
        {
            strcpy(cmd[cmd_argc], cmds);
            (*cmdp)[cmd_argc] = cmd[cmd_argc];
            (*cmdp)[cmd_argc + 1] = NULL; // Must be terminated by a null pointer
            cmds = strtok(NULL, " \n");
        }

        int background = 0;

        if (strcmp(cmd[cmd_argc - 1], "&") == 0)
        {
            background = 1;
            (*cmdp)[cmd_argc - 1] = NULL;
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
            call_cmd(cmdp[0], background);
        }
        else if (strcmp(cmd[0], "echo") == 0)
        {
            (*cmdp)[0] = MYSH "echo";
            call_cmd(cmdp[0], background);
        }
        else if (strcmp(cmd[0], "cat") == 0)
        {
            (*cmdp)[0] = MYSH "cat";
            call_cmd(cmdp[0], background);
        }
        else if (strcmp(cmd[0], "mkdir") == 0)
        {
            (*cmdp)[0] = MYSH "mkdir";
            call_cmd(cmdp[0], background);
        }
        else if (strcmp(cmd[0], "rm") == 0)
        {
            (*cmdp)[0] = MYSH "rm";
            call_cmd(cmdp[0], background);
        }
        else if (strcmp(cmd[0], "wc") == 0)
        {
            (*cmdp)[0] = MYSH "wc";
            call_cmd(cmdp[0], background);
        }
        else if (strcmp(cmd[0], "man") == 0)
        {
            (*cmdp)[0] = MYSH "man";
            call_cmd(cmdp[0], background);
        }
        else if (strcmp(cmd[0], "clear") == 0)
        {
            printf("\033[H\033[2J\033[3J");
        }
        else if (strcmp(cmd[0], "sleep") == 0)
        {
            (*cmdp)[0] = MYSH "sleep";
            call_cmd(cmdp[0], background);
        }
        else if (strcmp(cmd[0], "exit") == 0)
        {
            printf("exit\n");
            exit(0);
        }
        else
        {
            printf("%s: command not found\n", cmd[0]);
            printf("\nYou can try the following commands:\n");
            printf("       ls, echo, cat, mkdir, rm, cd, pwd, wc, clear, sleep\n");
            printf("\nOr use `man [CMD]...` to view the command manual.\n");
            printf("       For example: `man ls`\n");
        }

        // Clean up the argv array
        for (int i = 0; i < cmd_argc; i++)
        {
            cmd[i][0] = '\0';
        }
    }
    return 0;
}

int call_cmd(char *cmd_argv[], int background)
{
    pid_t pid = -1;

    if (background) // Run in background
    {
        if ((pid = fork()) == -1)
        {
            printf("Error, failed to fork()\n");
        }
        else if (pid > 0) // Parent process
        {
            int status;
            printf("[Background] %d\n", pid);
            waitpid(-1, &status, WNOHANG | WUNTRACED);
        }
        else // Child process
        {
            setsid();
            execv(cmd_argv[0], cmd_argv);
            _exit(EXIT_FAILURE);
        }
    }
    else // Run in foreground
    {
        if ((pid = fork()) == -1)
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
    return 0;
}