#include <stdio.h>
int main (void)
{
    int i, j, r;
    scanf("%d", &r);
    
    //upper part
    for ( i = 1; i <= r; i++)
    {
        for (j = 1; j <= (2*r-1); j++)
        {
            if (j >= r-(i-1) && j <= r+(i-1) )
            {
                printf("*");
            }
            else printf(" ");
            
            
        }
        printf("\n");

        // for ( i = 1; i < r; i++)
        // {
        //     for ( j = 1; j < 2*r-3 ; j++)
        //     {
        //         if (j >= 2*r-2-i && j<=2*r-2-i)
        //         {
        //             printf("*");
        //         }
        //         else printf(" ");
        //     }
        //     printf("\n");
        // }
        
    }

    //lower part
    for ( i = r-1; i >= r; i--)
    {
        for (j = 1; j <= (2*r-1); j++)
        {
            if (j >= r-(i-1) && j <= r+(i-1) )
            {
                printf("*");
            }
            else printf(" ");
    
        }
        printf("\n");
    }
}
            