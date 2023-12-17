#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

// Function to push an element onto the stack
void push(char x)
{
    stack[++top] = x;
}

// Function to pop an element from the stack
char pop()
{
    // Check if the stack is empty
    if (top == -1)
    {    
        return -1;
    }
    else
    {    
        return stack[top--];
    }
}

// Function to determine the priority of operators
int priority(char x)
{
    if (x == '(')
    {
        return 0;
    }

    if (x == '+' || x == '-')
    {    
        return 1;
    }

    if (x == '*' || x == '/')
    {
        return 2;
    }
    return 0;
}

int main()
{
    char exp[100];
    char *e, x;

    // Input expression from the user
    printf("Enter the expression : ");
    scanf("%s", exp);
    printf("\n");
    e = exp;

    while (*e != '\0')
    {
        if (isalnum(*e))
        {
            // If the character is an operand, print it
            printf("%c ", *e);
        }    

        else if (*e == '(')
        {
            // If the character is an opening parenthesis, push it onto the stack
            push(*e);
        }    

        else if (*e == ')')
        {
            // If the character is a closing parenthesis, pop and print elements from the stack until an opening parenthesis is encountered
            while ((x = pop()) != '(')
            {
                printf("%c ", x);
            }    
        }
        else
        {
            // If the character is an operator, pop and print operators from the stack with higher or equal priority until a lower priority operator is encountered, then push the current operator onto the stack
            while (priority(stack[top]) >= priority(*e))
            {
                printf("%c ", pop());
            }    
            push(*e);
        }
        e++;
    }

    // Pop and print any remaining operators from the stack
    while (top != -1)
    {
        printf("%c ", pop());
    }
    return 0;
}

/*sample inputs:
a+b*c

(a+b)*c+(d-a)

((4+8)(6-5))/((3-2)(2+2))
*/