#include <stdio.h>
#include <stdlib.h>
void array2d_sort(int row, int col, long long arr[][500]);
long long arr[500][500] = {};

int main(void){

    int row, col;
    scanf("%d%d", &row, &col);

    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            scanf("%lld", &arr[i][j]);

    array2d_sort(row, col, arr);

    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            printf("%lld%c", arr[i][j], (j==col-1) ? '\n' : ' ');

    return 0;
}

void array2d_sort(int row, int col, long long arr[][500])
{
    //Insertion sort
    long long int temp;
    //Initial point 
    for ( int i = row - 1, j = 0; (i >= 0) && (j < col);)
    {
        //Check the diagonal
        int x, y;
        for (int a = i + 1, b = j + 1; (a < row) && (b < col) ; a++, b++)//Diagonal turun - Temp
        {
            temp = arr[a][b];
           for ( x = a-1, y = b-1; (x >= 0) && (y >= 0); x--, y--)//Diagonal naik
           {
            if (arr[x][y] > temp) 
            {
                arr[x+1][y+1] = arr[x][y];
                arr[x][y] = temp;
            }
            else if (arr[x][y] == temp) arr[x+1][y+1] = temp;
            else arr[x][y] = arr[x][y];
           }
           
             
        }
        
        if (i > 0) i--;
        else j++;
        
    }

}
