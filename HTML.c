// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// int count = 0;

// int main (void)
// {
//     char S[1005];
//     char Subs[1005];
//     while (gets(S)!= NULL)
//     {
//         char *title = NULL, *link = NULL; //Title founder
//         int len = 0;
//         strcpy(Subs, S);
//         title = strstr(Subs, "<title>");//dia return adress "<" pertama
//         if (title != NULL)//Title aj juga bisa
//         {
//             *title = '\0';//Bisa juga tambah pointernya Subs += Subs+....
//             len = strlen(Subs);
//             //printf("len: %d\n", len);
//             strcpy(Subs, S+len+strlen("<title>"));//karna string mulainya dari elemnt [0]kan jadi kalau di tambah ya lewat 1 jadinya
//             char *split = strtok(Subs, "<");
//             printf("%s\n", split);
//         }
//         strcpy(Subs, S);
//         while ((link = strstr(Subs, "</a>")) != NULL)
//         {
//             ++count;
//             *link = '\0';
//             len = strlen(Subs);
//             strcpy(Subs, S+len+strlen("</a>"));
//             strcpy(S, Subs);
//         }
        
//     }
//     printf("%d\n", count);
// }
        
#include <stdio.h>
#include <string.h>

int count = 0;
int main (void)
{
    char S[1005], Subs[1005];
    while (gets(S) != NULL)
    {
        int len = 0;
        char *link = NULL, *title = NULL;
        //Mainin Subs dan S sebagai patokan
        strcpy(Subs, S);
        title = strstr(Subs, "<title>"); //dia kasih adress ke "<"
        if (title != NULL)
        {
            *title = '\0';
            len = strlen(Subs);
            strcpy(Subs, S+len+strlen("<title>"));
            char *split = strtok(Subs, "<"); // mau potong yang lastnya dia returb asress awalnya dan yang delim diganti '\0'
            printf("%s\n", split);
        }
        //Renew
        strcpy(Subs, S);
        while ((link = strstr(Subs, "</a>")) != NULL)
        {
            ++count;
            *link = '\0';
            len = strlen(Subs);
            strcpy(Subs, S+len+strlen("</a>"));
            strcpy(S, Subs);
        }
        
    }
    printf("%d\n", count);

}