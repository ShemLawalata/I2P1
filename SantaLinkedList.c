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

// Node* Solver(Node* head, int k)
// {
//     if (k==1) return head;
    
//     //Hitung br banyak node start dr 1 karna hitung head juga
//     int total = 1;
//     Node* Decoy = head;
//     while (Decoy->next != NULL)
//     {
//      total++;
//      Decoy = Decoy->next;
//     }    
    
//     //Start work *Switch setiap kelipatan dari k*
//     int limit = 0; // kalau sudah sampai total/k return

//     Node *Help = (Node*) malloc(sizeof(Node)); //free //sebagai bantuan
//     Node *Last, *Temp, *Target, *Switcher, *Destination;
//     Help->next = head;
//     Decoy = head;
//     Temp = head;
//     Last = Help;// untuk point ketika sudah selesai swap
//     while (limit++ != total/k)
//     {
//         int step = 1;
//         Switcher = Decoy->next; //Yang mau diswitch

//         while (step++ != k)// ada satu loop sebanyak k kali itu bagian switch"nya
//         {
            
//             Target = Decoy;//Mau switch kemana
//             Destination = Switcher->next; //iteration selanjutnya

//             Decoy = Switcher;
//             Switcher->next = Target;
//             Switcher = Destination;

//         }
//         Last->next = Decoy;
//         Temp->next = Destination;
//         Last = Temp;
//         if(Destination == NULL)break;
//         Temp = Destination;
//         Decoy = Destination;
//     }
//     return Help->next;
// }
        
Node* Solver(Node* head, int k)
{
    int total = 1; //kalau ini berapa kali loncat atau grup
    Node* Decoy = head;
    while (Decoy->next != NULL)
    {
        total++;
        Decoy = Decoy->next;
    }
//printf("%d \n", total);
    int limit = 0;
    Node* help = (Node*)malloc(sizeof(Node));
    Node* Temp, *Last, *Destination, *Switcher, *Target;
    help->next = head;
    Decoy = head;
    Last = help;
    Temp = head;

    while (limit++ != total/k)
    {
        int step = 1;
        Switcher = Decoy->next;
        while (step++ != k)
        {
            Target = Decoy;
            Destination = Switcher->next;
            Decoy = Switcher;
            Switcher->next = Target;
            Switcher = Destination;
        }
        Last->next = Decoy;
        Temp->next = Destination;
        Last = Temp;
        if(Destination == NULL) break;
        Temp = Destination;
        Decoy = Destination;
    }
    return help->next;
    
}
        
        
            