#include<stdio.h>
#include <stdlib.h>
#include "function.h"
int size;

void Swap(int*, int*);

void Replace(int*, int*);

void Switch(int**, int**);

void PrintArrays(int *A, int *B, int size);

int main(){
    char str[10];
    int size;    scanf("%d", &size);

    int *A = (int*)malloc(sizeof(int)*size);//Malloc return adress of memory block OK
    int *B = (int*)malloc(sizeof(int)*size);

    for(int i = 0; i < size; i++){
        int num;
        scanf("%d", &num);
        A[i] = num;
    }

    for(int j = 0; j < size; j++){
        int num;
        scanf("%d", &num);
        B[j] = num;
    }

    while(1){
        scanf("%s", str);
        if(str[2] == 'A') Swap(A, B);//Swap
        else if(str[2] == 'I') Switch(&A, &B);//Switch
        else if(str[2] == 'P') Replace(A, B);//Replace
        else if(str[2] == 'O') break;//Stop
    }

    PrintArrays(A, B, size);
    //FREE
    free(A);
    free(B);
    return 0;
}

void Swap(int* A, int* B)
{
    int i, j, temp = 0;
    char a , b;
    scanf(" %c %c%d %d", &a, &b, &i, &j);
    if(a == 'A' && b == 'B') 
    {
        temp = A[i];
        A[i] = B[j];
        B[j] = temp; 
    } 

    else if(a == 'A' && b == 'A') 
    {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp; 
    } 

    else if(a == 'B' && b == 'A') 
    {
        temp = B[i];
        B[i] = A[j];
        A[j] = temp; 
    } 
    
    else
    {
        temp = B[i];
        B[i] = B[j];
        B[j] = temp; 
    }
}

void Switch(int**A, int**B)
{
    int* C; //*ambil the real avlue of A or B karena dia kirim adress
    C = *A;
    *A = *B;
    *B = C;
    
    
}

void Replace(int*A, int*B)
{
    char a;
    int i, j;
    scanf(" %c%d %d", &a, &i, &j);
    if (a == 'A') A[i] = j;
    else B[i] = j;
}

void PrintArrays(int *A, int *B, int size){
    for(int i = 0; i < size; i++){
        if(i != 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");

    for(int j = 0; j < size; j++){
        if(j != 0) printf(" ");
        printf("%d", B[j]);
    }
    printf("\n");
    return;
}