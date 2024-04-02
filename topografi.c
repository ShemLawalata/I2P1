#include <stdio.h>
int main(void)
{
    int in;
    scanf("%d", &in);
    for (int i = 1; i <= in; i++)
    {
        //space
        for (int s = 1; s <= in-i; s++)
        {
            printf(" ");
        }
        //number
        int b = i;
        for (int n = 1; n <= 2*i-1 ; n++)
        {
            if (n<=i)
            {
                printf("%d", n);
            }
            
            else
            {
                b--;
                printf("%d", b);
            }
        }
        printf("\n");
    }
    //reverse in-(2*1)
    for (int i = 1; i <= in-1; i++)
    {
        //space
        for (int s = 1; s <= i; s++)
        {
            printf(" ");
        }
        //angka
        int b = in-i;
        for (int a = 1; a <= (in*2-1)-2*i; a++)
        {
            if (a<=in-i)
            {
                printf("%d", a);
            }
            
            else
            {
                b--;
                printf("%d", b);


            }
        }
        printf("\n");
    }
    
}
            