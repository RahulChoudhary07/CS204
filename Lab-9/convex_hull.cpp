#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};

Point p0;

Point nextToTop(stack<Point> &rio)
{
    Point p = rio.top();
    rio.pop();
    Point res = rio.top();
    rio.push(p);
    return res;
}

void swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

int compare(const void *vp1, const void *vp2)
{
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;

    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;

    return (o == 1) ? -1 : 1;
}

void Hull(Point points[], int n)
{
    int xmin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        int x = points[i].x;

        if (x < xmin || (xmin == x && points[i].y < points[min].y))
            xmin = points[i].x, min = i;
    }

    swap(points[0], points[min]);

    p0 = points[0];
    qsort(&points[1], n - 1, sizeof(Point), compare);

    int m = 1;
    for (int i = 1; i < n; i++)
    {
        while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0)
            i++;

        points[m] = points[i];
        m++;
    }
    if (m < 3)
        return;

    stack<Point> rio;
    rio.push(points[0]);
    rio.push(points[1]);
    rio.push(points[2]);

    for (int i = 3; i < m; i++)
    {
        while (orientation(nextToTop(rio), rio.top(), points[i]) != 1)
            rio.pop();
        rio.push(points[i]);
    }
    Point a[m];
    int i = 0;
    while (!rio.empty())
    {
        Point p = rio.top();
        a[i].x = p.x;
        a[i].y = p.y;
        rio.pop();
        i++;
    }
    cout << i << endl;
    for (int j = m - 2; j >= 0; j--)
        cout << a[j].x << " " << a[j].y << endl;
}

int main()
{
    int n;
    cin >> n;
    Point a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;

    Hull(a, n);
    return 0;
}
