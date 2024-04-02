#include <stdio.h>
#include <stdlib.h>
#define COLS 5
int main(void)
{
    int u, j, rows = 10;
    int *a; // a is a pointer to an integer
    int (*b) [COLS]; // b isa pointer to A 1-D ARRAY of COLS ints (isinya sebanyak COls)

    a = (int *) malloc(rows * sizeof(int)); //berarti dia jadi 1 D array yah

    for (int i = 0; i < rows; i++) a[i] = i;

    b = (int(*) [COLS]) malloc(rows * COLS * sizeof(int));

    // printf("%lu\n", sizeof(b));
    // printf("%lu\n", sizeof(a));
    for (int i = 0; i <  rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%3d ", (b[i][j] = i*COLS+j));
        }
        printf("\n");
    }
    free(a);
    free(b);
    return 0;

    //calloc(100, sizeof(int)); MAu create memory space sebanyak 100 int dan assigned with 0
//The malloc() function reserves a block of memory of the specified number of bytes. And, it returns a pointer of void which can be casted into pointers of any form. 
}