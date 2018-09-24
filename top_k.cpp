//Find top k (or most frequent) numbers in a stream

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void k_top(int *array, int len, int k)
{
    vector<int> top_table(k+1);
    unordered_map<int, int> freq_map;

    for(int i = 0; i < len; i++)
    {
        freq_map[array[i]]++;
        top_table[k] = array[i];

        vector<int>::iterator it = find(top_table.begin(), top_table.end()-1, array[i]);

        for(int j = distance(top_table.begin(), it) - 1; j >= 0; --j)
        {
            if(freq_map[top_table[j+1]] > freq_map[top_table[j]])
            {
                swap(top_table[j], top_table[j+1]);
            }
            else if(freq_map[top_table[j+1]] == freq_map[top_table[j]] && top_table[j] > top_table[j+1])
            {
                swap(top_table[j], top_table[j+1]);
            }
            else
            {
                break;
            }
        }

        for(int j = 0; j < k && top_table[j] != 0; j++)
        {
            cout<<" "<<top_table[j];
        }
    }
    cout<<endl;
}

int main()
{
    int k = 4;
    int arr[] = { 5, 2, 1, 3, 2 };
    k_top(arr, 5, k);
    return 0;
}