#include<stdio.h>
int main ()
{
   int i,j;
   int a[10][10] = {1};
   i=1;
   while (i<=9)
   {
    j = 1;
     while (j<=9)
     {
        a[i][j]= a[i-1][j-1]+a[i-1][j];
        j++;
     }
        i++;
   }
   i = 1;
   while (i<=9)
   {
    j=1;
    while (j<=9)
    {
        printf("%3d ", a[i][j]);
        j++;
    }
    printf("\n");
    i++;
   }
   return 0;
      
}