#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PROGRAM_NAME "sleep"

int main(int argc, char *argv[])
{
    int invalid = 0;

    if (argv[1] == NULL) // Execute in `sleep`
    {
        sleep(0);
    }
    else // Execute in `sleep NUMBER`
    {
        for (int i = 1; i < argc; i++)
        {
            errno = 0;
            char *temp;
            long int time = strtol(argv[i], &temp, 10);

            if (temp == argv[i] || *temp != '\0' ||
                ((time == LONG_MIN || time == LONG_MAX) && errno == ERANGE))
            {
                invalid = 1;
                printf(PROGRAM_NAME);
                printf(": invalid time interval '%s'\n", argv[i]);
            }
        }
        if (invalid == 1)
        {
            return 1;
        }

        for (int i = 1; i < argc; i++)
        {
            sleep((int)strtol(argv[i], (char **)NULL, 10));
        }
    }
    return 0;
}