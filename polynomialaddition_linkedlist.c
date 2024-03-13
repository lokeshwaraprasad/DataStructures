#include<stdio.h>
#include<stdlib.h>

struct node {
    int co;
    int exp;
    struct node *next;
    
};

void traverse(struct node *head)
{
     struct node *ptr=head;
    
    while(ptr!=NULL)
    {
        printf("%dx^%d",ptr->co,ptr->exp);
        ptr=ptr->next;
        if (ptr != NULL)
            printf("+ ");
    }
}








struct node * addsdjwoijf(struct node *poly1,struct node *poly2)
{
    printf("it came::");
    struct node *head,*ptr,*res;
    head=0;
    res=(struct node *)malloc(sizeof(struct node));
    while(poly1!=NULL &&poly2!=NULL)
    {
        if(poly1->exp > poly2->exp)
        {
            res->exp=poly1->exp;
            res->co=poly1->co;
            res->next=NULL;
            if(head==0)
            {
                head=res=ptr;
            }
            else
            {
                ptr->next=res;
                ptr=ptr->next;
            }
            poly1=poly1->next;
        }
        
        else if(poly2->exp > poly1->exp)
        {
            res->exp=poly2->exp;
            res->co=poly2->co;
            res->next=NULL;
            if(head==0)
            {
                head=res=ptr;
            }
            else
            {
                ptr->next=res;
                ptr=ptr->next;
            }
            poly2=poly2->next;
        }
        
        else
        {
            res->co=poly1->co+poly2->co;
            res->exp=poly1->exp;
            res->next=NULL;
              if(head==0)
            {
                head=res=ptr;
            }
            else
            {
                ptr->next=res;
                ptr=ptr->next;
            }
            poly1=poly1->next;
            poly2=poly2->next;
        }
        
    
    }
    return head;
}

struct node * add(struct node *poly1, struct node *poly2)
{
    struct node *head = NULL, *ptr = NULL, *res = NULL;

    while (poly1 != NULL && poly2 != NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        if (temp == NULL)
        {
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }

        if (poly1->exp > poly2->exp)
        {
            temp->exp = poly1->exp;
            temp->co = poly1->co;
            poly1 = poly1->next;
        }
        else if (poly2->exp > poly1->exp)
        {
            temp->exp = poly2->exp;
            temp->co = poly2->co;
            poly2 = poly2->next;
        }
        else
        {
            temp->exp = poly1->exp;
            temp->co = poly1->co + poly2->co;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        temp->next = NULL;

        if (head == NULL)
        {
            head = ptr = temp;
        }
        else
        {
            ptr->next = temp;
            ptr = ptr->next;
        }

        if (res == NULL)
        {
            res = head;
        }
    }

    // Add remaining terms of poly1
  /*  while (poly1 != NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        if (temp == NULL)
        {
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        temp->exp = poly1->exp;
        temp->co = poly1->co;
        poly1 = poly1->next;
        temp->next = NULL;
        ptr->next = temp;
        ptr = ptr->next;
    }

    // Add remaining terms of poly2
    while (poly2 != NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        if (temp == NULL)
        {
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        temp->exp = poly2->exp;
        temp->co = poly2->co;
        poly2 = poly2->next;
        temp->next = NULL;
        ptr->next = temp;
        ptr = ptr->next;
    }*/

    return head;
}


int main()
{
    
    struct node *head,*poly1,*temp,*poly2,*head2,*head3;
    
    int n,m;
    
    
    int co,exp;
    
    printf("enter the number of terms in the polynomial expression:");
    scanf("%d",&n);
       head = (struct node *)malloc(sizeof(struct node));
      // head2 = (struct node *)malloc(sizeof(struct node));

    // Terminate if memory not allocated
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }


    // Input data of node from the user
    printf("enter the va;luse:\n");
//printf("Enter the data of node 1: ");
    scanf("%d %d", &co,&exp);

    head->co = co;
    head->exp=exp;// Link data field with data
    head->next = NULL; // Link address field to NULL


    // Create n - 1 nodes and add to list
    temp = head;
    for(int i=2; i<=n; i++)
    {
        poly1 = (struct node *)malloc(sizeof(struct node));

        /* If memory is not allocated for newNode */
        if(poly1 == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }

        //printf("Enter the data of node %d: ", i);
        scanf("\n%d %d", &co,&exp);

        poly1->co= co;
        poly1->exp=exp;// Link data field of newNode
        poly1->next = NULL; // Make sure new node points to NULL 

        temp->next = poly1; // Link previous node with newNode
        temp = temp->next;    // Make current node as previous node
    }
    
    traverse(head);
    
    printf("\n\n for 2nd polynomial");
     printf("enter the number of terms in the polynomial expression:");
    scanf("%d",&m);
       head2 = (struct node *)malloc(sizeof(struct node));

    // Terminate if memory not allocated
    if(head2 == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }


    // Input data of node from the user
    printf("enter the va;luse:\n");
//printf("Enter the data of node 1: ");
    scanf("%d %d", &co,&exp);

    head2->co = co;
    head2->exp=exp;// Link data field with data
    head2->next = NULL; // Link address field to NULL


    // Create n - 1 nodes and add to list
    temp = head2;
    for(int i=2; i<=m; i++)
    {
        poly2 = (struct node *)malloc(sizeof(struct node));

        /* If memory is not allocated for newNode */
        if(poly2 == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }

        //printf("Enter the data of node %d: ", i);
        scanf("\n%d %d", &co,&exp);

        poly2->co= co;
        poly2->exp=exp;// Link data field of newNode
        poly2->next = NULL; // Make sure new node points to NULL 

        temp->next = poly2; // Link previous node with newNode
        temp = temp->next;    // Make current node as previous node
    }
    traverse(head2);
    printf("\n");
   head3= add(head,head2);
   printf("\nthe resultant polynomial addition:\n");
   traverse(head3);
}