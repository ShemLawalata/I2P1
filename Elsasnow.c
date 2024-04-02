#include <stdio.h>
int row, col, n;
int snow[500][500] = {0};
int mid[8] = {0,1}; //{0, 1, 2, 5, 12, 29, 70, 169}
int cumulative[8] = {0,1}; //[0, 1, 3, 8, 20, 49, 119, 288]
void initialize_size();
int snowflake_size(int n);
void expand(int n, int row, int col);

int main(void)
{
    //Input n or "order"
    scanf("%d", &n);
    initialize_size();
    int size = snowflake_size(n);

    //Print snowflakes (call function)
    expand(n, cumulative[n-1],cumulative[n-1]);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (snow[i][j] == 0) {printf(" ");}
            if (snow[i][j] == 1) {printf("#");}
        }
        printf("\n");
    }
    

}

void expand(int n, int row, int col) //Basiclly tugas kita cuma print middle
{
    //Base case
    if (n == 0) {return;}
    if (n == 1) 
    {
        snow[row][col] = 1;
        return;
    }

         

    if (n > 1)
    {
        for (int i = row; i < row + mid[n] ; i++)
        {
            for (int j = col; j < col + mid[n]; j++)
            {
                snow[i][j] = 1;
            }
        }
        expand (n-1, row - mid[n-1], col - mid[n-1]); //Corner left up
        expand (n-1, row - mid[n-1], col + mid[n]); // Corner right up
        expand (n-1, row + mid[n], col + mid[n]); // corner right down  
        expand (n-1, row + mid[n], col - mid[n-1]); // corner left down  

        if (n > 2)
        {
            expand (n-2, row - mid[n-2], col + mid [n-1]); //mid up
            expand (n-2, row + mid[n-1], col + mid[n]); //mid right
            expand (n-2, row + mid[n], col + mid[n-1]); //mid down
            expand (n-2, row + mid[n-1], col - mid[n-2]);//mid left
        }
        return;
    }


}

void initialize_size() {

    for(int i = 2; i <= 7; i++) {

        mid[i] = 4 * cumulative[i-2] - mid[i-2] + 2;

        cumulative[i] = cumulative[i-1] + mid[i];

    }

}
 
int snowflake_size(int n) {
    return cumulative[n] + cumulative[n - 1];
}