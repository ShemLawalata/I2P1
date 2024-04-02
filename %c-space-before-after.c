#include <stdio.h>
char maze[350][350];
int X, Y, M, N;
int a = 0, b = 0;
int U_i[30];
int U_j[30];
int flag = 0;
void Escape (int X, int Y);

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T > 0)
    {
        
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                scanf(" %c", &maze[i][j]);
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
        /*
        for(int f=0;f<N;f++){
            for(int g=0;g<M;g++){
                printf("%c ",maze[f][g]);
            }
            printf("\n");
        }
        */
        if (flag == 1) printf("Yes\n");
        else printf("No\n");
        // for (int i = 0, j = 0; (i < a) && (j < b); i++, j++)
        //     {
        //         printf("(%c)", maze[U_i[i]][U_j[j]]);
        //         printf("\n[%d], [%d]", U_i[i], U_j[j]);
        //     }
        // for (int i = 0; i < N; i++)
        // {
        //     for (int j = 0; j < M; j++)
        //     {
        //         printf("%c", maze[i][j]);

        //     }
        //     printf("\n");
        // }
        T--;
        flag = 0;
        a = 0, b = 0;
    }
    
}

void Escape(int X, int Y)
{
 if(flag==0){  // printf("x:%d y:%d (%c)\n",X,Y,maze[X][Y]);
    if (maze[X][Y] == '&')
    {
        flag = 1;
        return;
    }

    else
    {

        if ((maze[X][Y] >= 'a') && (maze[X][Y] <= 'z'))
        {
            for (int i = 0, j = 0; (i < a) && (j < b); i++, j++)
            {
                //printf("char:%c tes x:%d y:%d\n",maze[X][Y],U_i[i],U_j[j]);
                if ((maze[X][Y]- 32) == maze[U_i[i]][U_j[j]])
                {
                    maze[X][Y] = '#';
                    //printf("[%c]", maze[X][Y]);
                    Escape(U_i[i], U_j[j]);
                    break;
                } 
                continue;
            }
            return;     
        }
        else
        {
            maze[X][Y] = '#';
            if ((X > 0 && flag == 0) && (maze[X-1][Y] == '.' || maze[X-1][Y] == '&' ||((maze[X-1][Y] >= 'A') && (maze[X-1][Y] <= 'z')))) {Escape(X-1, Y);} //Up
            if ((X < N-1 && flag == 0) && (maze[X+1][Y] == '.' || maze[X+1][Y] == '&' ||((maze[X+1][Y] >= 'A') && (maze[X+1][Y] <= 'z')))) {Escape(X+1, Y);} //Down
            if ((Y < M-1 && flag == 0) && (maze[X][Y+1] == '.' || maze[X][Y+1] == '&' ||((maze[X][Y+1] >= 'A') && (maze[X][Y+1] <= 'z')))) {Escape(X, Y+1);} //Right
            if ((Y > 0 && flag == 0)&& (maze[X][Y-1] == '.' || maze[X][Y-1] == '&' ||((maze[X][Y-1] >= 'A') && (maze[X][Y-1] <= 'z'))))  {Escape(X, Y-1);} //Left
            return;

        }

    }
 }
 return;
}