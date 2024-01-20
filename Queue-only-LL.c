#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct Queue {
    struct node* front;
    struct node* rear;
};

struct Queue* CreateQue() {
    struct Queue* Qu = (struct Queue*)malloc(sizeof(struct Queue));
    Qu->front = Qu->rear = NULL;
    printf("Que Created succesfully");
    return Qu;
}

struct node* Newn(int k) {
    struct node* Newnode = (struct node*)malloc(sizeof(struct node));
    Newnode->data = k;
    Newnode->next = NULL;
    return Newnode;
}

void enQue(struct Queue* Qu, int k) {
    struct node* NewNode = Newn(k);
    if (Qu->front == Qu->rear && Qu->rear == NULL) {
        Qu->front = Qu->rear = NewNode;
    } else {
        Qu->rear->next = NewNode;
        Qu->rear = Qu->rear->next;
    }
}

int DeQue(struct Queue* Qu) {
    int val;
    if (Qu->front == Qu->rear && Qu->front == NULL) {
        printf("Queue is Empty\n");
        return -1;
    } else {
        struct node* temp = Qu->front;
        val = temp->data;
        Qu->front = Qu->front->next;
        free(temp);
        return val;
    }
}

int peek(struct Queue* Qu) {
    int val;
    if (Qu->front == Qu->rear && Qu->front == NULL) {
        printf("Queue is Empty\n");
        return -1;
    } else {
        val = Qu->front->data;
        return val;
    }
}

void printQ(struct Queue* Qu) {
    if (Qu != NULL) {
        struct node* ptr = Qu->front; // Use a temporary pointer to traverse the queue
        while (ptr != NULL) {
            printf("%d->", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}


void menu() {
    struct Queue* queue = NULL;
    int choice, value;

    do {
        printf("\nQueue Menu:\n");
        printf("1. Create Queue\n");
        printf("2. Enqueue\n");
        printf("3. Dequeue\n");
        printf("4. Peek\n");
        printf("5. Print Queue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                queue = CreateQue();
                break;
            case 2:
                if (queue == NULL) {
                    printf("Create a queue first.\n");
                } else {
                    printf("Enter value to enqueue: ");
                    scanf("%d", &value);
                    enQue(queue, value);
                }
                break;
            case 3:
                if (queue == NULL) {
                    printf("Create a queue first.\n");
                } else {
                    value = DeQue(queue);
                    if (value != -1) {
                        printf("Dequeued value: %d\n", value);
                    }
                }
                break;
            case 4:
                if (queue == NULL) {
                    printf("Create a queue first.\n");
                } else {
                    value = peek(queue);
                    if (value != -1) {
                        printf("Front of the queue: %d\n", value);
                    }
                }
                break;
            case 5:
                if (queue == NULL) {
                    printf("Create a queue first.\n");
                } else {
                    printQ(queue);
                }
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}
