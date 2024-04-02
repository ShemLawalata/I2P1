#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *split(char *str, const char *delim)
{
    char *p = strstr(str, delim);

    if (p == NULL) return NULL;     // delimiter not found

    *p = '\0';
    int n = 0, i = 0;
    while (str[i] != '\0')
    {
        i++;
        n++;
    }
    printf("n:%d|i:%d \n", n, i);            // terminate string after head
    return p + strlen(delim);       // return tail substring
}

int main(void)
{
    char str[] = "goodotmoring!";
    char delim[] = "ot";
    char *tail;

    tail = split(str, delim);

    if (tail) {
        printf("head: '%s'\n", str);
        printf("tail: '%s'\n", tail);
    }

    return 0;
}