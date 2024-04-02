#include <stdio.h>

int main(void)
{
    // Input N array 3 - 1000, L subarray 3 - 10, array
    int N, L, flag = 1, flag2 = 1;
    scanf("%d %d", &N, &L);
    int arr[1001];
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    // Buat loop batas pembanding subarray, batasnya tergantung dengan L nya
    for (int i = 1; i <= N - (L - 1); i++) //declare flag == 1 dmn?
    {   
        flag = 1;
        for (int a = i + 1; a < i + (L - 1); a++)
        {   
            
            if (arr[i] >= arr[a] || arr[i + (L - 1)] >= arr[a]) //##
            {
                flag = 0;
                break;
            }
        }
            if (flag)
            {   int p;
                flag2 = 0;
                for (p = i; p < i + (L - 1); p++)
                {
                    printf("%d ", arr[p]);
                }
                printf("%d\n", arr[p]);
            }
        
                //kalau ga dilanggar or flag ==1 mau print i - L, ingat ada domo
    }
            if (flag2) 
             {
             printf("Domo\n");
             }


    // 2nd loop bandingin nilai, flag 
    // Pakai conditional statement untuk cek besar kecilnya
    // bagian dalam harus lebih besar dari pojok kanan dan kiri, kalau ada salah satu yang lebih kecil langsung skip.
    // kalau gada yang sama print "domo", flag
    // print sub array with new line.
}