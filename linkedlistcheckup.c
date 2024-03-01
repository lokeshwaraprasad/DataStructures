#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

int createlist(int n)
{

    if(n==0)
    {
        printf("the linked list has no nodes:");
        return 0;
    }
    else{

    
    struct node *head,*ptr,*new;
     head=(struct node*)malloc(sizeof(struct node));
     new=(struct node*)malloc(sizeof(struct node));
     ptr=(struct node*)malloc(sizeof(struct node));

     printf("enter the data for the head node");
     scanf("%d",&head->data);
     head->next=NULL;

     if(head==NULL)
     {
        printf("\nthere is no headn node therefore thr linked list is empty");
        return 0;
     }

    }
}

int main()
{
    int n;
    printf("enter the number of node:");
    scanf("%d",&n);
  createlist(n);

}
