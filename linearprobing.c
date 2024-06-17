#include <stdio.h>

int tsize;

int hasht(int key) {
    return key % tsize;
}

//-------LINEAR PROBING-------
int rehashl(int index) {
    return (index + 1) % tsize;
}

//-------QUADRATIC PROBING-------
int rehashq(int index, int j) {
    return (index + j * j) % tsize;
}

int main() {
    int key, arr[20], hash[20], i, n, op, j, k;

    printf("Enter the size of the hash table: ");
    scanf("%d", &tsize);

    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < tsize; i++)
        hash[i] = -1;

    printf("Enter Elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n\n1. Linear Probing\n2. Quadratic Probing \n3. Exit \nEnter your option: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                for (i = 0; i < tsize; i++)
                    hash[i] = -1;

                for (k = 0; k < n; k++) {
                    key = arr[k];
                    i = hasht(key);
                    while (hash[i] != -1) {
                        i = rehashl(i);
                    }
                    hash[i] = key;
                }
                printf("\nThe elements in the hash table are: ");
                for (i = 0; i < tsize; i++) {
                    printf("\n  Element at position %d: %d", i, hash[i]);
                }
                break;

            case 2:
                for (i = 0; i < tsize; i++)
                    hash[i] = -1;

                for (k = 0; k < n; k++) {
                    j = 1;
                    key = arr[k];
                    i = hasht(key);
                    while (hash[i] != -1) {
                        i = rehashq(i, j);
                        j++;
                    }
                    hash[i] = key;
                }
                printf("\nThe elements in the hash table are: ");
                for (i = 0; i < tsize; i++) {
                    printf("\n  Element at position %d: %d", i, hash[i]);
                }
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    } while (op != 3);

    return 0;
}
