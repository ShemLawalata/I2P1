// //pakai malloc int utk array, sama inside malloc +1
// //Binary OR
// #include <stdio.h>
// #include <stdlib.h> //pakai bitwise saat kau scanning, anjay mabar var <<= 1 baru var += 1 or 0;

// int main(void)
// {
//     int N, K, Pivot = 0, count = 0;
//     scanf("%d %d", &N, &K);
//     int *array = (int*)calloc(N, sizeof(int));
//     int A = K;
//     //Tentuin patokan
//     while (A--)
//     {
//         Pivot <<= 1;
//         Pivot += 1;
//     }
    
//     int binary;
//     //Binary to Decimal store in array
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < K; j++)
//         {
//             array[i] <<= 1;
//             scanf("%d", &binary);
//             array[i] += binary;
//         }
//     }

//     //Debug
//     // for (int i = 0; i < N; i++)
//     // {
//     //     printf("%d ",array[i]);
//     // }
    
//     //Co kang //Bisa pakai kurang" tapi kalau sama" dengan pivot nilanya gamau
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = i+1; j < N; j++)
//         {
//             if((array[i] | array[j]) == Pivot) count++; 
//         }
        
//     }

//     printf("%d\n", count);
//      free(array);
// }

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, K, Pivot = 0, binary = 0, A, count = 0;
    scanf("%d %d", &N, &K);
    A = K;
    int *array = calloc((N+1), sizeof(int)); //FREE
    //Set Pivot
    while (A--)
    {
        Pivot <<= 1;
        Pivot += 1;
    }
    
    //Set to binary
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            array[i] <<= 1;
            scanf("%d", &binary);
            array[i] += binary;
        }
        
    }
    // Co kang
    for (int i = 0; i < N; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            if ((array[i] | array[j]) == Pivot) count++;
        }
        
    }
    printf("%d\n", count);
    free(array);
}

