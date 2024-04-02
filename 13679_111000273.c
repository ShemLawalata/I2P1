#include<stdio.h>
int n, row, col;
int flag = 0;
long long int save = 0;
long long int score = -10000000001;
long int Garden[15][15];
int P[15];
int place(int n, int row);
int valid(int row, int col);

int main(void)
{
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%ld", &Garden[i][j]);
        }
        
    }

    //check and show results
    place(n, 0);
    if (flag == 1) printf("%lld\n", score);
    else printf("no solution\n");
}

int place(int n, int row)
{
    if (row == n)
    {
        flag = 1;
        for (int i = 0; i < n; i++) //oooh makanya setiap i di loop beda" i see...
        {
            save += Garden[i][P[i]];
        }
        
        if (save > score)
        {
            score = save;
        }
        save = 0;
        
    }

    else 
    {
        for (int col = 0; col < n; col++)
        {
            if (valid(row, col))//hanya pakai col yang di dalam loop ini
            {
                P[row] = col;
                place(n, row + 1);
            }
            
        }
    }
        return 0;
    
}

int valid(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (P[i] == col || P[i] == col -row + i || P[i] == col + row -i) return 0;
    }
    return 1;
    
}































// #include <stdio.h>

// int n;
// long int Garden[15][15];
// long int P[15];
// long long int score = -10000000001;
// long long int save = 0;
// int row, col;
// int flag = 0;
// int place(int row, int n);
// int valid(int row, int col);

// int main(void)
// {
//     //input
//     scanf("%d\n", &n);
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             scanf("%ld", &Garden[i][j]);
//         }
        
//     }

//     //check max point
//     place(0, n);
//     if (flag == 1) printf("%lld\n", score);
//     else printf("no solution\n");
    
// }

// int place(int row, int n)
// {
//     //Base case
//     if (row == n)
//     {
//         flag = 1;
//         //code for assig save with P
//         for (int i = 0; i < n; i++)
//         {
//             save += Garden[i][P[i]];
//         }
//         if(save > score) {score = save;}
//         save = 0;
        
//     }

//     else
//     {
//         for (int col = 0; col < n; col++)//ga initial col sbgai int,  why?? Bisa jadi karna input valid itu int col
//         {
//             if (valid(row, col))
//             {
//                 P[row] = col;
//                 place(row+1, n);
//             }
            
//         }
        
//     }
    
// }

// int valid(int row, int col)
// {
//     for (int i = 0; i < row; i++)
//     {
//         if(P[i] == col || P[i] == (col - row + i) || P[i] == (col + row - i)) return 0;
//     }
//         return 1;// hati hati
    
// }