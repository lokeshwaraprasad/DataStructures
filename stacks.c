#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;

};

int isempty(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    else
    return 0;
}

int main()
{
    struct stack *s;
     s->size=6;
     s->top=-1;
     s->arr=(int *)malloc(s->size*sizeof(int));


     //manually giving data for the stacks

     s->arr[0]=89;
     s->top++;

     //function to check whether the stack is empty

     if(isempty(s))
{
    printf("the stack is empty");
}
else{
    printf("the stack is not empty");
}

}