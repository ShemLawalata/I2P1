#include <stdio.h>
int main(void)
// Simple jangan ribet
{
    // array img tambah 1 karena kita mulainya dari [1][1], karena array start from [0][0]
    // tapi emang lebih bagus buat lebih jadi aman 
    int inp;
    scanf("%d", &inp);
    int const row = inp;
    int const column = inp;
    int img[row+1][column+1];

// Matrix Image
    for (int i = 1; i <= inp; i++)
    {
        for (int j = 1; j <= inp; j++)
        {
            scanf("%d", &img[i][j]);
        }
    }
    
    // for (int i = 1; i <= inp; i++)
    // {
    //     for (int j = 1; j <= inp; j++)
    //     {
    //            printf("%d ", img[i][j]);
    //     }
    //     printf("\n");
    // }

// Matrix Checker
    int enter;
    scanf("%d", &enter);
    int const r = enter,c = enter;
    int pola[r][c];

    for (int i = 0; i < enter; i++)
    {
        for (int j = 0; j < enter; j++)
        {
            scanf("%d", &pola[i][j]);
        }
        
    }
    
// Checking
// Tentuin batasan pengecekan sesuai pola 
    int store = 0;
    for (int i = 1; i <= inp-(enter-1); i++)//batas lopp i dan j juga untuk tentuin array i dan j
    {
        for (int j = 1; j <= inp-(enter-1) ; j++)
        {
            int flag = 1;
            for (int a = 0; a < enter; a++)
            {
                if (flag==0) //Conditional saja 
                {
                    break;
                }
                // SISTEM LOOP SELALU SATU" BERURUT
                // Ngga ada yang instan
                for (int b = 0; b < enter; b++)
                {
                   if (img[i+a][j+b] != pola[a][b] && pola[a][b] == 1) // check match apa ngga dengan pattern yang bernilai 1
                   {
                    // printf("a=%d b=%d\n", a, b);
                    // printf("i=%d j=%d\n", i, j);
                    // printf("img=%d, pattern=%d\n", img[i+a][j+b], pola[a][b]);
                    flag = 0;
                    break;
                   }
                   
                   else //Kalau else mau pakai if sertakan curly braces
                   {
                    if (a == enter-1 && b == enter-1) //ini pakai conditional di atas, semacam dioper gitu 
                    {
                        store++;
                    }
                   }
                   
                   
                }
                
            }
            
            
        }
        
    }
    printf("%d\n", store);



    
}