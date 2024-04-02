#include <stdio.h>

int main(void)
{
    //Input
    int G[20005];
    int n;
    scanf("%d %d %d", &G[0], &G[1], &n);
    //Process //use loop buat rumusnya
    for (int i = 0; i <= n-2; i++)
    {
        G[i+2] = G[i] - G[i+1];
    }
    printf("%d\n", G[n]);
}

// #include <stdio.h>

// int Fib (int);
// int main(void)
// {
//     //Input
//     int F;
//     int n;
//     scanf("%d", &n);
//     printf("%d", Fib(n));
// }

// int Fib (int n) // So dia bakalan lihat input melalui Base case kita n=0 dan n=1;
// {
//     if (n == 0) return 0; 
//     else if (n == 1) return 1;
//     return Fib (n - 1) + Fib (n - 2);  
// }