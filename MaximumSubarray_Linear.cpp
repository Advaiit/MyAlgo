#include <iostream>

using namespace std;

#define MAX_SIZE 100

int findMaxSubarray(int *a, int n, int *maxLow, int *maxHigh)
{
    int sum = 0, max = -9999;
    int low = 0;

    for(int i = 0; i < n; i++)
    {
        sum += a[i];

        if(sum > max)
        {
            max = sum;
            *maxLow = low;
            *maxHigh = i;
        }

        if(sum < 0)
        {
            sum = 0;
            low = i + 1;
        }
    }

    return max;
}

int main()
{
    int n;
    int array[MAX_SIZE];

    cin>>n;

    for(int i = 0; i < n; i++)
    {
        cin>>array[i];
    }

    int maxLow = 0, maxHigh = 0;
    int max = findMaxSubarray(array, n, &maxLow, &maxHigh);
    cout<<"Max Total: "<<max<<" MaxLow: "<<maxLow<<" MaxHigh: "<<maxHigh<<endl;

    return 0;
}