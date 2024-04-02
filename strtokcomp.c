#include <stdio.h>
#include <ctype.h>
#include <string.h>
void split(char *arr, int x);//
int main(void) //malloc buat size array?
{
    int T;
    scanf("%d", &T);
    char O[5005];
    char D[5005];
    while (T > 0)
    {
        int flag = 1;
        scanf("%s", O);
        scanf("%s", D); 
        int n = strlen(O);
        int m = strlen(D);
        //split the string 
    
        char *ptcO = strtok(O, "/");
        char *SubO[n+5];
        int i =0;
        while (ptcO != NULL)
        {
            SubO[i++] = ptcO;
            ptcO = strtok(NULL, "/");
        }
    /*for (int a = 0; a < i; a++)
    {
        printf("%s\n", SubO[a]);
    }*/
    
    char *ptcD = strtok(D, "/");
    char *SubD[m+5];
    int j = 0;
    while (ptcD != NULL)
    {
        SubD[j++] = ptcD;       //j is still iterating
        ptcD = strtok(NULL, "/");
    }
    // for (int a = 0; a < j; a++)
    // {
    //     printf("%s\n", SubD[a]);
    // }

    //comparing
    for (int x = 0; x < j; x++)//for D
    {
        if (flag == 1 && x == j ) break;
        if (flag == 0) break;
        for (int y = 0; y <i ; y++)//for O
        {
            int z = strcmp(SubD[x], SubO[y]);
            // printf("Z=%d\n", z);
            // printf("flag = %d\n", flag);              
            if (z == 0)
               {
                 flag = 1;
                 break;
               }
               flag = 0;
               if (y == i && z != 0) break;
               
        }
    }
    if (flag == 1) printf("valid\n");
    else printf("not valid\n");
    
       T--;
    }
    
    
    


}
//  for (int y = 0; y <=j ; y++)//for O
//         {
//             int z = strncmp(SubD[x], SubO[y]);
//               if (z == 0)
//                {
//                  flag = 1;
//                  continue;
//                }
//         }