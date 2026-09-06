#include <stdio.h>
#define SIZE 5

int q1[SIZE], q2[SIZE];
int front1 = 0, rear1 = -1;
int front2 = 0, rear2 = -1;

void push(int value)
{
    if (rear1 == SIZE - 1)
    {
        printf("Stack is Full\n");
        return;
    }

    q1[++rear1] = value;
}

void pop()
{
    int value;

    if (rear1 == -1)
    {
        printf("Stack is Empty\n");
        return;
    }

    while (front1 < rear1)
        q2[++rear2] = q1[front1++];

    value = q1[front1];

    front1 = 0;
    rear1 = -1;

    while (front2 <= rear2)
        q1[++rear1] = q2[front2++];

    front2 = 0;
    rear2 = -1;

    printf("Popped element: %d\n", value);
}

void display()
{
    int i;

    if (rear1 == -1)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack: ");

    for (i = rear1; i >= front1; i--)
        printf("%d ", q1[i]);

    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
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