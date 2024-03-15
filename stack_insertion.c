#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;

};

int isfull(struct stack *ptr)
{
   if(ptr->top==ptr->size-1)
   {
    return 1;
   }
   else{
    return 0;
   }
}
int isempty(struct stack *q)
{
  if(q->top==-1)
  {
    return 1;
  }
  else{
    return 0;
  }
}
//push
void push(struct stack *ptr,int val)
{
    if(isfull(ptr))
    {
        printf("\nthe stack overflows:\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

int main()
{
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr=(int *)malloc(sp->size*sizeof(int));
    printf("\n the stack is created succesfully\n");
 
push(sp,69);
push(sp,69);
push(sp,69);
push(sp,69);
push(sp,69);
push(sp,69);
push(sp,69);
push(sp,69);
push(sp,69);
push(sp,69);
//is epty and is full function calls impliuwmnetation
if(isempty(sp))
{
    printf("the stack is empty\n");

}
else{
    printf("the stack is full");
}
if(isfull(sp))
{
    printf("the stack is Full");

}
else{
    printf("the stack is Not full yet");
}


}
