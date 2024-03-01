#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

void traversal(struct node *ptr)
{
    while(ptr!=NULL)
    {
    printf("the elemnt:%d->",ptr->data);
    ptr=ptr->next;

    }
}

struct node *insertionatend(struct node*head,int data)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    struct node *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
        
    }
    p->next=ptr;
    ptr->next=NULL;

    return head;

}
int main()
{
    struct node *head,*second,*third;
    head=(struct node*)malloc(sizeof(struct node));
     second=(struct node*)malloc(sizeof(struct node));
      third=(struct node*)malloc(sizeof(struct node));

      head->data=90;
      head->next=second;

      //second

      second->data=69;
      second->next=third;
      //thired

      third->data=789;
      third->next=NULL;

      //traversal(head);
      

      insertionatend(head,1090);
      printf("the linked list after the insertion at end:\n");
      traversal(head);

    
}