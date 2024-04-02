#include<stdio.h>
#define SIZE 4
int main(void)
{
   char cdata[SIZE] = {'A', 'B', 'C', 'D'};//assume cdata==0022FF6C
   char * ptc;
   int idata[SIZE] = {1, 2, 3, 4};//assume idata==0022FF50
   int * pti; 
   int k; 

   ptc = cdata;//make ptc point to the first element of array cdata
   pti = idata;//make pti point to the first element of array idata
   
   printf("%20s %12s\n", "char", "int"); 
   for (k = 0; k < SIZE; k++)
      printf("pointers + %d: %10p %c  %10p %d\n",
         k, ptc+k, *ptc+k, pti+k, *pti+k); 

         printf("%ld", pti +2 - pti);
    
   return 0; 
} 
//pti 