#include <stdio.h>

#define MAX_SIZE 5

// Global variables
int circularQueue[MAX_SIZE];
int front = -1, rear = -1;


// Function to enqueue an element into the circular queue
void enqueue(int value) {
    if (((rear +1 )% MAX_SIZE)==front) {
        printf("Queue Overflow: Cannot enqueue element, queue is full.\n");
    } else {
        if (front ==-1 && rear ==-1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        circularQueue[rear] = value;
        printf("%d enqueued into the queue.\n", value);
    }
}

// Function to dequeue an element from the circular queue
void dequeue() {
    if (front==-1 && rear==-1) {
        printf("Queue Underflow: Cannot dequeue element, queue is empty.\n");
    } else {
        printf("%d dequeued from the queue.\n", circularQueue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }
}

// Function to display the elements of the circular queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Elements in the queue: ");
        int i = front;
       for ( i =  front ; i < ((rear+1) % MAX_SIZE) ; i++){
        printf(" %d " , circularQueue[i]);
       }
    }
}

int main() {
    int choice, value;

    do {
        // Display menu
        printf("\nCircular Queue Implementation using Array\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on user choice
        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
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
