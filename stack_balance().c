#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

// Function to push a character onto the stack
void push(char ch) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow: Cannot push character, stack is full.\n");
        exit(EXIT_FAILURE);
    } else {
        top++;
        stack[top] = ch;
    }
}

// Function to pop a character from the stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow: Cannot pop character, stack is empty.\n");
        exit(EXIT_FAILURE);
    } else {
        int val=stack[top];
        top--;
        return val ;
    }
}

// Function to check if parentheses are balanced
int isBalanced(char expression[]) {
    char ch;

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (top == -1) {
                return 0; // Unbalanced if closing parenthesis encountered when stack is empty
            }

            ch = pop();

            if ((expression[i] == ')' && ch != '(') ||
                (expression[i] == ']' && ch != '[') ||
                (expression[i] == '}' && ch != '{')) {
                return 0; // Unbalanced if mismatched parentheses
            }
        }
    }
    top ==-1;
    return 1; // Balanced if stack is empty at the end

}

int main() {
    char expression[MAX_SIZE];

    // Input expression from the user
    printf("Enter an expression: ");
    fgets(expression, MAX_SIZE, stdin);

    int result=isBalanced(expression);

    // Check if parentheses are balanced
    if (result==1) {
        printf("Parentheses are balanced.\n");
    } else {
        printf("Parentheses are not balanced.\n");
    }

    return 0;
}
