//1. Write a program to illustrate operations on a BST holding numeric keys.The menu must include : 
//• Insert • Delete • Find • display in Inorder way

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left, *right;
};

struct Node *createNode(int key)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insertNode(struct Node *root, int key)
{
    if (root == NULL)
        return createNode(key);
    if (key < root->key)
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);
    return root;
}

struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = root->right;
        while (temp && temp->left != NULL)
            temp = temp->left;
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

struct Node *findNode(struct Node *root, int key)
{
    if (root == NULL || root->key == key)
        return root;
    if (key < root->key)
        return findNode(root->left, key);
    return findNode(root->right, key);
}

void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    int choice, key;

    while (1)
    {
        printf("\n1. Insert  2. Delete  3. Find  4. Display Inorder  5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            root = insertNode(root, key);
            break;
        case 2:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            root = deleteNode(root, key);
            break;
        case 3:
            printf("Enter key to find: ");
            scanf("%d", &key);
            if (findNode(root, key) != NULL)
                printf("Key %d is found in the BST.\n", key);
            else
                printf("Key %d is not found in the BST.\n", key);
            break;
        case 4:
            printf("Inorder traversal: ");
            inorderTraversal(root);
            printf("\n");
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
