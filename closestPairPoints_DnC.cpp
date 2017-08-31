//returns the distance between closest pair of points from a set of points using divide and conquer
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

#define MIN(x, y) x > y ? y : x

struct Point
{
    int x;
    int y;
};

int compareX(const void *a, const void *b)
{
    return ((Point *)a)->x - ((Point *)b)->x;
}

int compareY(const void *a, const void *b)
{
    return ((Point *)a)->y - ((Point *)b)->y;
}

float distance(Point p1, Point p2)
{
    return sqrt(((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)));
}

float StripDistance(Point strip[], int size, float d)
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

int closestPairUtil(Point pointArrayX[], Point pointArrayY[], int n)
{
    int mid = n/2;

    Point midPoint = pointArrayX[mid];

    Point pointArrayYL[mid];
    Point pointArrayYR[n - mid];
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

    float dl = closestPairUtil(pointArrayX, pointArrayYL, mid);
    float dr = closestPairUtil(pointArrayX + mid, pointArrayYR, n - mid);
    float d = MIN(dl, dr);

    Point strip[n];
    int si = 0;

    for(int i = 0; i < n; i++)
    {
        if((pointArrayY[i].x - midPoint.x) < d)
        {
            strip[si++] = pointArrayY[i];
        }
    }

    return MIN(d, StripDistance(strip, si, d));
}

int main()
{
    return 0;
}
