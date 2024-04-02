#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    int N, K, count = 0, *array, *idx;
    scanf("%d %d", &N, &K);
    //Set dynamic array
    array = (int*) malloc(sizeof(int)* (N+1)); //FREE
    idx = (int*) malloc(sizeof(int)*(N+1)); //FREE
    memset(idx, -1, sizeof(int)*(N+1));

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &array[i]);
    }
    
    //Co kang
    int last = 0, first = 0, j;

    for (int i = 0; i <= N-K; i++) //intinya dalah jangan dua kali kerja jadi yaa muali dengan idx yang tepat
    {
        for ( j = last; j < i+K; j++)
        {
            if(idx[array[j]] < i) idx[array[j]] = j;
            else
            {
                first = idx[array[j]];
                last = j;
                break;
            }
        }
        if(j == i+K)
        {
            count++;
            last = j;
        }
        else i = first; //kan habis iini iterate
    }
    printf("%d\n", count);
    free(array);
    free(idx);
}






















// #include <stdio.h>
// #include <stdlib.h>

// int main (void)
// {
//     int N, K, count = 0,*array;
//     scanf("%d %d", &N, &K);
//     int idx[K+1];

//     //Set the Dynamic Array
//     array = (int*)malloc(N*sizeof(int)+1);
//     for (int i = 0; i < N; i++)
//     {
//         scanf("%d", &array[i]);
//     }
   
//     //Co Kang
//     int awal, last, occur, temp, in; //occur brp kali berulang

//     for (int i = 0; i <= (N-K); )
//     {
//         awal = i;
//         in = 0;
//         occur = 0;
//         for (int j = awal+1; ((awal < (i+K-1))&& (j <i+K))  ; j++)//hanya cek ada yang sama apa ngga
//         {  
//             printf("arr aw[%d] = %d ", awal, array[awal]);
//             printf("arr j[%d] = %d \n", j, array[j]);
//             // printf("%d\n", count);
//             // printf("awal 1: %d \n", awal);
//              if(array[j] == array[awal]) //Kalau sama set and break
//                 {
//                     last = i; // kalau cmn 2 yang sama
//                     occur++;
//                     for (int a = j+1; a < (i+K); a++)
//                     {
//                         if (array[a] == array[awal]) 
//                         {
//                 //printf("ahayyy\n");
//                             occur++;
//                             if(a <(i+K-1)) idx[in++] = a;
//                             printf("%d ", idx[in-1]);
//                         }

//                     // for (int i = 0; i < in; i++)
//                     // {
//                     //     printf("%d ", idx[i]);
//                     // }
//                     }
//                     printf("occur %d\n", occur);
//                     if(occur > 1) i = idx[in-2]+1;
//                     else if(occur == 1)i = last+1;
//                     break;
//                 }

//              //Kalau lolos dan ga sama
//              else if(j == (i+K-1)) awal += 1;
//             //  printf("akhir_:%d \n", awal);
//             //  printf("j : %d\n", j);

//         }
//         //printf("occur %d\n", occur);
//         if(occur == 0)
//         {
//             count++;
//             i++;
//         }
//                     printf("count %d\n", count);
//                     printf("i: %d\n", i);
//     }
    
//     printf("%d\n", count);
//     free(array);
// }
       