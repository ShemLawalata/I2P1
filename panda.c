#include <stdio.h>

char map[1001][1001];
int max, m, n;
void move(int X, int Y, int count);

int main(void)
{
    int X, Y;
    scanf("%d %d", &m, &n);
    max = m * n -1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf(" %c", &map[i][j]);
            if (map[i][j] == 'S')//Assign bisa sekali jalan ga perlu pakai loop lagi//
            {
                X = i;
                Y = j;
            }  
        }
    }
    
    move(X, Y, 0);
    printf("%d\n", max);
    
}

void move(int X, int Y, int count)
{
    if (count == max) return;
    else if (map[X][Y] == 'M')
    {
        max = count;
        return;
    }
    else
    {
        map[X][Y] = '^';
        if (X < m && (map[X + 1][Y] == '.' || map[X + 1][Y] == 'M')) move(X + 1, Y, count + 1);//Down
        if (X > 0 && (map[X - 1][Y] == '.' || map[X - 1][Y] == 'M')) move(X - 1, Y, count + 1);//Up
        if (Y < n && (map[X][Y + 1] == '.' || map[X][Y + 1] == 'M')) move(X, Y + 1, count + 1);//Right
        if (Y > 0 && (map[X][Y - 1] == '.' || map[X][Y - 1] == 'M')) move(X, Y - 1, count + 1);//Left
        map[X][Y] = '.';
        return; //auto return
        
    }
}