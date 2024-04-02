#include <stdio.h>
int a[15];
int count = 0;
int n;
int place(int row, int n);
int valid(int row, int col);


int main()
{
    scanf("%d", &n);
    place(0, n);
    printf("%d", count);
    return 0;
}

int place(int row, int n)
{
    if(row == n) count++;
    else{
        for(int col = 0; col < n; col++){
            if(valid(row, col)){
                a[row] = col;
                place(row+1, n);
            } 
        }
    }
}

int valid(int row, int col){
    for(int i = 0; i < row; i++) if(a[i] == col || a[i] == (col - row + i) || a[i] == (col + row - i)) return 0;
    return 1;
}



