#include <stdio.h>
int main(void)
{
    int const row = 1000;
    int const columns = 2000;
    int x;
    int arr [1000][2000] = {0};
    scanf("%d", &x);

    for (int i = 1; i <= x; i++)
    {
        int a = i;
        int j = x;
        int b = 0;
        while (a>=1)
        {
            arr[i][j-b] = a;
            arr[i][j+b] = a;
            a--;
            b++;
        }
         
    }
    int i = 1;
    while (i<=x)
    {
        int j = 1;
        while (j<=2*x-1)
        {
            if (arr[i][j]==0)
            {
                if (j<=i+x-1) printf(" ");
            }
            
            else printf("%d", arr[i][j]);
            j++;

        }
        printf("\n");
        i++;
    }
    
    
    
    
}