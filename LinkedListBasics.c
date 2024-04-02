#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int x;
    struct node *next;
} Node;

int main(void)
{
    Node head;
    head.x = 0;
    head.next = (Node*) malloc(sizeof(Node));
    Node *np, *nq;
    int i;

    np = head.next; //head.next kan itu pointer nah si np kan juga pointer jadi okelah terus dia bisa access nialinya pakai ->
    i = 1;
    while (i < 10)
    {
        np -> x = i;
        np ->next = (Node*) malloc (sizeof(Node));
        np = np->next;
        i++;
    }
    np ->x = i;
    np ->next = NULL; //Tail or end set to NULL

    np = head.next;
    while (np != NULL)
    {
        printf("%d\n", np ->x);
        np = np ->next;
    }
    
    np = head.next;
    while (np != NULL)
    {
        nq = np ->next;
        free(np);
        np = nq;
    }
    return 0;
}