#include<stdio.h>

int NQ;
int q[1000];
int count = 0;

void place(int row);
int valid(int row, int col);
void display(void);

int main(void)
{
    scanf("%d",&NQ);
    place(0);
    return 0;
}

void place(int row)
{
    int j;
    if (row == NQ) {
        display();
    } else {
        for (j=0; j<NQ; j++) {
            if (valid(row,j)) {
                q[row] = j;
	         place(row+1);
            }
        }
    }
}

int valid(int row, int col){
    for(int i = 0; i < row; i++) if(q[i] == col || q[i] == (col - row + i) || q[i] == (col + row - i)) return 0;
    return 1;
}

void display(void)
{
    int i, j;
    for (i=0; i<NQ; i++) {
        for (j=0; j<NQ; j++) {
	     if (q[i]==j) printf("O");
	     else printf("X");
	 }
	 printf("\n");
    }
    printf("\n");
}

