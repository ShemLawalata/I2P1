#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left, *right;
} Node;

void Insert(Node** root, int src);
void Print(Node* root);
void Print_2(Node* root);

int main() {
    
    char str[50];
    
    Node* root = NULL;
    
    while (scanf("%s", str) != EOF) {
        if (!strcmp(str, "Insert")) {
            int num;
            scanf("%d", &num);
            
            Insert(&root, num);
        } else if (!strcmp(str, "Print")){
            Print(root);
        }
    }
}

void Insert(Node** root, int src)
{
    //Create
    if((*root) == NULL)
    {
        Node* temp;
        temp = (Node*) malloc(sizeof(Node));
        temp->val = src;
        temp->left = temp->right = NULL;
        (*root) = temp;
        return;
    }
//Kanan
    if (src > (*root)->val)
    {
        Insert(&((*root)->right), src);
         //Karna (*root)->right) adalah pointer jadi kita harus kasih adressnya utk assign ke double pointer
    }
//Kiri
    else if (src < (*root)->val)
    {
        Insert(&((*root)->left), src);
       // (*root)->left = Insert(&((*root)->left), src); Gabisa karna return valuenya void, Konsepnya adalah dia langsung bawa pointernya di assign kalau yg di ppt kita buat barangnya baru kita bawa balik terus assign jd lbih ma huan
    }
//Sama or done
    return;
}

void Print(Node* root)
{
    if (root == NULL) return;

    printf("%d", root->val);
    Print_2(root->left);
    Print_2(root->right);
    printf("\n");
    // Print(root->left);
    // Print(root->right);
    
}

void Print_2(Node* root)
{
    if (root == NULL) return;
    printf(" %d", root->val);
    Print_2(root->left);
    Print_2(root->right);
}