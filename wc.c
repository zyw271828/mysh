#include <stdio.h>
#include <string.h>

#define PROGRAM_NAME "wc"

int lines = 0;
int words = 0;
int bytes = 0;
int tot_lines = 0;
int tot_words = 0;
int tot_bytes = 0;
enum states
{
    WHITESPACE,
    WORD
};
int state = WHITESPACE;

void count(char c);

int main(int argc, char *argv[])
{
    char c;

    if (argv[1] == NULL || strcmp(argv[1], "-") == 0 || strcmp(argv[1], "--") == 0) // Execute in `wc`
    {
        while ((c = getchar()) != EOF)
        {
            count(c);
        }
        printf("%d %d %d\n", lines, words, bytes);
    }
    else // Execute in `wc FILE` or `wc FILE...`
    {
        if (argc == 2) // Execute in `wc FILE`
        {
            FILE *file;
            file = fopen(argv[1], "r");

            if (file)
            {
                while ((c = getc(file)) != EOF)
                {
                    count(c);
                }
                fclose(file);
                printf("%d %d %d %s\n", lines, words, bytes, argv[1]);
            }
            else
            {
                printf(PROGRAM_NAME);
                printf(": cannot open \'");
                printf("%s\'\n", argv[1]);
            }
        }
        else // Execute in `wc FILE...`
        {
            for (int i = 1; i < argc; i++)
            {
                FILE *file;

                file = fopen(argv[i], "r");
                if (file)
                {
                    while ((c = getc(file)) != EOF)
                    {
                        count(c);
                    }
                    fclose(file);
                    if (i != 1)
                    {
                        words++;
                    }
                    printf("%d %d %d %s\n", lines, words, bytes, argv[i]);
                    tot_lines += lines;
                    tot_words += words;
                    tot_bytes += bytes;
                    lines = 0;
                    words = 0;
                    bytes = 0;
                }
                else
                {
                    printf(PROGRAM_NAME);
                    printf(": cannot open \'");
                    printf("%s\'\n", argv[i]);
                }
            }
            printf("%d %d %d %s\n", tot_lines, tot_words, tot_bytes, "total");
        }
    }
    return 0;
}

void count(char c)
{
    bytes++;
    if (c == '\n')
    {
        lines++;
        state = WHITESPACE;
    }
    else if (c == ' ' || c == '\t')
    {
        state = WHITESPACE;
    }
    else
    {
        if (state == WHITESPACE)
        {
            words++;
        }
        state = WORD;
    }
}