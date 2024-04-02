#include <stdio.h>
int main(void)
{
    int inp;
    scanf("%d", &inp);
    int const row = inp, column = inp; 
    int img[row+1][column+1];
    //Image
    for (int i = 1; i <= inp ; i++)
    {
        for (int j = 1; j <= inp; j++)
        {
           scanf("%d", &img[i][j]);
        }
        
    }
    //Pola
    int ent;
    scanf("%d", &ent);
    int const c = ent, r = ent;
    
    int pola[r][c];
    for (int i = 0; i < ent; i++)
    {
        for (int j = 0; j < ent; j++)
        {
            scanf("%d", &pola[i][j]);
        }
        
    }
    //Check
    //Batas
    int store = 0;
    for (int i = 1; i <= inp-(ent-1); i++)
    {
       for (int j = 1; j <= inp-(ent-1); j++)
       { 
        int flag = 1;
        for (int a = 0; a < ent; a++)
        {
            if (flag==0)
            {
                break;
            }
            for (int b = 0; b < ent; b++)
            {
                if (img[i+a][j+b] != pola[a][b] && pola[a][b] == 1)
                {
                    flag = 0;
                    break;
                }
                
                else if (a == ent-1 && b == ent-1)
                {
                    store++;
                }
                
            }
            
        }
        
       }
       
    }
    printf("%d\n", store);
    
}