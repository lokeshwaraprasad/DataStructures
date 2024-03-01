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

struct node *insertbetwwen(struct node*head,int data,int index)
{
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p=head;
        int i=0;
        while(i!=index-1){
            p=p->next;
            i++;
        }
        ptr->data=data;
        ptr->next=p->next;
        p->next=ptr;
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

      traversal(head);
    insertbetwwen(head,890,2);
    printf("\n\n");
    traversal(head);

    
}