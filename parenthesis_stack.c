#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char *arr;

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

int isempty(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    else
    return 0;
}
void push(struct stack *p,char val )
{
    if(isfull(p))
    {
        printf("\nsTACK OVERFLOWS");
    }
    else{
        p->top++;
        p->arr[p->top]=val;
    }
}
char pop(struct stack *sp)
{
    if(isempty(sp))
    {
        printf("\n Stac underflows");
        return -1;
    }
    else{
        char val=sp->arr[sp->top];
        sp->top--;
        return val;
    }
}
int parenthesismatch(char *exp)
{
    struct stack *sp;
    sp->size=100;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size*sizeof(char));
    
    for(int i=0;exp[i]!='\0';i++)
    {
          if(exp[i]=='(')
          {
                   push(sp,'(');
          }
          else if (exp[i]==')')
          {
            if(isempty(sp))
            {
                return 0;
            }
            pop(sp);

          }
    }
   if(isempty(sp))
   {
    return 1;
   } 
   else{
    return 0;
   }
}

int main()
{
    char *exp="8*(9))";

    if(parenthesismatch(exp))
    {
  printf("\nparenthesis is matching");
    }
    else{
 printf("\n parenthesis is not matching");
    }
    return 0;
}