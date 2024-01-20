#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list node
struct node {
    int data;
    struct node* Next;
};

// Declare the global top pointer
struct node* Top;
struct node* start;

// Function to push an element onto the stack
void push(int value) {
    struct node* Newnode;
    Newnode = (struct node*)malloc(sizeof(struct node));
    if (Newnode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    Newnode->data = value;
    Newnode->Next = NULL;

    if (start == NULL || Top == NULL) {
        start = Newnode;
        Top = start;
    } else {
        struct node* pre = start;
        while (pre->Next != NULL) {
            pre = pre->Next;
        }
        pre->Next = Newnode;
        Top = pre->Next;
    }
}

// Function to pop an element from the stack
int pop() {
    int val;
    if (start == NULL || Top == NULL) {
        printf("Stack is empty, create one\n");
        return -1; // Return a sentinel value to indicate an error or empty stack
    } else {
        struct node* ptr;
        struct node* pre = NULL;
        ptr = start;
        while (ptr->Next != NULL) {
            pre = ptr;
            ptr = ptr->Next;
        }
        // if (pre != NULL) {
        //     pre->Next = NULL;
        // } else {
        //     start = NULL; // Set start to NULL if there was only one element in the stack
        // }
        val = Top->data;
        Top = pre;
        Top->Next=NULL ;
        free(ptr);
    }

    return val;
}

// Function to peek at the top of the stack
int peek() {
    int val;
    if (start == NULL || Top == NULL) {
        printf("Stack is empty, create one\n");
        return -1; // Return a sentinel value to indicate an error or empty stack
    } else {
        // struct node* ptr;
        // ptr = start;
        // // while (ptr != Top) {
        // //     ptr = ptr->Next;
        // // }
        val = Top->data;
    }
    return val;
}

// Function to print the elements of the stack
void printStack(struct node* start) {
    printf("Stack: ");
    struct node* ptr = start ;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->Next;
    }
    printf("NULL\n");
}

// Main menu function
 
int main() {
       int choice, value;

    do {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Print Stack\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("Top of the stack: %d\n", value);
                }
                break;
            case 4:
                printStack(start);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);


    return 0;
}
