/*
This program finds maximum subarray using divide and conquer strategy
Author: Adwait R Sambare
Explanation: @TODO
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAX_SIZE 100
int array[MAX_SIZE];

int maximumSubarrayAcross(int low, int high, int *maxLow, int *maxHigh)
{
    int mid = (low + high) / 2;
    
    int leftSum = -9999;
    int rightSum = -9999;
    int sum = 0;

    for(int i = mid; i >= low; i--)
    {
        sum += array[i];

        if(sum > leftSum)
        {
            leftSum = sum;
            *maxLow = i;
        }
    }

    sum = 0;

    for(int i = mid + 1; i <= high; i++)
    {
        sum += array[i];

        if(sum > rightSum)
        {
            rightSum = sum;
            *maxHigh = i;
        }
    }

    return leftSum + rightSum;
}

int maximumSubarray(int low, int high, int *maxLow, int *maxHigh)
{
    if(high == low)
    {
        *maxLow = low;
        *maxHigh = high;
        return array[high];
    }

    int mid = (low + high) / 2;

    int leftSum, midSum, rightSum;
    int leftHigh, leftLow, rightHigh, rightLow, midHigh, midLow;

    leftSum = maximumSubarray(low, mid, &leftLow, &leftHigh);

    rightSum = maximumSubarray(mid + 1, high, &rightLow, &rightHigh);

    midSum = maximumSubarrayAcross(low, high, &midLow, &midHigh);

    if((leftSum > rightSum) && (leftSum > midSum))
    {
        *maxLow = leftLow;
        *maxHigh = leftHigh;
        return leftSum;
    }
    else if((rightSum > leftSum) && (rightSum >  midSum))
    {
        *maxLow = rightLow;
        *maxHigh = rightHigh;
        return rightSum;
    }
    else
    {
        *maxLow = midLow;
        *maxHigh = midHigh;
        return midSum;
    }
}

int main()
{
    int N = 0;

    cin>>N;

    for(int i = 0; i < N; i++)
    {
        cin>>array[i];
    }

    int maxLow, maxHigh;
    int max = maximumSubarray(0, N-1, &maxLow, &maxHigh);

    cout<<"Max Total: "<<max<<endl<<"MaxLow: "<<maxLow<<"MaxHigh: "<<maxHigh<<endl;

    for(int i = maxLow; i <= maxHigh; i++)
    {
        cout<<array[i]<<endl;
    }
}
