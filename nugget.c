#include<stdio.h>
int k, a;
long int count = 0;
long int max, min, n;
long int box[25];//set local atau pakai malloc
int combination(long int n, int a);
//greedy but in recursion and in order
int main(void)
{
    /*input * n dan k * ukuran box maybe store in array; */
   
    scanf("%ld%d", &n, &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%ld", &box[i]);
    }
    
    a = k-1;

    combination(n, a); //print jawaban
    printf("%ld\n", count);

}

int combination(long int n, int a)
{
    //base case

    if (n < 0)return 0;
    if (n == 0)
    {
        count++;
       // printf("count %d", count);
        return 1;
        //balik lagi 
    }

    //recursive
    else
    {
        for (int i = a; i >= 0; i--)
        {
            if (n >= box[i])
            {
            n -= box[i];
            //printf("dikurang [%ld] sisa (%ld)\n", box[i], n);
            combination(n, i);
            n += box[i]; 
            }
           //printf("\nrenew {%ld}\n", n);//n renew supaya ya bisa buat lagilah
        }
        return 0;
    }
}

//Call function combination print how many rantang
    /*
    *urutan kombinasinya harus berurutan dalam loop
    *dia cek setiap kemungkinan dalam loop juga
    *udah dapat hasil kita back terus decrement sebelum, then yang setelahnya mulai dr 4 kalau misalnya yang sebelum lebih kecil pakai cindition yg sama dgn sebelumnya
    *setiap hasil sama dengan jumlah nugget tambuah 1
    */