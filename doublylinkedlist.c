#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *insertion_begin(struct node *head,int data)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    
    newnode->prev=NULL;
    newnode->next=head;
    head->prev=newnode;
    
    return newnode;
}
struct node *insertion_last(struct node *head,int data)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    
    newnode->data=data;
    
    newnode->next=NULL;
    
    struct node *ptr=head;
    
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    
    ptr->next=newnode;
    newnode->prev=ptr;
    
    return head;
}


struct node *insertion_afterp(struct node *head,int data,int index)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    
    newnode->data=data;
    struct node *ptr=head;
    struct node *qtr=head->next;
    
    int i=0;
    
    while(i<index-1)
    {
        ptr=ptr->next;
        qtr=qtr->next;
        i++;
        
    }
    
    ptr->next=newnode;
    newnode->prev=ptr;
    newnode->next=qtr;
    
    return head;
    
    
}

struct node *delete_begin(struct node *head)
{
    struct node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

struct node *delete_end(struct node *head)
{
    struct node*ptr=head;
    struct node *qtr=head->next;
    
    while(qtr->next!=NULL)
    {
        ptr=ptr->next;
        qtr=qtr->next;
    }
    ptr->next=NULL;
    free(qtr);
    return head;
    
    
}

struct node *delete_index(struct node *head,int pos)

{
    
    int i=0;
    struct node *ptr=head;
    struct node *qtr=head->next;
    struct node *str=head->next->next;
    
    
    while(i<pos-1)
    {
        ptr=ptr->next;
        qtr=qtr->next;
        str=str->next;
        i++;
    }
    
    ptr->next=str;
    str->prev=ptr;
    
    free(qtr);
    return head;
}




void traverse(struct node *head)
{
    struct node *ptr=head;
    
    while(ptr!=NULL)
    {
        printf("%d-> ",ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    struct node *head,*n1,*n2;
    
    head=(struct node *)malloc(sizeof(struct node));
    n1=(struct node *)malloc(sizeof(struct node));
    n2=(struct node *)malloc(sizeof(struct node));
    
    head->data=1;
    head->prev=NULL;
    head->next=n1;
    
    n1->data=2;
    n1->prev=head;
    n1->next=n2;
    
     
    n2->data=3;
    n2->prev=n1;
    n2->next=NULL;
    printf("\n the created doubly linked list is:");
    traverse(head);
    
    int op;
    printf("\n AN PROGRAM THAT PERFORMS EVERY OPTOIONS OF DOUBLY LINKED LIST");
    
    printf("enter the option 1.insertion at begin\n2.insetion at end\n3.insertion after p\n4.traversal\n5.Delte at the begin\n6.delte at end\n7.delete at index\n");
    scanf("%d",&op);
    
    switch(op)
    {
        case 1:
         
    head=insertion_begin(head,69);
      
    printf("\n after insertoion\n");
    traverse(head);
    break;
    
    case 2:
    
     
    head=insertion_last(head,69);
      
    printf("\n after insertoion\n");
    traverse(head);
    break;
    
    case 3:
     
    head=insertion_afterp(head,69,1);
      
    printf("\n after insertoion\n");
    traverse(head);
    break;
    
    case 4:
    traverse(head);
    break;
    
    case 5:
    head=delete_begin(head);
    printf("\n after the deletion\n");
    traverse(head);
    break;
    
    case 6:
    head=delete_end(head);
    printf("\n after the deletion\n");
    traverse(head);
    break;
    
    case 7:
    head=delete_index(head,1);
    printf("\nafter the position deletion\n");
    traverse(head);
    break;
    
    }
    
    
    
}