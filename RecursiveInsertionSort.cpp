/*
Recursive Insertion Sort example

*/

#include <iostream>
using namespace std;

void InsertionSortUtility(int* a, int n)
{
    int temp;
    for(int i = 1; i < n; i++)
    {
        int j = i - 1;
        temp = a[i];

        while(j >= 0 && a[j] > temp)
        {
            a[j+1] = a[j];
            j--;
        }

        a[j + 1] = temp;
    }
}

void RecursiveInsertionSortUtility(int* a, int n, int x)
{
    if(!n)
        return;

    RecursiveInsertionSortUtility(a, n-1, a[n]);

    int i = n;

    while(a[i] > x && i >= 0)
    {
        a[i+1] = a[i];
        i--;
    }

    a[i + 1] = x;
}

int main()
{
    int array[10] = {7, 9, 5, 2, 7, 8, 5, 2, 1, 0};
    int array1[10] = {7, 9, 5, 2, 7, 8, 5, 2, 1, 0};

    RecursiveInsertionSortUtility(array, 8, array[9]);

    cout<<"Recursive Sorted Array: \n";

    for(int i = 0; i < 10; i++)
    {
        cout<<array[i]<<"\n";
    }

    InsertionSortUtility(array1, 10);

    cout<<"Sorted Array: \n";
    
    for(int i = 0; i < 10; i++)
    {
        cout<<array1[i]<<"\n";
    }

    return 0;
}