#include <stdio.h>
char puzzle[100000][3][3];
char change[3][3];
int solution = 0;
int flag, n;
void function(int move, int x, int y, int direction);

int main(){
    int moves, startx, starty;
    scanf("%d %d", &n, &moves);
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                scanf(" %c", &puzzle[i][j][k]);
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf(" %c", &change[i][j]);
            if(change[i][j]=='x'){
                startx = i;
                starty = j;
            }
        }
    }
    function(moves, startx, starty, 0);
    printf("%d\n", solution);
}

void function(int move, int x, int y, int direction){
    for(int i=n-1;i>=0;i--){
        if(change[x][y]!=puzzle[i][x][y])continue;
        flag = 0;
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(puzzle[i][j][k]==change[j][k])flag++;
            }
        }
        if(flag==9){
            solution++;
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    puzzle[i][j][k] = puzzle[n-1][j][k];
                }
            }
            n--;
        }
    }

    if(move>0){
        if(x!=2 && direction != 2){
            change[x][y] = change[x+1][y];
            change[x+1][y] = 'x';
            function(move-1, x+1,y, 1);
            change[x+1][y] = change[x][y];
            change[x][y] = 'x';
        }
        if(x!=0 && direction != 1){
            change[x][y] = change[x-1][y];
            change[x-1][y] = 'x';
            function(move-1, x-1,y, 2);
            change[x-1][y] = change[x][y];
            change[x][y] = 'x';
        }
        if(y!=2 && direction != 4){
            change[x][y] = change[x][y+1];
            change[x][y+1] = 'x';
            function(move-1, x,y+1, 3);
            change[x][y+1] = change[x][y];
            change[x][y] = 'x';
        }
        if(y!=0 && direction != 3){
            change[x][y] = change[x][y-1];
            change[x][y-1] = 'x';
            function(move-1, x,y-1, 4);
            change[x][y-1] = change[x][y];
            change[x][y] = 'x';
        }
    }
}