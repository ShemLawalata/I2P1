#include <stdio.h>
int main(void)
{
    int inp;
    scanf("%d", &inp);
    if (inp%2==0)
    {
        printf("Stop drawing fake diamonds!\n");
       
    }
    
    else if (inp%2!=0)
    {
        for (int i = 1; i <= (inp+1)/2; i++)//batas
        {
        //space
            for (int s = 1; s <= (inp+1)/2-i ; s++)
            {
                printf(" ");
            }
        //star
            for (int b = 1; b <= i*2-1; b++)
            {
                printf("*");
            
            }
            printf("\n");
         }
    
    //low
    for (int i = 1; i <= inp/2; i++)//batas row
    {
        //space
        for (int s = 1; s <= i; s++)
        {
            printf(" ");
        }
        
        for (int b = 1; b <= inp-(2*i); b++)
        {
            printf("*");
        
        }
        printf("\n");
    }
    }
}