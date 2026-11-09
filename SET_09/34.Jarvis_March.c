#include <stdio.h>

struct Point
{
    int x, y;
};

int orientation(struct Point p, struct Point q, struct Point r)
{
    int val = (q.y - p.y) * (r.x - q.x)
            - (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;       // Collinear
    return (val > 0) ? 1 : 2;
}

void convexHull(struct Point points[], int n)
{
    int l = 0, p, q, i;

    if (n < 3)
    {
        printf("Convex hull requires at least 3 points.\n");
        return;
    }

    for (i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    p = l;

    printf("Convex Hull:\n");

    do
    {
        printf("(%d, %d)\n", points[p].x, points[p].y);
        q = (p + 1) % n;

        for (i = 0; i < n; i++)
        {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }

        p = q;

    } while (p != l);
}

int main()
{
    struct Point points[100];
    int n, i;

    printf("Enter number of points: ");
    scanf("%d", &n);

    if (n < 3 || n > 100)
    {
        printf("Invalid number of points.\n");
        return 0;
    }

    printf("Enter coordinates (x y):\n");

    for (i = 0; i < n; i++)
        scanf("%d %d", &points[i].x, &points[i].y);

    convexHull(points, n);

    return 0;
}