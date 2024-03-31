#include<stdio.h>
#include<stdlib.h>

struct queue{
    int f;
    int r;
    int size;
    int *arr;
};
int dequeue(struct queue *q) {
    int a = -1;
        q->f++;
        a = q->arr[q->f];
    return a;
}

int isempty(struct queue *q) {
    if (q->r == q->f) {
        return 1;
    } else {
        return 0;
    }
}

void traversal(struct queue *q)
{
    while(q->r!=-1)
    {
        printf("%d ",q->arr[q->r]);
        q->r--;
    }
}

int isfull(struct queue *q)
{
    if(q->r==q->size-1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q,int val)
{
    if(isfull(q))
    {
        printf("\n the queue overflows");
    }
    else{
        q->r++;
        q->arr[q->r]=val;
    }
}

int main()
{

    struct queue *q;

    printf("\n ENter the size of the queue to be created");
    scanf("%d",&q->size);
    q->f=q->r=-1;

    q->arr=(int *)malloc(q->size *sizeof(int));
      
      int op;
      int val;
      printf("enter 0 to stop the enqueue process:");
      printf("\n enter the ch0ice");
          scanf("%d",&op);
      while(op!=0)
      {
          printf("\n enter the value to be inserted in the queue:");
          scanf("%d",&val);
          enqueue(q,val);

          printf("\n enter the ch0ice");
          scanf("%d",&op);
      }

      int us;
      
do
{
    printf("\n1.to check the queue is full\n2.the queue is empty\n3.dequueue\n4.traversal\n");
    scanf("%d",&us);
    switch(us)
    {
        case 1:
             if(isfull(q))

             {
         printf("the queue is full");

             }  
             else{
                printf("\n the queue is not full");
             } 
             break;
             case 2:
             if(isempty(q))
             {
                printf("\n the queue is empty");
             }
             else{
                printf("the quueue is not empty");
             }
             break;

             case 3:
                printf("the dequed element is %d",dequeue(q));
                break;
            case 4:
            traversal(q);
            break;

 }

 printf("Enter 0 to stop performing the operation:");
 scanf("%d",&us);
} while (us!=0);


}