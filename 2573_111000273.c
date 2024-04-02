#include <stdio.h>
int main(void)
{
    //Image
    int input;
    scanf("%d", &input);
    int const row = input, column = input;
    int img[row+1][column+1];

    for (int i = 1; i <= input; i++)
    {
        for (int j = 1; j <= input; j++)
        {
            scanf("%d", &img[i][j]);
        }
        
    }
    //Pola
    int enter;
    scanf("%d", &enter);
    int const r = enter, c = enter;
    int pola[r][c];
    for (int i = 0; i < enter; i++)
    {
        for (int j = 0; j < enter; j++)
        {
            scanf("%d", &pola[i][j]);
        }
    }
    
    //Process
     //Batas
     int store = 0;
    for (int i = 1; i <= input-(enter-1); i++)
    {
         for (int j = 1; j <= input-(enter-1); j++) // Checking! 
         {
           
           int flag = 1;
           for (int a = 0; a < enter; a++)
           {
           if (flag == 0)
           {
            break;
           }
            for (int b = 0; b < enter; b++)
            {
                if (img[i+a][j+b] != pola[a][b]  && pola[a][b] == 1 )
                {
                    flag = 0;
                    break;
                }

                else if (a == enter-1 && b == enter-1)
                {
                    store++;
                }
                
                
            }
            
           }
           
         }
        
    }
    printf("%d\n", store);

    
}