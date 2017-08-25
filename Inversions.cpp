#include <iostream>

using namespace std;

int NumberOfInversions(int* a, int n)
{
    int count = 0;
    int temp;

    for(int i = 1; i < n; i++)
    {
        int j = i - 1;
        temp = a[i];

        while(j >= 0)
        {
            if(a[j] > temp)
                count++;
            j--;
        }
    }

    return count;
}

int main()
{
    int array[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int array1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 0};
    cout<<"Number Of Inversions: "<<NumberOfInversions(array1, 10)<<endl;
    return 0;
}