#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(char x) {
    stack[++top] = x;
}

// Function to pop an element from the stack
char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

// Function to determine the priority of operators
int priority(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

// Function to reverse a string
void reverseString(char str[]) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

// Function to convert infix expression to prefix expression
void infixToPrefix(char infix[], char prefix[]) {
    char temp, x;
    int i = 0, j = 0;

    // Reverse the infix expression
    reverseString(infix);

    while (infix[i] != '\0') {
        if (infix[i] == ' ' || infix[i] == '\t') {
            // Ignore spaces and tabs
            i++;
            continue;
        }

        if (isalnum((unsigned char)infix[i])) {
            // If the character is an operand, add it to the prefix expression
            prefix[j++] = infix[i];
        } else if (infix[i] == ')') {
            // If the character is a closing parenthesis, push it onto the stack
            push(infix[i]);
        } else if (infix[i] == '(') {
            // If the character is an opening parenthesis, pop operators from the stack until a closing parenthesis is encountered
            while ((x = pop()) != ')') {
                prefix[j++] = x;
            }
        } else {
            // If the character is an operator, pop operators from the stack until an operator with lower or equal priority is encountered, then push the current operator onto the stack
            while (top != -1 && priority(stack[top]) >= priority(infix[i])) {
                prefix[j++] = pop();
            }
            push(infix[i]);
        }

        i++;
    }

    // Pop any remaining operators from the stack and append them to the prefix expression
    while (top != -1) {
        prefix[j++] = pop();
    }

    // Null-terminate the prefix expression
    prefix[j] = '\0';

    // Reverse the prefix expression to get the final result
    reverseString(prefix);
}

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];

    printf("Enter the infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    infixToPrefix(infix, prefix);

    printf("\nThe prefix expression is: %s", prefix);

    return 0;
}

/*sample inputs:
a+b*c

(a+b)*c+(d-a)

((4+8)(6-5))/((3-2)(2+2))
*/
