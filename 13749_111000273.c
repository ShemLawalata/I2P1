#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
char p[10];
char s[500];
char **split_(char* str, char* pattern, int* split_num);
void free_(char **result, int split_num);
int main(){
    int i, split_num;
    char **result;
    scanf("%s",s);
    scanf("%s",p);
    result = split_(s, p, &split_num);
    for(i=0; i<split_num; ++i) printf("%s\n",result[i]);
    free_(result, split_num);
    return 0;
}
char **split_(char* str, char* pattern, int* split_num)
{
    char subs[500];
    int n = 0;
    *split_num = 0;
    char **result = (char**) malloc(sizeof(char*)*500);
    strcpy(subs, str);
    while (strlen(subs))
    {
        char *cut = strstr(subs,pattern);//WOi

        if (cut == NULL)
        {
            n = strlen(subs);
            if (n > 0)
            {
                result[*split_num] = (char*) malloc(sizeof(char) * n);
                strcpy(result[*split_num], subs);
                (*split_num)++;
            }
            break;
        }
        
        else{
            *cut = '\0';
            if (cut == subs)
            {
                strcpy(subs, str+(strlen(pattern)));
                strcpy(str, subs);
            }
            
            else{
                n = cut-subs;
                result[*split_num] = (char*) malloc(sizeof(char)*n);
                strncpy(result[*split_num], subs, n);
                strcpy(subs, str+(n+strlen(pattern)));
                strcpy(str,subs);
                (*split_num)++;
            }
        }
    }
    result = realloc(result, sizeof(char*)*(*split_num));
    return result;
}


void free_(char **result, int split_num)
{
    for (int i = 0; i < split_num; i++)
    {
        free(result[i]);
    }
    free(result);
}

// char **split_(char* str, char* pattern, int* split_num)
// {
//     char subs[500];
//     *split_num = 0;
//     //2D Dynamic Array
//     char **result = (char**) malloc(500*sizeof(char*));
//     int n = 0;
//     strcpy(subs, str);

//     while (strlen(subs)-1 != 0) //Idenya adalah kirim adress aja supaya bisa diakses result
//     {
//         char *cut = strstr(subs, pattern);
//         if (cut == NULL)
//         {
//             n = strlen(subs);
//             if (strlen(subs) > 0)
//             {
//                 result[*split_num] = (char*) malloc(n*sizeof(char));
//                 strcpy(result[*split_num], subs);
//                 (*split_num)++;
//             }
//             break;
//         } 
//         else{
//             *cut = '\0';
//             if (cut == subs) 
//             {
//                  strcpy(subs, str+(strlen(pattern)));
//                  strcpy(str, subs);
//             }
//             else
//             {
//              n = cut - subs;
//              result[*split_num] = (char*) malloc(n*sizeof(char)); //Brarti kirim adress every start point "str" ke subs
//              //result[*split_num] = cut-n;      //if '\0' continue dengan split_num tetap
//              strncpy(result[*split_num], subs, n);
//              strcpy(subs, str+(n+strlen(pattern)));
//              strcpy(str, subs);
//              (*split_num)++;
//             }
//         }
//     }
//     result = realloc(result,sizeof(char*) * (*split_num));
//     return result;
// }