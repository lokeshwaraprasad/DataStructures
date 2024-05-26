#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void traverse(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

struct node *rotate(struct node *head) {
    if (head == NULL || head->next == NULL) {
        return head; 
    }

    struct node *new_head = head->next; 
    struct node *ptr = head;

    
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }


    ptr->next = head;
    head->next = NULL; 

    return new_head; 
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *n1 = (struct node *)malloc(sizeof(struct node));
    struct node *n2 = (struct node *)malloc(sizeof(struct node));
    struct node *n3 = (struct node *)malloc(sizeof(struct node));
    struct node *n4 = (struct node *)malloc(sizeof(struct node));

    head->data = 1;
    head->next = n1;

    n1->data = 2;
    n1->next = n2;

    n2->data = 3;
    n2->next = n3;

    n3->data = 4;
    n3->next = n4;

    n4->data = 5;
    n4->next = NULL;

    printf("Original list: ");
    traverse(head);


    
    int n;
    
    printf("Enter the number of times the linked list to be cycled/rotatedf:");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        head=rotate(head);
    }
    printf("Rotated list: ");
    traverse(head);

  
}