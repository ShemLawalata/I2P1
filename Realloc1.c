#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int n1, n2, *ptr;
    printf("enter nimber of n1 : %d\n", n1);
    scanf("%d", &n1);
    //MAlloc
    ptr = (int *) malloc(n1*sizeof(int));
     printf("Addresses of previously allocated memory:\n");
    for(int i = 0; i < n1; ++i)
    printf("%pc\n",ptr + i);
    
//REalloc
    printf("enter nimber of n2 : %d\n", n2);    
    scanf("%d", &n2);
    ptr = realloc(ptr, n2*sizeof(int));
    printf("Addresses of newly allocated memory:\n");
    for(int i = 0; i < n2; ++i)
    printf("%pc\n", ptr + i);
    //FREE
    free(ptr);
}