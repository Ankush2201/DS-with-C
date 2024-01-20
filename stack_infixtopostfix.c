#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// Global variables
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
        return '\0'; // Return null character for an empty stack
    } else {
        return stack[top--];
    }
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    int i, j;
    char ch;

    for (i = j = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while ((ch = pop()) != '(') {
                postfix[j++] = ch;
            } // jere when closing paranthesis comes we will pop all ement from stack aas Ch and then we will put it to the postfix expression
        } else {
            while (getPrecedence(stack[top]) >= getPrecedence(infix[i])) {
                postfix[j++] = pop(); // this will check the proprity of the sign lower on higher is not allowed.
            }
            push(infix[i]);// and sab chack krneke baad jo bhi bacha hai infix mai vo sab puch krdo stack mai. ;dkdkdkdkdkddkdkdkdkdkdkdkdkdkdkdkdkkdkdkdkdkdkdkdkdkdkdkdkdkdkdkdcdkdkd
        }
    }

    while (top != -1) {
        postfix[j++] = pop(); //aaur jo bhi elemt abhi stack mai hai unn sab ko post fix mai daal denge. 
    }

    postfix[j] = '\0'; // last vala ement jo bhi hai '\0' yeh dalna kyu ki infix mai se yeh aaigna nhi kyuki condition mia aaise diya  hau auna ne
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    // Input infix expression from the user
    printf("Enter an infix expression: ");
    gets(infix); // here f gets is not working ...used gets for it

    // Convert infix to postfix
    infixToPostfix(infix, postfix);

    // Display the postfix expression
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
