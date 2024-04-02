#include <stdio.h>
#include <stdlib.h>
#include "function.h"
void array_exchanger(int* array_a, int* array_b, int length); //So it's like kita set size of pointer bisa jadi array dong

int main() {
    int length = 0;
    scanf("%d", &length);

    int *array_a, *array_b;

    array_a = (int*) malloc(length * sizeof(int));
    array_b = (int*) malloc(length * sizeof(int));

    for (int i = 0; i < length; i++) {
        scanf("%d", &array_a[i]);
    }

    for (int i = 0; i < length; i++) {
        scanf("%d", &array_b[i]);
    }

    array_exchanger(array_a, array_b, length);

    printf("%d", array_a[0]);
    for (int i = 1; i < length; i++) {
        printf(" %d", array_a[i]);
    }

    printf("\n");

    printf("%d", array_b[0]);
    for (int i = 1; i < length; i++) {
        printf(" %d", array_b[i]);
    }
    
    //FREE
    free(array_a);
    free(array_b);
}

void array_exchanger(int* array_a, int* array_b, int length)
{
   int *swap_a = array_a, *swap_b = array_b;
    int temp = 0;
   for (int i = 0; i < length; i++)
   {
        temp = *(swap_a+i);             
        *(swap_a+i) = *(swap_b+i);
        *(swap_b+i) = temp;

   }
return;
}

// temp = *(swap_a+i);
// *(swap_a+i) = *(swap_b+i);
// *(swap_b+i) = temp;
