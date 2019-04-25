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
                printf("NAME\n");
                printf("       cd - change the working directory\n\n");
                printf("SYNOPSIS\n");
                printf("       cd [directory]\n\n");
                printf("DESCRIPTION\n");
                printf("       The cd command can change the current working directory.\n\n");
                printf("       If no directory operand is given and the HOME environment variable is set\n");
                printf("       to a non-empty value, the cd utility shall behave as if the directory\n");
                printf("       named in the HOME environment variable was specified as the directory\n");
                printf("       operand.\n");
            }
            else if (strcmp(argv[i], "pwd") == 0)
            {
                printf("NAME\n");
                printf("       pwd - print name of current/working directory\n\n");
                printf("SYNOPSIS\n");
                printf("       pwd\n\n");
                printf("DESCRIPTION\n");
                printf("       Print the full filename of the current working directory.\n");
            }
            else if (strcmp(argv[i], "ls") == 0)
            {
                printf("NAME\n");
                printf("       ls - list directory contents\n\n");
                printf("SYNOPSIS\n");
                printf("       ls [directory]\n\n");
                printf("DESCRIPTION\n");
                printf("       List information about the FILEs (the current directory by default).\n\n");
                printf("       The meaning of each field is: file permissions, number of links, owner\n");
                printf("       name, owner group, file size, time of last modification, file name.\n");
            }
            else if (strcmp(argv[i], "echo") == 0)
            {
                printf("NAME\n");
                printf("       echo - display a line of text\n\n");
                printf("SYNOPSIS\n");
                printf("       echo [STRING]...\n\n");
                printf("DESCRIPTION\n");
                printf("       Echo the STRING(s) to standard output.\n\n");
                printf("       The following sequences are recognized:\n\n");
                printf("       \\\\     backslash\n");
                printf("       \\a     alert (BEL)\n");
                printf("       \\b     backspace\n");
                printf("       \\c     produce no further output\n");
                printf("       \\e     escape\n");
                printf("       \\f     form feed\n");
                printf("       \\n     new line\n");
                printf("       \\r     carriage return\n");
                printf("       \\t     horizontal tab\n");
                printf("       \\v     vertical tab\n");
            }
            else if (strcmp(argv[i], "cat") == 0)
            {
                printf("NAME\n");
                printf("       cat - concatenate files and print on the standard output\n\n");
                printf("SYNOPSIS\n");
                printf("       cat [FILE]...\n\n");
                printf("DESCRIPTION\n");
                printf("       Concatenate FILE(s) to standard output.\n\n");
                printf("       With no FILE, or when FILE is -, read standard input.\n");
            }
            else if (strcmp(argv[i], "mkdir") == 0)
            {
                printf("NAME\n");
                printf("       mkdir - make directories\n\n");
                printf("SYNOPSIS\n");
                printf("       mkdir DIRECTORY...\n\n");
                printf("DESCRIPTION\n");
                printf("       Create the DIRECTORY(ies), if they do not already exist.\n");
            }
            else if (strcmp(argv[i], "rm") == 0)
            {
                printf("NAME\n");
                printf("       rm - remove files or directories\n\n");
                printf("SYNOPSIS\n");
                printf("       rm [FILE]...\n\n");
                printf("DESCRIPTION\n");
                printf("       rm removes each specified file, including directory. But it does not\n");
                printf("       remove non-empty directories.\n");
            }
            else if (strcmp(argv[i], "wc") == 0)
            {
                printf("NAME\n");
                printf("       wc - print newline, word, and byte counts for each file\n\n");
                printf("SYNOPSIS\n");
                printf("       wc [FILE]...\n\n");
                printf("DESCRIPTION\n");
                printf("       Print newline, word, and byte counts for each FILE, and a total line if\n");
                printf("       more than one FILE is specified. A word is a non-zero-length sequence\n");
                printf("       of characters delimited by white space.\n\n");
                printf("       With no FILE, or when FILE is -, read standard input.\n");
            }
            else if (strcmp(argv[i], "man") == 0)
            {
                printf("NAME\n");
                printf("       man - view reference manuals for commands\n\n");
                printf("SYNOPSIS\n");
                printf("       man [CMD]...\n\n");
                printf("DESCRIPTION\n");
                printf("       For each specified command, man prints its reference manual.\n");
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