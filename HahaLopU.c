// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #define Bigger(a, b) (a >= b)
// //int LCS(void);

// int main(void)
// {
    
//     int m, n;
//     static int Track[3105][3105];
//     char S1[3105], S2[3105];
//     scanf("%s", S1);
//     scanf("%s", S2);
//     m = strlen(S1);
//     n = strlen(S2);

//     //Set the tables
//     for (int i = 0; i <= m; i++) {
//         Track[i][0] = 0;
//     }
//     for (int j = 0; j <= n; j++) {
//         Track[0][j] = 0;
//     }
    
//     //Co Kang
//     for (int i = 1; i <= m; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (S1[i-1] == S2[j-1]) Track[i][j] = Track[i-1][j-1] + 1;

//             else if(Track[i-1][j] >= Track[i][j-1]) Track[i][j] = Track[i-1][j];
            
//             else Track[i][j] = Track[i][j-1];
//         }
        
//     }
//     int longest = Track[m][n];
//     printf("%d\n", longest);

//     //Character yang paling pjg;
//     char hasil[longest+1];
//     hasil[longest] = '\0';
//     int i = m, j =n;

//     //Trace ke atas
//     while (i > 0 && j > 0)
//     {
//         //Kalau smaa dia move ke dagonalnya
//         if(S1[i-1] == S2[j-1]) 
//         {
//             hasil[longest-1] = S1[i-1];
//             longest--;
//             i--;
//             j--;
//         }
//         //kalau diag atas lebih gede move ke sana
//         else if(Track[i-1][j] > Track[i][j-1]) i--;
//         //Kalau diag kiri lebig gede move ke sana
//         else j--;
//     }
    
//     printf("%s", hasil);
// }

#include <stdio.h>
#include <string.h>

int main(void)
{
    static int Track[3000][3000];
    int m , n;
    char S1[3105], S2[3105];
    scanf("%s", S1);
    scanf("%s", S2);
    m = strlen(S1);
    n = strlen(S2);

    for (int i = 0; i <= m; i++) Track[i][0] = 0;
    for (int j = 0; j <= n; j++) Track[0][j] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (S1[i-1] == S2[j-1]) Track[i][j] = 1 + Track[i-1][j-1];
            else if(Track[i-1][j] >= Track[i][j-1]) Track[i][j] = Track[i-1][j];
            else Track[i][j] = Track[i][j-1];
        }
        
    }
    int longest = Track[m][n];
    printf("%d\n", longest);
    char hasil[longest+1];
    hasil[longest] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (S1[i-1] == S2[j-1])
        {
            hasil[longest-1] = S1[i-1];
            longest--;
            i--;
            j--;
        }
        
        else if(Track[i-1][j] > Track[i][j-1]) i--;
        else j--;
    }
    printf("%s\n", hasil);
}