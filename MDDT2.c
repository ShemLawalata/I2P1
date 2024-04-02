#include<stdio.h>

int main(void)
{
    static int arr[3000000];
    int N, T, k;
    scanf("%d %d", &N, &T);
    int a = 1;
    int i = 1;
    arr[0] = 0;

    while (N--)
    {   
            //add 1 after itulah
            arr[i] = 1;

            //Invert and reverse

            //invert
            for (int x = 0, add = 1; x < i; x++, add++) //ini mau invert terus assign ke dalam array i+1 
            {
                if(arr[x] == 0) arr[i+add] = 1;
                else arr[i+add] = 0;
            }
            
            //reverse
            int temp = 0;
            int end = 2*i;
            int start = i+1;
            for (int y = 0; y < i/2; y++)
            {
                temp = arr[end-y];
                arr[end-y] = arr[start+y];
                arr[start+y] = temp;
            }
            i = 2*i+1;
    }

    //printf element index 'k'
    while (T--)
    {
        scanf("%d", &k);
        printf("%d\n", arr[k]);
    }
   
}