#include <stdio.h>

#define SIZE 10

// Hash table size
#define TABLE_SIZE 10

// Hash table
int hashTable[TABLE_SIZE] = {-1};

// Function to calculate the hash index using linear probing
int linearProbe(int key) {
    return key % TABLE_SIZE;
}

// Function to insert a key into the hash table using linear probing
void insert(int key) {
    int index = linearProbe(key);

    if (hashTable[index] == -1) {
        // If the slot is empty, insert the key
        hashTable[index] = key;
        printf("Key %d inserted at index %d.\n", key, index);
    } else {
        // If the slot is occupied, find the next available slot using linear probing
        while (hashTable[index] != -1) {
            index = (index + 1) % TABLE_SIZE;
        }
        hashTable[index] = key;
        printf("Key %d inserted at index %d after linear probing.\n", key, index);
    }
}

// Function to search for a key in the hash table using linear probing
void search(int key) {
    int index = linearProbe(key);

    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            printf("Key %d found at index %d.\n", key, index);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    }

    printf("Key %d not found in the hash table.\n", key);
}

// Function to display the contents of the hash table
void display() {
    printf("Hash Table: ");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1) {
            printf("[%d:%d] ", i, hashTable[i]);
        } else {
            printf("[ ] ");
        }
    }
    printf("\n");
}

int main() {
    int choice, key;

    do {
        // Display menu
        printf("\nLinear Probing Implementation\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on user choice
        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
