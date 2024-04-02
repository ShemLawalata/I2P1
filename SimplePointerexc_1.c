#include <stdio.h>
#include <stdlib.h>
#include "function.h"
int get_sum(int** int_2D_array, int length, int width);

int main() {
    int width = 0, length = 0;
    scanf("%d %d", &length, &width);
    int** int_2D_array = (int**) malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        int_2D_array[i] = (int*) malloc(width * sizeof(int));
    }

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++){
            scanf("%d", &int_2D_array[i][j]);
        }
    }
    printf("%d\n", get_sum(int_2D_array, length, width));

    //FREE
    for (int i = 0; i < length; i++) free(int_2D_array[i]);
    free(int_2D_array);

}

int get_sum(int** int_2D_array, int length, int width)
{
    int total = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            total += int_2D_array[i][j];
        }
        
    }
    return total;
}