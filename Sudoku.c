#include <stdio.h>

int n = 9;
int Sudoku[10][10];
int Check[10];
int position, row, col;
int flag = 0;
int X, Y;
int test = 0;
void place(int row, int n, int col);
int valid(int X, int Y, int position);

int main(void)
{
    //Input 9x9 sudoku board
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &Sudoku[i][j]);
        }

    }
    //Search '0' and check num 1 - 9
    place(0, n, 0);
    if (flag == 0) printf("no solution\n");

}

void place(int row, int n, int col)
{
    //Base case
    if (row == n) 
    {
        flag = 1;
        int i, j;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n - 1; j++) 
            {
                printf("%d ", Sudoku[i][j]);
            }
                printf("%d\n", Sudoku[i][j]);
        }
    }
    
    else
    {
            if (col == n) place(row+1, n, 0); //tambah paramete col = 0;

            else 
            {
                if (Sudoku[row][col] != 0) place(row, n, col + 1);
                else  // kalau bukan '0' tetap pangil function yang lanjut cek col selanjutnya, sampai ujung, row baru & col set 0
                {
                    for (int k = 1; k <= n; k++)
                        {
                            if (valid(row, col, k)) //kalau misalnya valid return 0 itu dia quit for loop k? atau ke iteration selanjutnya?
                                {   Sudoku[row][col]=k;
                                    place (row, n, col +1); //panggil function ke col selanjutnya atau ke row selanjutnya
                                    //Sudoku[row][col]=0; (ini dia kalau gagal set 0 terus)
                                }
                    
                        }
                    Sudoku[row][col]=0; //(iteration habis, sebelum back ke caller dia set 0)
                   
                }       
            }
            //Disini dia AUTO RETURN ingat!!
            //terus balek ke caller yang ada di dalam loop 'k' yg sebelumnya.
        
    }
}

int valid(int X, int Y, int position)
{
    for (int i = 0; i < n; i++)
    {
        if (position == Sudoku[X][i] || position == Sudoku[i][Y]) return 0;
    }

    for (int a = X/3 + (X/3 * 2); a <= (2 + (X/3 * 3)); a++)
    {
        for (int b = Y/3 + (Y/3 * 2); b <= (2 + (Y/3 * 3)); b++)
        {
           if (position == Sudoku[a][b])return 0;
        }
        
    }
           return 1;

}