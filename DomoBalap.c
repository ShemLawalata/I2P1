#include <stdio.h>
int pace = 0;
int temp = 0;
//int max;
int N, M, Q;
void Race(int X, int Y, int max, int count, char Circuit[][25]);
int main(void)
{
    
    char Circuit[25][25];
    int Result[5];
    scanf("%d %d %d", &N, &M, &Q);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf(" %c", &Circuit[i][j]);
        }
        
    }
    int max;
    max = N * M - 1;
    temp = max;

    //For Domo
    int a, b;
    int record = max;
    scanf("%d %d", &a, &b);
    Race(a, b, max, 0, Circuit);
    Result[0] = temp;
    pace = temp;
    //printf("pace %d", pace);
    temp = max;
    //For Competitor
    for (int i = 1; i <= Q; i++)
    {
        
        int x, y;
        scanf ("%d %d", &x, &y);
        Race(x, y, max, 0, Circuit);
        Result[i] = temp;
        if (temp < record) record = temp;
        temp = max;
    }
    //Result
    int i;
    for ( i = 0; i <= Q-1; i++) printf("%d ", Result[i]);
    printf("%d", Result[i]);
    printf("\n%d\n", record - pace);
}

void Race(int X, int Y, int max, int count, char Circuit[][25])
{

    if(Circuit[X][Y] == '-')
    {
        if (count < max)
        {
    
            temp = count;
            max = count;

        }
        return;
    }
    //Recursive
    else
    {
        //printf("tes");
        Circuit[X][Y] = 'X';
        if (X > 0 && (Circuit[X-1][Y] == '.' || Circuit[X-1][Y] == '-')) Race(X-1, Y, temp, count+1, Circuit);//Up
        if (X < N-1 && (Circuit[X+1][Y] == '.' || Circuit[X+1][Y] == '-')) Race(X+1, Y, temp, count+1, Circuit);//Down
        if (Y < M-1 && (Circuit[X][Y+1] == '.' || Circuit[X][Y+1] == '-')) Race(X, Y+1, temp, count+1, Circuit);//Right
        if (Y > 0 && (Circuit[X][Y-1] == '.' || Circuit[X][Y-1] == '-')) Race(X, Y-1, temp, count+1, Circuit);//Left
        Circuit[X][Y] = '.';
    }
}