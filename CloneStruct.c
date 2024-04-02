#include <stdio.h>
#include <stdlib.h>
typedef struct t_data {
int size;
int * ptr;
} DATA;

void create_data(DATA *z, int sz);
void show_data(DATA d);
DATA clone_data(DATA x);
void delete_data(DATA *z);

int main(void)
{
DATA x, x_clone;

create_data(&x, 100);
show_data(x);

x_clone = clone_data(x);//why not x_clone = x directly? Karena dia bkalan point ke adress malloc yang sama. Makanya kita harus return y baru pakai '=' utk assign value y ke x clone ezzzz
delete_data(&x);
show_data(x_clone);

return 0;
}

void create_data(DATA *z, int sz)
{
int i;
z->size = sz;
z->ptr = (int *) malloc(sz*sizeof(int));
for (i=0; i< sz; i++) 
{
    (z->ptr)[i] = i;
}
}
void show_data(DATA d)
{
int i;
printf("%u\n", sizeof(d));
for (i=0; i<d.size; i++) {
printf("%d ", (d.ptr)[i]);
if ((i+1)%10 == 0) printf("\n");
}
}

DATA clone_data(DATA x)
{
 int i;
 DATA y;
 y.size = x.size;
 y.ptr = (int *) malloc(y.size*sizeof(int));
 for (i=0; i<y.size; i++) {
 (y.ptr)[i] = (x.ptr)[i];
 }
 return y;
}

void delete_data(DATA *z)
{
free(z->ptr);//release the memory pointed to by ptr
 z->ptr = NULL;
 z->size = 0;
}
