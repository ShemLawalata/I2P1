#include <stdio.h>
#include <stdlib.h>
typedef struct _Node{
    int val;
    struct _Node *next;
}Node;
Node* Solver(Node* head, int k);


Node* createNode(int val){
    Node *node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}
void printList(Node* head)
{
    while(head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main()
{
    Node* head = NULL;
    
    int tmp;
    scanf("%d", &tmp);
    head = createNode(tmp);
    Node* tail = head;
    
    while(1)
    {
        scanf("%d", &tmp);
        if(tmp==-1)
            break;
        tail->next = createNode(tmp);
        tail = tail->next; //Node baru
    }
    
    int k;
    scanf("%d", &k);
    Node* res = Solver(head, k);
    printList(res);
    
    return 0;
}

Node* Solver(Node* head, int k)
{
    Node* Decoy = head;
    static Node* Array[1000000];
    int total = 0;
    int hehe[1000]; //hehe ini ntarlah
    int idx = 0;

    while (Decoy != NULL)//beda
    {
        Array[idx] = Decoy;
        hehe[idx] = Decoy->val;
        total++;
        Decoy = Decoy->next;
        idx++;
    }
    // for (int i = 0; i < idx; i++)
    // {
    //     printf("%d ", Array[i]->val);
    // }
    // printf("\n");
    //printf("total: %d\n", total);

    int limit = 0;
    int start = 1;
    int i = 0;
    Node* Temp;
    while (limit++ != total/k)
    {
        for (i = start; i < (start+k-1); i++)
        {
            int j = i-1;
            Temp = Array[i];
            while (j >= start-1 && (Temp->val < Array[j]->val))
            {
                Array[j+1] = Array[j];
                Array[j] = Temp;
                j--;
            }
            
        }
        //printf("i: %d ", i);
        start = i+1;
        
    }
    //Sambungin
    int a = 0;
    for ( a = 0; a < idx-1; a++)
    {
        Array[a]->next = Array[a+1];
    }
    Array[a]->next = NULL;
    return Array[0];
}