#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

//Find a node 
TreeNode* Find(TreeNode *node, int data)
{
    if(node == NULL) // not found
        return NULL;

    if(data > node->data)
        return Find(node->right, data);
    else if(data < node->data)
        return Find(node->left, data);
    else //found Nilainya sama
        return node;
}

// Search BST

TreeNode* FindMin(TreeNode *node)
{
    // There is no element in the tree
    if(node == NULL) {
        return NULL;
    }

    // Go to the left sub tree to find the min element 
    if(node->left)
        return FindMin(node->left);
    else
        return node;
}

TreeNode* FindMax(TreeNode *node)
{
    if(node == NULL) {
        return NULL;
    }

// Dia cari sampai pojok paling kanan kalau misalnya masih ada element past dieksekusikan
// Nah ketika tree node righntnya itu NULL brti dia sudah jadi nilai paling max
    if(node->right) 
        FindMax(node->right);
    else
        return node;
}

//Insert a Node
TreeNode* Insert(TreeNode *node, int data)
{
 	if(node == NULL) // create a temp node for storing data element
    	{
        		TreeNode *temp;
        		temp = (TreeNode *)malloc(sizeof(TreeNode));
        		temp -> data = data;
        		temp -> left = temp -> right = NULL;
        		return temp;
    	}

    if(data > (node->data) ) 
	{
        		node->right = Insert(node->right, data);
	}
 	else if(data < (node->data)) 
	{
        		node->left = Insert(node->left, data);
	}

            // Else there is nothing to do as the data is already in the tree.
	return node;
}

//Delete
TreeNode* Delete(TreeNode *node, int data)
{
 	TreeNode *temp;
    	
    if(node == NULL) 
	{
        printf("Element Not Found");
    }
    
    //Kita pakai "=" untuk kepp track semua cabang karena kita pakai pointer
    else if(data < node->data) 
	{
        node->left = Delete(node->left, data);
    }      
    
    else if(data > node->data) 
	{
        node->right = Delete(node->right, data);
   	}

    else // data == node->data //Ketemu yang mau kita hapus
    {
        /* Now we can delete this node and replace with either minimum element
       	in the right sub tree or maximum element in the left subtree */

        // ^ ^ ^ penjelasan di atas make sense karena kita cari max di kiri dia akan tetap akan lebih kecil yang di kanan tapi kalau ketemu yang lebih kecil pasti ke kiri

        // \/ di bawah ini kalau dia ada cabang kiri kanan kan harus cari yang mana mau kita naikin ke new root dan hapus yg redundance  dengan tetap terhubung 
        if(node->right && node->left)
        {
            // replace this node with minimum element in the right sub tree
            //Jadi kita cuma ganti valuenya aja bukan hapus nodenya

            temp = FindMin(node->right);
            node -> data = temp->data;

            // As we replaced it with some other node, we have to delete that node
            //Supaya ngga redundance
            // OOOHHH KARENA DIA MIN OR MAX jadinya anakkannya pasti NULl jdi di function elsenya dia di hapus
            node -> right = Delete(node->right, temp->data);
        }
        
        else
        {
            // only 1 or 0 children atau yang temp operan yang mau dihapus
            // directly remove it from the tree and connect its parent to its child
            temp = node;

            // langsung hubungin jadi ga putus

            if(node->left == NULL)
            node = node->right;
            
            else if(node->right == NULL)
            node = node->left;
            //Kalau keduanya NULL dia tetap bakalan terhubung dengan NULL

            free(temp); // temp is longer required
        }
    }
    return node;
}

void PrintInorder(TreeNode *node)
{
    if(node == NULL) {
        return;
    }
//Paham
    PrintInorder(node->left);
    printf("%d ", node->data);
    PrintInorder(node->right);
}

void PrintPreorder(TreeNode *node)
{
    if(node == NULL) {
        return;
    }

    printf("%d ", node->data);
    PrintPreorder(node->left);
    PrintPreorder(node->right);
}

void PrintPostorder(TreeNode *node)
{
    if(node == NULL) {
        return;
    }

    PrintPostorder(node->left);
    PrintPostorder(node->right);
    printf("%d ", node->data);
}

int main()
{
    TreeNode *root = NULL;
    root = Insert(root, 5);
    root = Insert(root, -1);
    root = Insert(root, 3);
    root = Insert(root, -14);
    root = Insert(root, 8);
    root = Insert(root, 10);
    root = Insert(root, 9);
    root = Insert(root, 6);
    PrintInorder(root);
    printf("\n");

    root = Delete(root, 5);
    root = Delete(root, -1);
    PrintInorder(root);
    printf("\n");

    TreeNode *temp;
    temp = FindMin(root);
    printf("Minimum element is %d\n", temp->data);

     temp = FindMax(root);
    printf("Maximum element is %d\n", temp->data);

    temp = Find(root, 8);
    if(temp == NULL) {
        printf("Element 8 not found\n");
    }
    else {
        printf("Element 8 Found\n");
    }

    temp = Find(root, 2);
    if(temp == NULL) {
        printf("Element 2 not found\n");
    }
    else {
        printf("Element 2 Found\n");
    }

    return 0;
}
