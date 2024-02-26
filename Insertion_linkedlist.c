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

struct node *insertionatfirst(struct node *head,int data)
{
  struct node *ptr=(struct node*)malloc(sizeof(struct node));
  ptr->next=head;
  ptr->data=data;
  return ptr;
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

      traversal(head);
      head=insertionatfirst(head,111);
      printf("\n");
      traversal(head);


    
}