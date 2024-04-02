#include <stdio.h>
#include <math.h>
int main ()
{
int x,y,z;
while(scanf("%d", &x)!=EOF){
    y=x;
    z=x;
    int count = 0;
    while (x!=0)
    {
        count++;
        x = x/10;
    }
    int sum=0;
    for ( int i = 0; i < count; i++)
    {
        sum += pow(y%10, count);
        y=y/10;
    }
    if (sum==z)
    {
        printf("Yes it is.\n");
    }
    if (sum!=z)
    {
        printf("No it is not.\n");
    }

}
}