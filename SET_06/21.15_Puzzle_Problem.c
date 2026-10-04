#include <stdio.h>
#include <stdlib.h>

#define N 4

struct Node
{
    int board[N][N];
    int x, y;
    int level, cost;
};

int goal[N][N] =
{
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 0}
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int calculateCost(int board[N][N])
{
    int i, j, cost = 0;

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            if(board[i][j] != 0)
            {
                int value = board[i][j] - 1;
                int gi = value / N;
                int gj = value % N;

                cost += abs(i - gi) + abs(j - gj);
            }

    return cost;
}

struct Node *createNode(int board[N][N], int x, int y, int newX, int newY, int level)
{
    int i, j;

    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            node->board[i][j] = board[i][j];

    node->board[x][y] = node->board[newX][newY];
    node->board[newX][newY] = 0;

    node->x = newX;
    node->y = newY;
    node->level = level;
    node->cost = level + calculateCost(node->board);

    return node;
}

void printBoard(int board[N][N])
{
    int i, j;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
            printf("%2d ", board[i][j]);

        printf("\n");
    }

    printf("\n");
}

int isGoal(int board[N][N])
{
    int i, j;

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            if(board[i][j] != goal[i][j])
                return 0;

    return 1;
}

void solve(int initial[N][N], int x, int y)
{
    struct Node *queue[10000];
    int front = 0, rear = 0;
    int i;

    struct Node *root = createNode(initial, x, y, x, y, 0);
    queue[rear++] = root;

    while(front < rear)
    {
        int k;

        /* Find node with minimum cost */
        for(i = front + 1; i < rear; i++)
        {
            if(queue[i]->cost < queue[front]->cost)
            {
                struct Node *temp = queue[i];
                queue[i] = queue[front];
                queue[front] = temp;
            }
        }

        struct Node *current = queue[front++];

        printBoard(current->board);

        if(isGoal(current->board))
        {
            printf("Solution found in %d moves.\n", current->level);
            return;
        }

        for(k = 0; k < 4; k++)
        {
            int newX = current->x + dx[k];
            int newY = current->y + dy[k];

            if(newX >= 0 && newX < N && newY >= 0 && newY < N)
            {
                if(rear < 10000)
                    queue[rear++] = createNode(
                        current->board,
                        current->x, current->y,
                        newX, newY,
                        current->level + 1
                    );
            }
        }
    }

    printf("No solution found.\n");
}

int main()
{
    int board[N][N];
    int i, j, x, y;

    printf("Enter the 15-puzzle configuration (0 for blank):\n");

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            scanf("%d", &board[i][j]);

            if(board[i][j] == 0)
            {
                x = i;
                y = j;
            }
        }
    }

    printf("\nSolution steps:\n");
    solve(board, x, y);

    return 0;
}