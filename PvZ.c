#include<stdio.h>

int n;
long long int negatif = -10000000001;
long int count = 0;
long long int score = -10000000001;
int flag = 0;
int test = 0;
long long int save;
int P[15];
long int Garden[15][15];
int place(int row, int n); //Main recursion untuk list placement si starfruit
int valid(int row, int col); //To check apakah si Starfruit bisa ditaruh

int main(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%ld", &Garden[i][j]);
        }
    }
    
    place(0, n);
    if (flag == 1) printf("%lld\n", score);
    else printf("no solution\n");
}

int place(int row, int n)
{
    //Base case
    if (row == n ) //Mau hitung dan bandingin total simpanan position di arraynya.
    {
      test++;
      flag = 1;
      for ( row = 0; row < n; row++)
      {
        save += Garden[row][P[row]];
      }
      
    if (save > negatif) //pakai loop utk store final score.
    {
     if (save > score) score = save;
    }
     save = 0;
    }
    //Recursive step;
    else
    {
        for (int col = 0; col < n; col++)
        {
            if (valid(row, col)) //if Valid then store the value of particular point to our 1d storgae
            {
                P[row] = col; //array to store row or col
                //Count when you're sure you've reached your destination
                place(row + 1, n);

            }
            
        }
        
    }
}

int valid(int row, int col)
{
    //Wanna check apakah conflict dengan posisi sebelumnya
    for (int i = 0; i < row; i++) if (P[i] == col || P[i] == (col - row + i) || P[i] == (col + row - i)) return 0;//cek nilai atau posisinya?
    return 1;   
}