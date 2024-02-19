#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;

};


int main()
{
    struct  node *head,*newnode,*temp;
     head=0;
int choice=1;
printf("Program for linked list");

while(choice)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data");
    scanf("%d",&newnode->data);

    newnode->next=0;
    if(head==0)
    {
        head=temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }

    printf("do you wanna create an linked list and continue the process of creating");
    printf("\n");
printf("for yes select 1 for no select 0 :");
scanf("%d",&choice);
}

temp=head;
while(temp!=0)
{
    printf("%d->",temp->data);
    temp=temp->next;

}
}
