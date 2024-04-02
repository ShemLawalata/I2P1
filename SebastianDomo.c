#include <stdio.h>
#include <ctype.h>

int pace = 0;
int temp = 0;
int N, M, Q;
void Race(int X, int Y, int result[5], int count, char Circuit[][25]);
int main(void)
{
    
    char Circuit[25][25];
    int result[5] = {0}, nrow, ncol, record = 0;
    scanf("%d %d %d", &N, &M, &Q);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf(" %c", &Circuit[i][j]);
            if (Circuit[i][j] == '-') {
                nrow = i;
                ncol = j;
            }
        }
        
    }
    int max;
    max = N * M - 1;
    //For Competitor
    for (int i = 1; i <= Q+1; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        Circuit[x][y] = '0' + i; 
        //printf("[%d %d %c]\n", x, y, Circuit[x][y]);
    }
    Race( nrow, ncol, result, 0, Circuit);
    //Result
    printf("%d", result[1]);
    for (int i = 2; i <= Q + 1; i++) {
        printf(" %d", result[i]);
        if (result[i] < record || !record)  
        {
            record = result[i];
        }
    }
    printf("\n%d\n", record - result[1]);
}

void Race(int X, int Y, int result[5], int count, char Circuit[][25])
{
    //printf("[%d %d %c]\n",X,Y, Circuit[X][Y]);
    //Basis step
   // printf("temp [%d] max (%d)\n", count, max);
    //if (temp == max) return;
    char tempc;
    tempc = Circuit[X][Y];
    if(tempc >= '0' && tempc <= '9')
    {   int index = tempc - '0';
        //printf("%d %d %d\n", X, Y, index);
        if (result[index] > count || !result[index])  
        {
            result[index] = count;
        }
    }
    //Recursive
        //printf("tes");
        Circuit[X][Y] = 'X';
        if (X > 0 && (Circuit[X-1][Y] != 'X')) {Race(X-1, Y, result, count+1, Circuit);}//Up
        if (X < N-1 && (Circuit[X+1][Y] != 'X')) {Race(X+1, Y, result, count+1, Circuit);}//Down
        if (Y < M-1 && (Circuit[X][Y+1] != 'X')) {Race(X, Y+1, result, count+1, Circuit);}//Right
        if (Y > 0 && (Circuit[X][Y-1] != 'X')) {Race(X, Y-1, result, count+1, Circuit);}//Left
        Circuit[X][Y] = tempc;
}