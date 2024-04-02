#include <stdio.h>

int main(void)
{
    //Input for matrix MxN, NxM, loop, variable, double array, array 
        //1 <= N M <= 2100, 
        int M, N;
        static int A[2102][2102];
        static int B[2102][2102];
        static int Produk[2102][2102];
        static int Transpose[2102][2102];
        scanf("%d", &M);
        scanf("%d", &N); 
        for (int i = 1; i <= M; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                scanf("%d", &A[i][j]);
            }
        }


        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                scanf("%d", &B[i][j]);
            }
            
        }
        
    //Multiple matrix using 3 loop, yang ketiga utk tentuin point perpoin, buat variabel store hasil kali, int sum;
    int sum = 0;
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                sum += A[i][k] * B[k][j];
            }
                Produk[i][j] = sum;  //simpan dalam array baru 
                sum = 0;
        }
    }
    
    //Transpose matrix $loop needed from one iteration i, changes in j, swtich
    for (int i = 1, j; i <= M; i++)
    {
        for (j = 1; j <= M; j++)
        {
            Transpose[i][j] = Produk[j][i]; 
            if (j < M)
            {
                printf("%d ", Transpose[i][j]); //print result with space
            }
            else 
            {
                printf("%d\n", Transpose[i][j]);   
            }
            
        }
    }
    
}