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
                printf("       If no directory operand is given and the HOME environment variable is set to a\n");
                printf("       non-empty value, the cd utility shall behave as if the directory named in the\n");
                printf("       HOME environment variable was specified as the directory operand.\n");
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
                printf("       The meaning of each field is: file permissions, number of links, owner name,\n");
                printf("       owner group, file size, time of last modification, file name.\n");
            }
            else if (strcmp(argv[i], "echo") == 0)
            {
                printf("NAME\n");
                printf("       echo - display a line of text\n\n");
                printf("SYNOPSIS\n");
                printf("       echo [STRING]...\n\n");
                printf("DESCRIPTION\n");
                printf("       Echo the STRING(s) to standard output.\n\n");
                printf("       The following sequences are recognized:\n");
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
                printf("       rm removes each specified file, including directory. But it does not remove\n");
                printf("       non-empty directories.\n");
            }
            else if (strcmp(argv[i], "wc") == 0)
            {
            }
            else if (strcmp(argv[i], "man") == 0)
            {
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