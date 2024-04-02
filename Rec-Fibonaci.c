#include <stdio.h>

int Gib (int, int, int);
int main(void)
{
    //Input
    int G0, G1;
    int n;
    scanf("%d %d %d", &G0, &G1, &n);
    printf("%d", Gib(G0, G1, n));
}

int Gib (int G0, int G1, int n) // So dia bakalan lihat input melalui Base case kita n=0 dan n=1;
{
      if (n == 0) return G0;
      else if (n == 1) return G1;
      return Gib(G0, G1, (n - 2)) - Gib(G0, G1, (n - 1));//Bercabang manggil func Gib sampai return valuenya semua
}