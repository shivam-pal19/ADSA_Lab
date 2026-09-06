#include <stdio.h>
#define SIZE 5

int stack1[SIZE], stack2[SIZE];
int top1 = -1, top2 = -1;

void enqueue(int value)
{
    while (top1 != -1)
    {
        stack2[++top2] = stack1[top1--];
    }

    stack1[++top1] = value;

    while (top2 != -1)
    {
        stack1[++top1] = stack2[top2--];
    }
}

void dequeue()
{
    if (top1 == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Deleted element: %d\n", stack1[top1--]);
}

void display()
{
    int i;

    if (top1 == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue: ");

    for (i = top1; i >= 0; i--)
        printf("%d ", stack1[i]);

    printf("\n");
}

int main()
{
    int choice, value;

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
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
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
}