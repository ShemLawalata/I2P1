#include <stdio.h>
//input habis dia cao;
int main(void) {
    int i;
    char s[6] = {-1, -1, -1, -1, -1, -1};
    gets(s);
    for (i = 0; i < 6; i++)
        printf("%d ", s[i]);
    return 0;
}