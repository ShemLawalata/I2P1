#include<stdio.h>

int main (){
    int arr[31];
    int i;
    unsigned int input;
    for ( i = 0; i < 31; i++)
    {
        arr[i]=-1;
    }
    int q=1;
    int r;
    int idx=0;
    scanf("%u", &input);
    if (input==0)
    {
        printf("%d",input);
        return 0;
    }

    while (q !=0)
    { 
        q = input/2;
        r = input%2;
        input=q;
        arr[idx]=r;
        idx=idx+1;
    }
    for ( i = 0; i<31; i++)
    {
        if (arr[31-i-1]!=-1)
        {
            printf("%d", arr[31-i-1]);
        }
    }
    printf("\n");
    }

