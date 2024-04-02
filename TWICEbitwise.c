#include<stdio.h>

int main(void)
{
    int T;
    scanf("%d", &T);
    int start, end;
    while (T--)
    {    
          int i = 0;
        scanf("%d %d", &start, &end);
        while (end != start)
        {
            end >>= 1; 
            start >>= 1;
            i++;
        }
        printf("%d\n", start << i);
    }
    
}