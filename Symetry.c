#include<stdio.h>
#include <string.h>
int count = 0;
char S[45];
int valid(int start, int end);
int Symetry(int n, int start);

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T>0)
    {
        scanf("%s", S);
        int n = strlen(S);
        //Count all caharacter combination
        Symetry(n, 0);
        printf("%d\n", count);
        T--;
        count = 0;
    }
    
}

int Symetry(int n, int start)
{
    //Base case
    if (start == n)
    {
        count++;
        return 1;
    }

    //Recursive step
    else
    {
        for (int j = start; j < n; j++)
        {
            if (valid(start, j)) Symetry(n, j+1);
        }
        
    }
    
}

int valid(int start, int end)
{
        if (start == end) return 1;
        for (int x = 0; x <= end - start; x++)// pas a|aa kena! kecil n atau n - start jg bisa
        {
            if (S[start + x] != S[end - x]) return 0;
        }
        return 1;
}