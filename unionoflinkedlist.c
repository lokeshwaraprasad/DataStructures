#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void traversal(struct node *ptr) {
    while(ptr != NULL) {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
}

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* listUnion(struct node* l1, struct node* l2) {
    struct node *head = NULL;
    struct node *tail = NULL;
    struct node *temp;

    // Traverse first list and add nodes to the union list
    temp = l1;
    while (temp != NULL) {
        struct node *newNode = createNode(temp->data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        temp = temp->next;
    }

    // Traverse second list and add nodes to the union list if not already present
    temp = l2;
    while (temp != NULL) {
        struct node *current = head;
        int found = 0;
        while (current != NULL) {
            if (current->data == temp->data) {
                found = 1;
                break;
            }
            current = current->next;
        }
        if (!found) {
            struct node *newNode = createNode(temp->data);
            if (head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        temp = temp->next;
    }

    return head;
}

int main() {
    struct node *head1, *n1, *n2, *n3, *n4;
    struct node *head2, *m1, *m2, *m3, *m4;

    // Creating first linked list
    head1 = createNode(1);
    n1 = createNode(2);
    n2 = createNode(3);
    n3 = createNode(4);
    n4 = createNode(6);
    head1->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    // Creating second linked list
    head2 = createNode(89);
    m1 = createNode(25);
    m2 = createNode(38);
    m3 = createNode(489);
    m4 = createNode(68);
    head2->next = m1;
    m1->next = m2;
    m2->next = n3; // Shared node between lists
    m3->next = m4;

    // Printing the first list
    printf("\nThe first list is:\n");
    traversal(head1);

    // Printing the second list
    printf("\nThe second list is:\n");
    traversal(head2);

    // Calculating and printing the union of the lists
    struct node *head3 = listUnion(head1, head2);
    printf("\nThe union is:\n");
    traversal(head3);

    return 0;
}
