#include <stdio.h>
#include <stdlib.h>

/* Define a new type */
/* Name the new type as “Point” */
/* The Point type contains two members, x and y */
/* Point can be used as a general type after being defined */
/* The definition should include declaration of all new variables and functions */

typedef struct {
    int x;
    int y;
} Point;

/* ones_vec_1() returns the address of a Point struct */
/* This address is beginning of the array used for storing the Point struct */
Point *ones_vec_1(int length);

void ones_vec_2(int length, Point **bp);

int main(void)
{
   Point *a, *b;// a and b are two pointers point to two memory arrays storing the Point structure
   int i, length;

   printf("The size of a Point is %lu bytes.\n", sizeof(Point));

   printf("vector length: ");
   scanf("%d", &length);

   /* Use ones_vec_1 to fetch an array */
   /* Each element in the array is a Point */
   /* The pointer a stores the address of the beginning of the array */
   a = ones_vec_1(length);
   ones_vec_2(length, b);//allow b to be modified by function ones_vec_2()

   for (i=0; i<length; i++)
      printf("(%d, %d) ", a[i].x, a[i].y);
   printf("\n");

   for (i=0; i<length; i++)
      printf("(%d, %d) ", b[i].x, b[i].y);
   printf("\n");

   return 0;
}

Point * ones_vec_1(int length)
{
   Point *a;
   int i;

   a = (Point *) malloc(length * sizeof(Point));

   for (i = 0 ; i < length; i++) {
      a[i].x = 1;
      a[i].y = 1;
   }

   return a;
}

void ones_vec_2(int length, Point **bp)
{
   int i;

   *bp = (Point *) malloc(length * sizeof(Point));

   for (i = 0 ; i < length; i++) {
      (*bp)[i].x = 1;
      (*bp)[i].y = 1;
   }
}
