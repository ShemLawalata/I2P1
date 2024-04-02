#include <stdio.h>
#include <math.h>
#include <string.h>
char S[25];
int Total = 0;
int i = -1;
int flag = 1;
void Window(int size);

int main(void)
{
    int N, size;
    scanf("%d %s", &N, S);
    size = pow(2, N) * pow(2,N);
    //Print domo    
    if ((strlen(S)-1)%4 != 0) printf("Domo");
    //Total colour
    else
    { 
        Window(size); 
        if (flag == 0)printf("Domo");       
        else printf("%d", Total);
        }
    
}

void Window(int size)
{
    i++;
    //printf("%c",S[i]);
        if(size < 1 || S[i] == '\0')
        {
            flag = 0;
            return;
        }
        else
        {
            if (S[i] == '0') return;
            else if(S[i] == '1') 
            {
                Total += size;
                return;
            }
        
            else
            {
                Window(size/4);
                Window(size/4);
                Window(size/4);
                Window(size/4);
                return;
            }
        }
}
