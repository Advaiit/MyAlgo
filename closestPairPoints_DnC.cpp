//returns the distance between closest pair of points from a set of points using divide and conquer
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <float.h>

#define MIN(x, y) ((x < y) ? x : y)

struct point
{
    int x;
    int y;
};

int compareX(const void *a, const void *b)
{
    return ((point *)a)->x - ((point *)b)->x;
}

int compareY(const void *a, const void *b)
{
    return ((point *)a)->y - ((point *)b)->y;
}

float distance(point p1, point p2)
{
    return (float)sqrt((float)((p1.x - p2.x) * (p1.x - p2.x)) + (float)((p1.y - p2.y) * (p1.y - p2.y)));
}

float min(float x, float y)
{
    return (x < y ? x : y);
}

float StripDistance(point strip[], int size, float d)
{
    float min = d;

    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; j++)// j = i + 1 so that the distance calculation is not repeated.
        {                                                                   //i.e once distance(a[0], a[1]) is calculated, no need to calculate distance(a[1], a[0])
            float current_min = distance(strip[j], strip[i]);               //Hence we start from j = i + 1 and not j = 0
            if(current_min < min)
            {
                min = current_min;
            }
        }
    }

    return min;
}

float bruteForce(point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (distance(P[i], P[j]) < min)
                min = distance(P[i], P[j]);
    return min;
}

float closestPairUtil(point pointArrayX[], point pointArrayY[], int n)
{
    if (n <= 3)
        return bruteForce(pointArrayX, n);

    int mid = n/2;

    point midPoint = pointArrayX[mid];

    point pointArrayYL[mid + 1];
    point pointArrayYR[n - mid - 1];
    int li = 0, ri = 0;

    for(int i = 0; i < n; i++)
    {
        if(pointArrayY[i].x < midPoint.x)
        {
            pointArrayYL[li++] = pointArrayY[i];
        }
        else
        {
            pointArrayYR[ri++] = pointArrayY[i];
        }
    }

    float dl = (float)closestPairUtil(pointArrayX, pointArrayYL, mid);
    float dr = (float)closestPairUtil(pointArrayX + mid, pointArrayYR, n - mid);
    float d = MIN(dl, dr);

    point strip[n];
    int si = 0;

    for(int i = 0; i < n; i++)
    {
        if(abs(pointArrayY[i].x - midPoint.x) < d)
        {
            strip[si++] = pointArrayY[i];
        }
    }

    return MIN(d, StripDistance(strip, si, d));
}

float closest(point P[], int n)
{
    point Px[n];
    point Py[n];
    for (int i = 0; i < n; i++)
    {
        Px[i] = P[i];
        Py[i] = P[i];
    }
 
    qsort(Px, n, sizeof(point), compareX);
    qsort(Py, n, sizeof(point), compareY);
 
    // Use recursive function closestUtil() to find the smallest distance
    return closestPairUtil(Px, Py, n);
}

int main()
{
    point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    float f = closest(P, n);
    std::cout << "The smallest distance is " << f;
    return 0;
}
