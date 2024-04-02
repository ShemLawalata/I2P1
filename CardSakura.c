// //10 table or array 0-9 //No card awalnya
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// typedef struct 
// {
//     int Card[10005];
//     int jumlah;
// }Table;

// //Print
// void print(Table* Paket);
// //All
// void all(Table* Paket, int n, int len);
// //Place
// void place(Table* Paket, int idx, int len);
// //Swap
// void swap(Table* Paket, int, int);
// //Clear
// void clear(Table* Paket);
// //Exit
// //void exit(Table* Paket);
// //Left Shift
// void left(Table* Paket);
// //Right Shift
// void right(Table* Paket);

// int main (void)
// {
//     char S[100];
//     Table *Paket = (Table*)malloc(10*sizeof(Table));
//     for (int i =0; i < 10; i++) Paket[i].jumlah = 0;
//   //co kang
//   while (1)
//   {
//     scanf("%s", S);
//     if (strcmp(S, "print") == 0) print(Paket);
//     if (strcmp(S, "all") == 0)
//     {
//         int n, len;
//         scanf("%d %d", &n, &len);
//         all(Paket, n, len);
//     }
//     if (strcmp(S, "place") == 0)
//     {
//         int sequence[10005], idx, len;
//         scanf("%d %d", &idx, &len);
//         place(Paket, idx, len);
//     }
//     if (strcmp(S, "swap") == 0)
//     {
//         int a, b;
//         scanf("%d %d", &a, &b);
//         swap(Paket, a, b);
//     }
//     if (strcmp(S, "clear") == 0) clear(Paket);
//     if (strcmp(S, "exit") == 0)
//     {
//         free(Paket); break;
//     }
//     if (strcmp(S, "shiftleft") == 0) left(Paket);
//     if (strcmp(S, "shiftright") == 0) right(Paket);
//   }
  
  
    
// }

// void print(Table* Paket)
// {
//     for (int i = 0; i < 10; i++)
//     {
//         if (Paket[i].jumlah == 0)
//         {
//             printf("%d:", i);
//             printf(" No card\n");
//         }
        
//         else 
//         {
//             printf("%d:", i);
//             for (int j = 0; j < Paket[i].jumlah; j++)
//             {
//                 printf(" %d", Paket[i].Card[j]);
//             }
//             printf("\n");
//         }
//     }
    
// }

// void all(Table* Paket, int n, int len)
// {
//     for (int i = 0; i < 10; i++)
//     {
//         Paket[i].jumlah = len;
//         for (int j = 0; j < len; j++)
//         {
//             Paket[i].Card[j] = n;
//         }
        
//     }
    
// }

// void place(Table* Paket, int idx, int len)
// {
//     Paket[idx].jumlah = len;
//     for (int i = 0; i < len; i++)
//     {
//         scanf("%d", &Paket[idx].Card[i]);
//     }
    
// }

// void swap(Table* Paket, int a, int b)
// {
//     Table temp; // karena kalau pakao[] kita langsung acces isi yaitu  table dan bukak ptr paket lg
//     temp = Paket[a];
//     Paket[a] = Paket[b];
//     Paket[b] = temp;
// }

// void clear(Table* Paket)
// {
//     for (int i = 0; i < 10; i++)
//     {
//         Paket[i].jumlah = 0;
//     }
    
// }

// void left(Table* Paket)
// {
//     Table temp = Paket[0];
//     int i;
//     for ( i = 0; i < 9; i++) //kita mau akhirnya di 8 aja
//     {
//         Paket[i] = Paket[i+1];
//     }
//     Paket[i] = temp;
// }

// void right(Table* Paket)
// {
//     Table temp;
//     int i;
//     temp = Paket[9];
//     for ( i = 9; i > 0; i--)//mau sampai 1 aja
//     {
//         Paket[i] = Paket[i-1];
//     }
//     Paket[i] = temp;
// }


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int Card[10005];
    int jumlah;
} Table;
//print
void print(Table* Paket);

//all
void all(Table *Paket, int n, int len);

//place
void place(Table* Paket, int idx, int len);

//swap
void swap(Table* Paket, int a, int b);

//clear
void clear(Table* Paket);

//exit

//shift left
void left(Table* Paket);

//shift right
void right( Table* Paket);
int main(void)
{
    char S[100];
    Table* Paket = (Table*) malloc(11*sizeof(Table));
    for (int i = 0; i < 10; i++) Paket[i].jumlah = 0;

    while (1)
    {
        scanf("%s", S);
        if(strcmp(S, "print") == 0) print(Paket);
        if(strcmp(S, "all") == 0)
        {
            int len , n;
            scanf("%d %d", &n, &len);
            all(Paket, n, len);
        }
        if(strcmp(S, "place") == 0)
        {
            int idx, len;
            scanf("%d %d", &idx, &len);
            place(Paket, idx, len);
        }
        if (strcmp(S, "swap") == 0)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            swap(Paket, a, b);
        }
        if (strcmp(S, "clear") == 0) clear(Paket);
        if (strcmp(S, "exit") == 0)
        {
            free(Paket); break;
        }
        if(strcmp(S, "shiftleft") == 0) left(Paket);
        if(strcmp(S, "shiftright") == 0) right(Paket);
    }
    
    
}

void print(Table* Paket)
{
    for (int i = 0; i < 10; i++)
    {
        if (Paket[i].jumlah == 0)
        {
            printf("%d:", i);
            printf(" No card\n");
            
        }
        
        else
        {
            printf("%d:", i);
            for (int j = 0; j < Paket[i].jumlah; j++)
            {
                printf(" %d", Paket[i].Card[j]);
            }
            printf("\n");
        }
    }
    
}

void all(Table *Paket, int n, int len)
{
    for (int i = 0; i < 10; i++)
    {
        Paket[i].jumlah = len;
        for (int j = 0; j < len; j++)
        {
            Paket[i].Card[j] = n;
        }
        
    }
    
}

void place(Table* Paket, int idx, int len)
{
    Paket[idx].jumlah = len;
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &Paket[idx].Card[i]);
    }
    
}

void swap(Table* Paket, int a, int b)
{
    Table temp = Paket[a];
    Paket[a] = Paket[b];
    Paket[b] = temp;
}

void clear(Table* Paket)
{
    for (int i = 0; i < 10; i++)
    {
        Paket[i].jumlah = 0;
    }
    
}

void left(Table* Paket)
{
    int i = 0;
    Table temp = Paket[0];
    for (i = 0; i < 9; i++)
    {
        Paket[i] = Paket[i+1];
    }
    Paket[i] = temp;
}

void right(Table* Paket)
{
    Table temp = Paket[9];
    int i = 0;
    for ( i = 9; i > 0; i--)
    {
        Paket[i] = Paket[i-1];
    }
    Paket[i] = temp;
}