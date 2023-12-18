/*Write a program to implement multiple queue i.e. two queues using array and perform
following operations on it.
a. Add queue b. Delete queue c. Display queue*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // Maximum size for each queue

struct MultiQueue
{
    int front1, rear1;    // Front and rear for Queue 1
    int front2, rear2;    // Front and rear for Queue 2
    int queue1[MAX_SIZE]; // Array representing Queue 1
    int queue2[MAX_SIZE]; // Array representing Queue 2
};

// Function to initialize the queues
void initialize(struct MultiQueue *mq)
{
    mq->front1 = mq->rear1 = -1;
    mq->front2 = mq->rear2 = -1;
}

// Function to add an element to Queue 1
void addToQueue1(struct MultiQueue *mq, int value)
{
    if (mq->rear1 == MAX_SIZE - 1)
    {
        printf("Queue 1 is full. Cannot add more elements.\n");
        return;
    }
    if (mq->front1 == -1)
    {
        mq->front1 = 0;
    }
    mq->queue1[++mq->rear1] = value;
}

// Function to add an element to Queue 2
void addToQueue2(struct MultiQueue *mq, int value)
{
    if (mq->rear2 == MAX_SIZE - 1)
    {
        printf("Queue 2 is full. Cannot add more elements.\n");
        return;
    }
    if (mq->front2 == -1)
    {
        mq->front2 = 0;
    }
    mq->queue2[++mq->rear2] = value;
}

// Function to delete an element from Queue 1
void deleteFromQueue1(struct MultiQueue *mq)
{
    if (mq->front1 == -1)
    {
        printf("Queue 1 is empty. Cannot delete.\n");
        return;
    }
    printf("Deleted from Queue 1: %d\n", mq->queue1[mq->front1++]);
    if (mq->front1 > mq->rear1)
    {
        mq->front1 = mq->rear1 = -1; // Reset queue if it becomes empty after deletion
    }
}

// Function to delete an element from Queue 2
void deleteFromQueue2(struct MultiQueue *mq)
{
    if (mq->front2 == -1)
    {
        printf("Queue 2 is empty. Cannot delete.\n");
        return;
    }
    printf("Deleted from Queue 2: %d\n", mq->queue2[mq->front2++]);
    if (mq->front2 > mq->rear2)
    {
        mq->front2 = mq->rear2 = -1; // Reset queue if it becomes empty after deletion
    }
}

// Function to display Queue 1
void displayQueue1(struct MultiQueue *mq)
{
    if (mq->front1 == -1)
    {
        printf("Queue 1 is empty.\n");
        return;
    }
    printf("Queue 1: ");
    for (int i = mq->front1; i <= mq->rear1; i++)
    {
        printf("%d ", mq->queue1[i]);
    }
    printf("\n");
}

// Function to display Queue 2
void displayQueue2(struct MultiQueue *mq)
{
    if (mq->front2 == -1)
    {
        printf("Queue 2 is empty.\n");
        return;
    }
    printf("Queue 2: ");
    for (int i = mq->front2; i <= mq->rear2; i++)
    {
        printf("%d ", mq->queue2[i]);
    }
    printf("\n");
}

int main()
{
    struct MultiQueue mq;
    initialize(&mq);

    int choice, element;

    do
    {
        printf("\nSelect an operation:\n");
        printf("1. Add to Queue 1\n");
        printf("2. Add to Queue 2\n");
        printf("3. Delete from Queue 1\n");
        printf("4. Delete from Queue 2\n");
        printf("5. Display Queue 1\n");
        printf("6. Display Queue 2\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element to add to Queue 1: ");
                scanf("%d", &element);
                addToQueue1(&mq, element);
                break;
            case 2:
                printf("Enter element to add to Queue 2: ");
                scanf("%d", &element);
                addToQueue2(&mq, element);
                break;
            case 3:
                deleteFromQueue1(&mq);
                break;
            case 4:
                deleteFromQueue2(&mq);
                break;
            case 5:
                displayQueue1(&mq);
                break;
            case 6:
                displayQueue2(&mq);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 7);

    return 0;
}