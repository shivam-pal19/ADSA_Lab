#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *rear = NULL;

void enqueue()
{
    int value;
    struct Node *newNode;

    printf("Enter value: ");
    scanf("%d", &value);

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (rear == NULL)
    {
        rear = newNode;
        newNode->next = rear;
    }
    else
    {
        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    struct Node *front;

    if (rear == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    front = rear->next;

    printf("Deleted element: %d\n", front->data);

    if (front == rear)
    {
        rear = NULL;
    }
    else
    {
        rear->next = front->next;
    }

    free(front);
}

void display()
{
    struct Node *temp;

    if (rear == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue: ");

    temp = rear->next;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != rear->next);

    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}