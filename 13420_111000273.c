#include<stdio.h>
int world[105][105], visit[105]; //always assign 0 if global
int n;
int Pick();//Picking a city
void DFS(int);

int main()
{
    int k,c,d,city ,count=0;
    scanf("%d %d", &n, &k);
    while(k--){
        scanf("%d %d", &c, &d);
        world[c][d]=1;
        world[d][c]=1;
    }
    // for (int i = 0; i < n; i++) printf("[%d]", visit[i]);
    // printf("\n");

    while((city=Pick())!=-1){
        DFS(city);
        count++;
    }
    printf("%d\n", count-1);
    return 0;
}

int Pick(){
    for (int i=0; i<n; i++){
        if(visit[i]==0){
            return i;
        }
    }
    return -1;
}

void DFS(int travel){
    visit[travel] = 1;
    for(int i=0; i<n; i++){
        if(world[travel][i]==1 && visit[i]==0){
            DFS(i);
        }
    }
}