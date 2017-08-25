#include <iostream>

using namespace std;

#define INFINITY 99999

int merge(int *a, int l, int m, int h)
{
    int sizeL = m - l + 1;
    int sizeR = h - m;
    int L[sizeL + 1], R[sizeR + 1];
    
    L[sizeL] = R[sizeR] = INFINITY;

    for(int i = l; i <= m; i++)
    {
        L[i - l] = a[i];
    }

    for(int i = m + 1; i <= h; i++)
    {
        R[i - (m + 1)] = a[i];
    }

    int j = 0, k = 0;

    for(int i = l; i <= h; i++)
    {
        if(L[j] < R[k])
        {
            a[i] = L[j++];
        }
        else
        {
            a[i] = R[k++];
        }
    }

    //Code to determine the number of inversions
    int ls = 0, lh = sizeL - 1, rs = 0, rh = sizeR - 1;
    int sCount = 0, lCount = 0;

    if(L[ls] < R[rs])
    {
        while(L[ls] < R[rs])
        {
            ls++;
        }
    }
    else
    {
        while(R[rs] < L[ls])
        {
            rs++;
        }
    }

    if(L[lh] < R[rh])
    {
        while(L[lh] < R[rh])
        {
            lh++;
        }
    }
    else
    {
        while(R[rh] < L[lh])
        {
            rh++;
        }
    }

    return (ls * sizeR + rs * sizeL + lh * sizeR + rh * sizeL);
    
}


//Inversions in O(nlgn)
int NumberOfInversions_DivideAndConquer(int *a, int l, int h)
{
    if(l < h)
    {
        int m = (h - l)/2 + l;//OR (l + h)/2
        int c1, c2, c3;
        c1 = NumberOfInversions_DivideAndConquer(a, l, m);
        c2 = NumberOfInversions_DivideAndConquer(a, m + 1, h);
        c3 = merge(a, l, m, h);

        return c1 + c2 + c3;
    }

    return 0;
}

//Inversions in O(n^2)
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
    
    int inversions = NumberOfInversions_DivideAndConquer(array, 0, 9);
    cout<<"Sorted Array: "<<endl;
    
    for(int i = 0; i < 10; i++)
    {
        cout<<array[i]<<endl;
    }

    cout<<"Inversions: "<<inversions<<endl;
    
    return 0;
}