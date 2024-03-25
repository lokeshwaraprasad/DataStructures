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





struct node* mul2(struct node* poly1, struct node* poly2) {
    struct node* head = NULL; 
    struct node* ptr1 = NULL; 
    struct node* temp = poly1;

       while (temp != NULL) {
        struct node* ptr2 = poly2; // Pointer to traverse poly2 for each term of poly1
        while (ptr2 != NULL) {
            // Create a new node to store the result of multiplication
            struct node* lp = (struct node*)malloc(sizeof(struct node));
            lp->co = temp->co * ptr2->co; // Multiply coefficients
            lp->exp = temp->exp + ptr2->exp; // Add exponents

            // Add the new node to the result polynomial
            if (head == NULL) {
                head = ptr1 = lp;
            } else {
                ptr1->next = lp;
                ptr1 = ptr1->next;
            }
            ptr2 = ptr2->next; // Move to the next term of poly2
        }
        temp = temp->next; // Move to the next term of poly1
    }
    if (head != NULL)
        ptr1->next = NULL; // Set the next of last node to NULL

    return head; // Return the head of the result polynomial
}
    

struct node* addPolynomials(struct node* poly1, struct node* poly2) {
    struct node* head = NULL; // Head of the result polynomial
    struct node* ptr = NULL; // Pointer to traverse result polynomial
   struct node* res = NULL; // Result polynomial

    // Iterate through polynomials until one or both become NULL
    while (poly1 != NULL || poly2 != NULL) {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        if (temp == NULL) {
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }

        // Add coefficients based on exponents
        if (poly1 == NULL) {
            temp->exp = poly2->exp;
            temp->co = poly2->co;
            poly2 = poly2->next;
        } else if (poly2 == NULL) {
            temp->exp = poly1->exp;
            temp->co = poly1->co;
            poly1 = poly1->next;
        } else if (poly1->exp > poly2->exp) {
            temp->exp = poly1->exp;
            temp->co = poly1->co;
            poly1 = poly1->next;
        } else if (poly2->exp > poly1->exp) {
            temp->exp = poly2->exp;
            temp->co = poly2->co;
            poly2 = poly2->next;
        } else { // poly1->exp == poly2->exp
            temp->exp = poly1->exp;
            temp->co = poly1->co + poly2->co;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        temp->next = NULL;

        if (head == NULL) {
            head = ptr = temp;
        } else {
            ptr->next = temp;
            ptr = ptr->next;
        }

        if (res == NULL) {
            res = head;
        }
    }

    return res;
}











struct node* subtractPolynomials(struct node* poly1, struct node* poly2) {
    struct node* head = NULL; // Head of the result polynomial
    struct node* ptr = NULL; // Pointer to traverse result polynomial
    struct node* res = NULL; // Result polynomial

    // Iterate through polynomials until one or both become NULL
    while (poly1 != NULL || poly2 != NULL) {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        if (temp == NULL) {
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }

        // Subtract coefficients based on exponents
        if (poly1 == NULL) {
            temp->exp = poly2->exp;
            temp->co = poly2->co;
            poly2 = poly2->next;
        } else if (poly2 == NULL) {
            temp->exp = poly1->exp;
            temp->co = poly1->co;
            poly1 = poly1->next;
        } else if (poly1->exp > poly2->exp) {
            temp->exp = poly1->exp;
            temp->co = poly1->co;
            poly1 = poly1->next;
        } else if (poly2->exp > poly1->exp) {
            temp->exp = poly2->exp;
            temp->co = -poly2->co;
            poly2 = poly2->next;
        } else { // poly1->exp == poly2->exp
            temp->exp = poly1->exp;
            temp->co = poly1->co - poly2->co;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        temp->next = NULL;

        if (head == NULL) {
            head = ptr = temp;
        } else {
            ptr->next = temp;
            ptr = ptr->next;
        }

        if (res == NULL) {
            res = head;
        }
    }

    return res;
}





int main()
{
    
    struct node *head,*poly1,*temp,*poly2,*head2,*head3;
    
    int n,m;
    
    
    int co,exp;
    
    printf("enter the number of terms in the first  polynomial expression:");
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
    printf("enter the valuse:\n");
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
        poly1->exp=exp;
        poly1->next = NULL;  

        temp->next = poly1; 
        temp = temp->next;    
    }
    
    traverse(head);
    
    printf("\n\n for 2nd polynomial");
     printf("enter the number of terms in the second  polynomial expression:");
    scanf("%d",&m);
       head2 = (struct node *)malloc(sizeof(struct node));

    
    if(head2 == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }


    
    printf("enter the value:\n");

    scanf("%d %d", &co,&exp);

    head2->co = co;
    head2->exp=exp;
    head2->next = NULL; 


    temp = head2;
    for(int i=2; i<=m; i++)
    {
        poly2 = (struct node *)malloc(sizeof(struct node));

        if(poly2 == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }

        
        scanf("\n%d %d", &co,&exp);

        poly2->co= co;
        poly2->exp=exp;
        poly2->next = NULL; 

        temp->next = poly2;
        temp = temp->next; 
    }
    traverse(head2);
    printf("\n");

    int op;
    printf("Enter 1 for addition \nEnter 2 for subtraction \n Enter 3 for Multiplication\n");
    scanf("%d",&op);
    switch(op)
    {
        case 1:
            head3=addPolynomials(head,head2);
            printf("\nthe resultant polynomial addition:\n");
            traverse(head3);
           break;

           case 2:
           head3=subtractPolynomials(head,head2);
            printf("\nthe resultant polynomial subtraction:\n");
            traverse(head3);
           break;

           case 3:
           head3=mul2(head,head2);
            printf("\nthe resultant polynomial Multiplication:\n");
            traverse(head3);
           break;
           default:
           printf("\n Invalid operation :");

    }
  
}