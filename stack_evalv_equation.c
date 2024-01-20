#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

// Global variables
int stack[MAX_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow: Cannot push element, stack is full.\n");
        exit(EXIT_FAILURE);
    } else {
        top++;
        stack[top] = value;
    }
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow: Cannot pop element, stack is empty.\n");
        exit(EXIT_FAILURE);
    } else {
        return stack[top--];
    }
}

// Function to evaluate a prefix expression
int evaluatePrefix(char expression[]) {
    int i, operand1, operand2, result;
    int len= strlen(expression);

    for (i = len - 1; i >= 0; i--) {

        if (isdigit(expression[i])) {
            push(expression[i] - '0');


        } else if (expression[i] != ' ') {  // Ignore spaces
            operand1 = pop();
            operand2 = pop();

            switch (expression[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator: %c\n", expression[i]);
                    exit(EXIT_FAILURE);
            }

            push(result);
        }
    }

    return pop();
}

int main() {
    char expression[MAX_SIZE];

    // Input prefix expression from the user
    printf("Enter a prefix expression: ");
    fgets(expression, MAX_SIZE, stdin);
    expression[strcspn(expression, "\n")] = '\0';  // Remove newline character if present

    // Evaluate the prefix expression
    int result = evaluatePrefix(expression);

    // Display the result
    printf("Result: %d\n", result);

    return 0;
}
