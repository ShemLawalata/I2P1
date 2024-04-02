#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include <math.h>
int** s(int* a,int len);
void print(int** ans,int len);

int main() {
	int len;
	scanf("%d", &len);
	int *a = (int*)malloc(len * sizeof(int));
	for (int i = 0;i < len;i++) scanf("%d", &a[i]);
    int **ans; //Double pointer bisa juga jadi 2D array	
	ans = s(a,len);
	print(ans,len);
	free(a);
	return 0;
}

int** s(int* a, int len)
{
    int i = 1, j = 0;
    int temp = 0;
    int n = (int) sqrt(len);
    //Dynamic 2D Array
    int** ans = (int**) malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        ans[i] = (int*) malloc(n*sizeof(int));
    }
    
    //sort
    while (i < len)
    {
        j = i-1;
        temp = a[i];
        
        while (j >= 0)
        {
            //printf("temp: %d\n", temp);
            if (a[j] > temp)
            {
                a[j+1] = a[j];
                a[j] = temp;
            }
            j--;
        }
        i++;
    }
    // int **ans; //or int **ptr then ptr[(int)sqrt(len)][(int)sqrt(len)]
    
    //2D array ptr
    for (int x = 0, z = 0; x < n; x++)
    {
        for (int y = 0; (z < len) && (y < n); y++, z++)
        {
            ans[x][y] = a[z];
        }
        
    }
    return ans;

}

void print(int** ans,int len)
{
    int n = (int)sqrt(len);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", ans[i][j]);
        }
        printf("\n");
        
    }
    
}