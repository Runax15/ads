// 2. Write a program to create a Binary Search Tree and display it level wise. Also perform
// deletion of a node from it.
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
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
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

struct Node *findMinimum(struct Node *node)
{
    struct Node *current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
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
        struct Node *temp = findMinimum(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void printLevelOrder(struct Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->key);
    else if (level > 1)
    {
        printLevelOrder(root->left, level - 1);
        printLevelOrder(root->right, level - 1);
    }
}

int height(struct Node *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void levelOrderTraversal(struct Node *root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        printf("Level %d: ", i);
        printLevelOrder(root, i);
        printf("\n");
    }
}

int main()
{
    struct Node *root = NULL;

    root = insertNode(root, 50);
    int keys[] = {30, 20, 40, 70, 60, 80};
    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++)
    {
        insertNode(root, keys[i]);
    }

    printf("BST level-wise:\n");
    levelOrderTraversal(root);

    int keyToDelete;
    printf("\nEnter the key to delete: ");
    scanf("%d", &keyToDelete);
    root = deleteNode(root, keyToDelete);

    printf("\nBST level-wise after deletion of node %d:\n", keyToDelete);
    levelOrderTraversal(root);

    return 0;
}