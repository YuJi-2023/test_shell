#include <stdio.h>

extern char **environ;
char *_getenv(const char *);

int main()
{
    char *str = _getenv("PATH");
    if (str != NULL)
    {
        printf("PATH=%s\n", str);
    }
    else
    {
        printf("Environment variable not found.\n");
    }

    return 0;
}
