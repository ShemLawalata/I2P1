#include <stdio.h>
int main()
{
int *ptr, *ptr1, c;
int arr[2]= {0};
//ptr = arr[1];// harus pakai adress kalau mau ini tapi kalau arr aja bisa
//ptr1 = c;// ga boleh juga ini harus puba adress kta
ptr1 = arr+1;
//ptr =  &arr[1];
*ptr1 = 5;
//*ptr = 100;
printf("%d %d", *ptr1, arr[1]);
}
//array names decay to pointers. In simple words, array names are converted to pointers. That's the reason why you can use pointers to access elements of arrays. However, you should remember that pointers and arrays are not the same.
