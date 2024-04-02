#include <stdio.h>
#include <math.h>
#include <string.h>
int main ()
{ 
  char exm[27]="QWERTYUIOPASDFGHJKLZXCVBNM";
  char inp[6];
  char out[6];
  scanf("%s", inp);
  out[0]=exm[inp[0]-'a'];
  out[1]=exm[inp[1]-'a'];
  out[2]=exm[inp[2]-'a'];
  out[3]=exm[inp[3]-'a'];
  out[4]=exm[inp[4]-'a'];
  out[5]='\0';
  printf("%s\n", out);
  //  char arr [27] = {"ZYXWVUTSRQPONMLKJIHGFEDCBA"};
  //  char new [1000];
  //  char ans[10];
  //  scanf("%s", new);

  //  ans[0]= arr[new[0]-'a'];
  //  ans[1]= arr[new[1]-'a'];
  //  ans[2]= arr[new[2]-'a'];
  //  ans[3]= arr[new[3]-'a'];
  //  ans[4]= arr[new[4]-'a'];
  //  ans[5]= '\0';

  //  printf("%s\n", ans);
   

// char new [1000];
// char arr[100] = "abcdefghijklmnopqrstuvwxyz";
//     scanf("%s", new);
//   for (int i = 0; i < 5; i++)
//    {
//    int b = (new[i]-'a')*2;
//    int a = 7+b;
//    new [i]= new[i]- a;
//   }
//   new[5] = '\0';
//    printf("%s\n", new);
   
}