#include <iostream>
using namespace std;

class Heap
{
    int *heap;
    int currentSize;

public:
    Heap()
    {
        heap = NULL;
        currentSize = 0;
    }

    ~Heap()
    {
        if(heap)
        {
            delete heap;
            heap = NULL;
        }
    }

    inline void swap(int index_1, int index_2)
    {
        int temp = heap[index_1];
        heap[index_1] = heap[index_2];
        heap[index_2] = temp;
    }

    inline int left(int i)
    {
        return i * 2;
    }

    inline int right(int i)
    {
        return (i * 2) + 1;
    }

    inline int parent(int i)
    {
        return i / 2;
    }

    void setMaxSize(int size);
    void rawInsert(int x, int index);
    void maxHeapify(int index);
    void buildMaxHeap();
    void printHeap();
};

void Heap::setMaxSize(int size)
{
    if(heap)
    {
        delete heap;
        heap = NULL;
    }

    heap = new int[size + 1];
    currentSize = size;
}

void Heap::rawInsert(int x, int index)
{
    if(index < currentSize)
    {
        heap[index] = x;
    }
}

void Heap::maxHeapify(int index)
{
    int l = left(index);
    int r = right(index);
    int largest = index;

    if(l <= currentSize && r <= currentSize)
    {
       if(heap[l] > heap[index])
       {
           largest = l;
       }

       if(heap[r] > heap[largest])
       {
           largest = r;
       }
    }

    if(largest != index)
    {
        swap(largest, index);
        maxHeapify(largest);
    }
}

void Heap::buildMaxHeap()
{
    int length = currentSize;

    for(int i = (length/2); i >= 1; i--)
    {
        maxHeapify(i);
    }
}

void Heap::printHeap()
{
    for(int i = 1; i <= currentSize; i++)
    {
        printf("%d\n", heap[i]);
    }
}

int main()
{
    Heap h;
    h.setMaxSize(15);

    // h.rawInsert(16, 0);
    // h.rawInsert(14, 1);
    // h.rawInsert(10, 2);
    // h.rawInsert(9, 3);
    // h.rawInsert(8, 4);
    // h.rawInsert(7, 5);
    // h.rawInsert(4, 6);
    // h.rawInsert(3, 7);
    // h.rawInsert(2, 8);
    // h.rawInsert(1, 9);

    h.rawInsert(16, 10);
    h.rawInsert(14, 9);
    h.rawInsert(10, 8);
    h.rawInsert(9, 7);
    h.rawInsert(8, 6);
    h.rawInsert(7, 5);
    h.rawInsert(4, 4);
    h.rawInsert(3, 3);
    h.rawInsert(2, 2);
    h.rawInsert(1, 1);

    h.printHeap();

    printf("\n\n");

    h.buildMaxHeap();

    h.printHeap();

    return 0;
}