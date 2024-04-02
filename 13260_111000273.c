// #include <stdio.h>
// int main(void)
// {
//     int in;
//     scanf("%d", &in);
//     for (int i = 1; i <= in; i++)
//     {
//         //space
//         for (int s = 1; s <= in-i; s++)
//         {
//             printf(" ");
//         }
        
//         //angka
//         int b=i;
//         for (int a = 1; a <= 2*i-1; a++)
//         {
//             if (a<=i)
//             {
//                 printf("%d", a);
//             }

//             else 
//             {
//                 b--;
//                 printf("%d", b);
//             }
            
            
//         }
//         printf("\n");
//     }
    
// }

#include <stdio.h>
int main(void)
{
    int in;
    scanf("%d", &in);
    for (int i = 1; i <= in; i++)
    {
        //space
        for (int s = 1; s <= in-i; s++)
        {
            printf(" ");
        }
        
        int b = i;
        for (int a = 1; a <= 2*i-1; a++)//batas angkanya
        if (a<=i)
        {
            printf("%d", a);
        }
         
        else
        {
            b--;
            printf("%d", b);
        }
        printf("\n");
    }
    
}