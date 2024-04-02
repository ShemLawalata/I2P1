#include <stdio.h>
#include <string.h>

int main ()
{
    char string[1000];
    char ch;
    int Temper, length, i = 0, no = 0;
    scanf("%s\n", string);
    scanf("%d\n", &Temper);
    length = strlen(string);
    while (scanf("%c", &ch) != EOF)
    {
        if (ch == '\n') continue;

        if (ch == string[i] && no == 0)
        {
            i++
            printf("%d\n", i);
        }
        
        else
        {
            if (ch == '!')
            {
                i = 0;
                no = 0;
                Temper -= 2;
            }

            else if (ch == '/')
            {
                Temper--;
                no--;
                if (no <= 0)
                {
                    no = 0;
                    i--;
                    if (i < 0) i=0;
                }
                
            }
            else
            {
                no++;
                printf("no\n");
            }
        }
        
        if (Temper <= 0)
        {
            printf("SAYONARA\n");
            break;
        }
        
        if (i == length) 
        {
            printf("DAISUKI!\n");
            break;
        }

        
    }
    

}