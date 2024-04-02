#include <stdio.h>
char maze[350][350];
int X, Y, M, N;
int a, b;
int U_i[30];
int U_j[30];
int flag = 0;
void Escape (int X, int Y);

int main(void)
{
    int T;
    scanf("%d", &T);
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%c", &maze[i][j]);
            if (maze[i][j] == '$')
            {
                X = i;
                Y = j;
            } 

            else if(maze[i][j] >= 'A' && maze[i][j] <= 'Z') 
            {
                U_i[a++] = i;
                U_j[b++] = j;  
            }
        }
    }
    Escape(X, Y);
    //if (flag == 1) printf("Yes\n");
    //else printf("No\n");
    T--;
    flag = 0;
    a = 0, b = 0;
}
//Backtrack kalau ketemu langsung out, kalau sudah sampai max gada jawaban it is no
// Simpan posisi Uppercase, if escape found lower pindah ke posisi upper
// if map = lower case, kita go ke upper by asci
void Escape(int X, int Y)
{
    if (maze[X][Y] == '&')
    {
        flag = 1;
        return;
    }

    else
    {
        if ((maze[X][Y] >= 97) && (maze[X][Y] <= 122))
        {
            for (int i = 0, j = 0; (i < a) && (j < b); i++, j++)
            {
                if ((maze[X][Y]- 32) == maze[U_i[i]][U_j[j]])
                {
                    maze[X][Y] == '#';
                    Escape(i, j);
                    break;
                } 
            }
            return;     
        }
        else
        {
            maze[X][Y] = '#';
            if ((X > 0 && flag == 0) && (maze[X-1][Y] == '.' || maze[X-1][Y] == '&' ||((maze[X-1][Y] >= 65) && (maze[X-1][Y] <= 90)))) Escape(X-1, Y); //Up
            if ((X < N && flag == 0) && (maze[X+1][Y] == '.' || maze[X+1][Y] == '&' ||((maze[X+1][Y] >= 65) && (maze[X+1][Y] <= 90)))) Escape(X+1, Y); //Down
            if ((Y < M && flag == 0) && (maze[X][Y+1] == '.' || maze[X][Y+1] == '&' ||((maze[X][Y+1] >= 65) && (maze[X][Y+1] <= 90)))) Escape(X, Y+1); //Right
            if ((Y > 0 && flag == 0)&& (maze[X][Y-1] == '.' || maze[X][Y-1] == '&' ||((maze[X][Y-1] >= 65) && (maze[X][Y-] <= 90))))  Escape(X, Y-1); //Left
            maze[X][Y] = '.';
            return;

        }

    }
}