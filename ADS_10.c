//10.Write a program to perform addition of two polynomials using singly linked list.

#include <stdio.h>
#include <stdlib.h>

// Node structure representing a term in a polynomial
typedef struct Node
{
    int coef;          // Coefficient of the term
    int exp;           // Exponent of the term
    struct Node *next; // Pointer to the next term
} Node;
// Renaming struct Node to Node

// Function to insert a new term at the end of a polynomial
void insert(Node **poly, int coef, int exp)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->coef = coef;
    temp->exp = exp;
    temp->next = NULL;

    if (*poly == NULL)
    {
        *poly = temp;
        return;
    }

    Node *current = *poly;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = temp;
}

// Function to print the polynomial
void print(Node *poly)
{
    if (poly == NULL)
    {
        printf("0\n");
        return;
    }

    Node *current = poly;
    while (current != NULL)
    {
        printf("(%dx^%d)", current->coef, current->exp);
        if (current->next != NULL)
        {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}

// Function to add two polynomials
Node *addPolynomials(Node *poly1, Node *poly2)
{
    Node *result = NULL;

    while (poly1 != NULL || poly2 != NULL)
    {
        int coef = 0, exp = 0;

        if (poly1 != NULL && poly2 != NULL)
        {
            if (poly1->exp > poly2->exp)
            {
                coef = poly1->coef;
                exp = poly1->exp;
                poly1 = poly1->next;
            }
            else if (poly1->exp < poly2->exp)
            {
                coef = poly2->coef;
                exp = poly2->exp;
                poly2 = poly2->next;
            }
            else
            {
                coef = poly1->coef + poly2->coef;
                exp = poly1->exp;
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        }
        else if (poly1 != NULL)
        {
            coef = poly1->coef;
            exp = poly1->exp;
            poly1 = poly1->next;
        }
        else if (poly2 != NULL)
        {
            coef = poly2->coef;
            exp = poly2->exp;
            poly2 = poly2->next;
        }

        insert(&result, coef, exp);
    }

    return result;
}

int main()
{
    Node *poly1 = NULL;
    insert(&poly1, 5, 4);
    insert(&poly1, 3, 2);
    insert(&poly1, 1, 0);

    Node *poly2 = NULL;
    insert(&poly2, 4, 4);
    insert(&poly2, 2, 2);
    insert(&poly2, 1, 1);

    printf("First polynomial: ");
    print(poly1);

    printf("Second polynomial: ");
    print(poly2);

    Node *result = addPolynomials(poly1, poly2);
    printf("Result: ");
    print(result);

    return 0;
}
