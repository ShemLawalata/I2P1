#include <stdio.h>
int n;
int map[105][105];
int visit[105];
int Pick();
int DFS(int);

int main(void)
{
    int k, c, d, city, count =0;
    scanf("%d %d",&n, &k);
    while (k--)
    {
        scanf("%d %d", &c, &d);
        map[c][d] = 1;
        map[d][c] = 1;
    }
    while ((city=Pick())!=-1)
    {
        DFS(city);
        count++;
    }
    printf("%d\n", count -1);
    return 0;    
}
int Pick()
{
    for (int i = 0; i < n; i++)
    {
        if (visit[i] == 0)
        {
            return i;
        }
        
    }
    return -1;
}

int DFS(int travel)
{
    visit[travel] = 1;
    for (int i = 0; i < n; i++)
    {
        if (map[travel][i] == 1 && visit[i] == 0)
        {
            DFS(i);
        }
        
    }
    
}













// #include<stdio.h>
// int map[105][105], visit[105]; //always assign 0 if global
// int n;
// int Pick();//Picking a city
// void DFS(int);

// int main()
// {
//     int k,c,d,city ,count=0;
//     scanf("%d %d", &n, &k);
//     while(k--){
//         scanf("%d %d", &c, &d);
//         map[c][d]=1;
//         map[d][c]=1;
//     }

//     while((city=Pick())!=-1){
//         DFS(city);
//         count++;
//     }
//     printf("%d\n", count-1);
//     return 0;
// }

// int Pick(){
//     for (int i=0; i<n; i++){
//         if(visit[i]==0){
//             return i;
//         }
//     }
//     return -1;
// }

// void DFS(int travel){
//     visit[travel] = 1;
//     for(int i=0; i<n; i++){
//         if(map[travel][i]==1 && visit[i]==0){
//             DFS(i);
//         }
//     }
// }