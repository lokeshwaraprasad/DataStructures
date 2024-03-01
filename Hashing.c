#include <stdio.h>

#define SIZE 10

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Function to insert a key into the hash table
void insert(int hashTable[], int key) {
    int index = hash(key);
    
    // Linear probing to handle collisions
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
}

// Function to search for a key in the hash table
int search(int hashTable[], int key) {
    int index = hash(key);
    
    // Linear probing to handle collisions
    while (hashTable[index] != key && hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }

    if (hashTable[index] == key) {
        return index; // Found
    } else {
        return -1; // Not found
    }
}

int main() {
    int hashTable[SIZE];
    
    // Initialize hash table with -1
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    // Insert some keys
    insert(hashTable, 5);
    insert(hashTable, 25);
    insert(hashTable, 15);
    insert(hashTable, 35);

    // Search for keys
    int key = 15;
    int index = search(hashTable, key);
    if (index != -1) {
        printf("Key %d found at index %d\n", key, index);
    } else {
        printf("Key %d not found\n", key);
    }

    key = 20;
    index = search(hashTable, key);
    if (index != -1) {
        printf("Key %d found at index %d\n", key, index);
    } else {
        printf("Key %d not found\n", key);
    }

    return 0;
}

