#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    int idx;
    struct node* next;
} Node;

void AddFront(Node** head, Node** back, int num);
void AddBack(Node** head, Node** back, int num);
void DeleteFront(Node** head, Node** back);
void Delete(Node** head, Node** back, int num);
void Swap(Node** head, Node** back); //3 Pointer track to change the directions //Reverse Linked list


int main()
{
    char str[50];
    
    Node* head = (Node*) malloc(sizeof(Node));
    Node* back = head;
    // initialize the dummy head
    
    // we'll append the element after this dummy head to avoid runtime error.
    head->idx = -1;
    head->next = NULL;
    
    while (scanf("%s", str) != EOF) {
        
        int num;
        
        if (!strcmp(str, "AddFront")) {
            scanf("%d", &num);
            AddFront(&head, &back, num);
        }
        else if (!strcmp(str, "AddBack")) {
            scanf("%d", &num);
            AddBack(&head, &back, num);
        }
         else if (!strcmp(str, "DeleteFront")) {
             DeleteFront(&head, &back);
        }
        else if (!strcmp(str, "Delete")) {
            scanf("%d", &num);
            Delete(&head, &back, num);
        }
        else if (!strcmp(str, "Swap")) {
            Swap(&head, &back);
        }
    }
    
    // print all the element except the dummy head and free them.
    Node* print = head;
         
    if (head->next == NULL) printf("empty\n");
    
    while (print != NULL) {
        if (print->idx != -1)
            printf("%d%c", print->idx, (print->next == NULL ? '\n' : ' '));
        
        Node* del = print;
        print = print->next;
        free(del);
    }
}

void AddFront(Node** head, Node** back, int num) //Just add in the front
{
    Node* medium = (Node*)malloc(sizeof(Node));
    Node* temp = (*head) -> next;
    (*head)->next = medium;
    medium->idx = num;
    medium->next = temp;
    if (temp == NULL) *back = medium; //Jadiin back sebagai last element;
}

void AddBack(Node** head, Node** back, int num) //Back is your LAST NODE!!!!!!!!
{
    //Updare your fakin Back, not repeating the same progress
    Node* temp, *temp2; //LAst one should point to the NULL
    Node* medium = (Node*)malloc(sizeof(Node));
    //if(*back == *head) 
    //{  
        //Let head point to medium
       //(*head)->next = medium;

       temp = *back;
       temp->next = medium;
       medium->idx = num;
       medium->next = NULL;
       *back = medium; 
    
    //} 
}

void DeleteFront(Node** head, Node** back)
{
    if ((*head)->next == NULL) return;
    Node* temp = (*head)->next->next;
    (*head)->next->idx = 0;
    free((*head)->next);
    //(*head)->idx = 0; Kalau ini kau sentuh dummyy headnya jadi bahaya dan gaboleh
    (*head)->next = temp;
}

void Delete(Node** head, Node** back, int num)
{
    Node* Linker;
    Node* Decoy = (*head);
    Node* temp;
    if (Decoy->next == NULL) return;
    else
    {
        while (Decoy->next != NULL )
        {
            Linker = Decoy->next->next;
            if (Decoy->next->idx == num)//Using decoy to track all the chain
            {

                //Check if it is NULL ptr, kalau NUll berarti kita sudah di last element
                Decoy->next->idx = 0;
                temp = Decoy->next;
                free(temp);
                Decoy->next = Linker;
                //Decoy = Linker; //harusnya dia udh adress Karena kita mau cek lagi selanjutnya sama apa ngga, kalau misalnya sama terus kita jalanin inikan berarti dia skip yg di tengah
            }
            // Decoy->next = Decoy->next;
            //Bukan Num
            else {
                Decoy = Decoy->next; // Tadikan kau buat ke linker jadi dia skip 1 element & dia juga memungkinkan linker point ntah kemana jadi segfault!

                //if (Linker == NULL) *back = Decoy;
                //Decoy sekarang ya sekarang 1
                //Decoy->next itu bubble nextnya 2
                //Decoy->next->next bubble stelah bubblenya 3
            }
        }
             *back = Decoy;
    }
    return;
}

void Swap(Node** head, Node** back) //start dari node kedua aja baru pas terakhir back arahkan ke NULL
{
    Node *Target, *Decoy, *Temp, *Switcher; //Decoy utk control pergerakan
    
    if((*head)->next == NULL) return;
    else{
        *back = (*head)->next;
        Decoy = (*head)->next;
        Switcher = (*head)->next->next;
            //printf("%d swtch to %d\n", Switcher->idx, Target->idx);
        while (Switcher != NULL)
        {
            Target = Decoy; //Target yang mau switch direction
            Temp = Switcher->next; //simpan alamat utk iteration
            //Kepp Track 
            Decoy = Switcher;
            //Start Switching
            Switcher->next = Target; //Switch
            //Pindah posisi
            Switcher = Temp;

        }
        (*back)->next = NULL;
        (*head)->next = Decoy;
    }
}