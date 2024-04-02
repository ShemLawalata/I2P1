#include<stdio.h>
#include<ctype.h>
char save;
int flag;
void postfix (int flag);

int main(void)
{
    //move operator and operands
    postfix(0);
}

void postfix(int flag)
{   char c; //local variable untuk setiap recursion supaya identitasnya masing"
    scanf(" %c", &c);
    //Basis step
    if (isdigit(c))         //read c as a integer //bisa pakai conditional 1-9
    {   int i;              // i kalau mau global juga ok karna dia valunya langsung print kalau 'c' kan dipakai terus jadi sensitif
        ungetc(c, stdin);   //putback c as int into stdin to be read as integer
        scanf("%d", &i);
        if (flag == 0)
        {
          printf("%d", i); 
        } 
        else printf(" %d", i);
        return;
    }
    //Recursive step
    else if  (c == '*' || c == '+' || c == '/' || c == '-')
    {
       //save = c; kalau pakai global variabel dia nilainya jd yang terakhir, ingat analogi pipis
        postfix(flag);
        flag = 1;
        postfix(flag);
        printf(" %c", c);//char kamu ga ke renew
        return;//autoreturn
    }
}