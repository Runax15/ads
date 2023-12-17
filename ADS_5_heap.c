/*Write a program to implement Heap sort and Quick Sort on 1D array of Student structure
(contains student_name, student_roll_no, total_marks), with key as student_roll_no.
and count the number of swap performed*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Student structure
struct Student
{
    char student_name[50];
    int student_roll_no;
    float total_marks;
};

// Function to perform swaps and count them
void swap(struct Student *a, struct Student *b, int *swapCount)
{
    struct Student temp = *a;
    *a = *b;
    *b = temp;
    (*swapCount)++;
}

// Heapify the array
void heapify(struct Student arr[], int n, int i, int *swapCount)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].student_roll_no > arr[largest].student_roll_no)
        largest = left;

    if (right < n && arr[right].student_roll_no > arr[largest].student_roll_no)
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest], swapCount);
        heapify(arr, n, largest, swapCount);
    }
}

// Heap Sort
void heapSort(struct Student arr[], int n, int *swapCount)
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i, swapCount);
    }

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i], swapCount);
        heapify(arr, i, 0, swapCount);
    }
}

// Partition function for Quick Sort
int partition(struct Student arr[], int low, int high, int *swapCount)
{
    struct Student pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j].student_roll_no < pivot.student_roll_no)
        {
            i++;
            swap(&arr[i], &arr[j], swapCount);
        }
    }

    swap(&arr[i + 1], &arr[high], swapCount);
    return i + 1;
}

// Quick Sort
void quickSort(struct Student arr[], int low, int high, int *swapCount)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, swapCount);

        quickSort(arr, low, pi - 1, swapCount);
        quickSort(arr, pi + 1, high, swapCount);
    }
}

int main()
{
    int n, swapCountHeap = 0, swapCountQuick = 0;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    // Input student details
    for (int i = 0; i < n; i++)
    {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].student_name);
        printf("Roll Number: ");
        scanf("%d", &students[i].student_roll_no);
        printf("Total Marks: ");
        scanf("%f", &students[i].total_marks);
    }

    // Perform Heap Sort
    heapSort(students, n, &swapCountHeap);

    // Print sorted array after Heap Sort
    printf("\nStudents sorted by Roll Number using Heap Sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t%d\t%.2f\n", students[i].student_name, students[i].student_roll_no, students[i].total_marks);
    }
    printf("Number of swaps in Heap Sort: %d\n", swapCountHeap);

    // Reset swap count for Quick Sort
    swapCountQuick = 0;

    // Perform Quick Sort
    quickSort(students, 0, n - 1, &swapCountQuick);

    // Print sorted array after Quick Sort
    printf("\nStudents sorted by Roll Number using Quick Sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t%d\t%.2f\n", students[i].student_name, students[i].student_roll_no, students[i].total_marks);
    }
    printf("Number of swaps in Quick Sort: %d\n", swapCountQuick);

    return 0;
}