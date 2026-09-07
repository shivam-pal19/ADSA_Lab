#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data, height;
    struct Node *left, *right;
};

int height(struct Node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

struct Node *createTree(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int balance(struct Node *root)
{
    if (root == NULL)
        return 0;

    return height(root->left) - height(root->right);
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *t = x->right;

    x->right = y;
    y->left = t;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *t = y->left;

    y->left = x;
    x->right = t;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

struct Node *insertItem(struct Node *root, int value)
{
    int b;

    if (root == NULL)
        return createTree(value);

    if (value < root->data)
        root->left = insertItem(root->left, value);
    else if (value > root->data)
        root->right = insertItem(root->right, value);
    else
        return root;

    root->height = max(height(root->left), height(root->right)) + 1;

    b = balance(root);

    if (b > 1 && value < root->left->data)
        return rightRotate(root);

    if (b < -1 && value > root->right->data)
        return leftRotate(root);

    if (b > 1 && value > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (b < -1 && value < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

struct Node *minNode(struct Node *root)
{
    while (root->left != NULL)
        root = root->left;

    return root;
}

struct Node *deleteItem(struct Node *root, int value)
{
    struct Node *temp;
    int b;

    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = deleteItem(root->left, value);
    else if (value > root->data)
        root->right = deleteItem(root->right, value);
    else
    {
        if (root->left == NULL || root->right == NULL)
        {
            temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                free(root);
                return NULL;
            }

            *root = *temp;
            free(temp);
        }
        else
        {
            temp = minNode(root->right);
            root->data = temp->data;
            root->right = deleteItem(root->right, temp->data);
        }
    }

    root->height = max(height(root->left), height(root->right)) + 1;

    b = balance(root);

    if (b > 1 && balance(root->left) >= 0)
        return rightRotate(root);

    if (b > 1 && balance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (b < -1 && balance(root->right) <= 0)
        return leftRotate(root);

    if (b < -1 && balance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

struct Node *searchItem(struct Node *root, int value)
{
    if (root == NULL || root->data == value)
        return root;

    if (value < root->data)
        return searchItem(root->left, value);

    return searchItem(root->right, value);
}

void deleteTree(struct Node *root)
{
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    free(root);
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    struct Node *result;
    int choice, value;

    while (1)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Delete Tree\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insertItem(root, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                root = deleteItem(root, value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);

                result = searchItem(root, value);

                if (result != NULL)
                    printf("Item found\n");
                else
                    printf("Item not found\n");
                break;

            case 4:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                deleteTree(root);
                root = NULL;
                printf("Tree deleted\n");
                break;

            case 6:
                deleteTree(root);
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}