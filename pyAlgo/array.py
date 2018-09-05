import math

def swap(array, x, y):
    temp = array[x]
    array[x] = array[y]
    array[y] = temp

def reverseArray(array, l, r):
    if l < 0 or r > len(array):
        assert("Size is invalid")
    
    while l < r:
        swap(array, l, r)
        l += 1
        r -= 1

#rotate using reverasl algorithm
def reversalLeftRotate(array, d):
    n = len(array)

    if d >= n:
        assert("size of d is invalid")
    
    reverseArray(array, 0, d-1)
    reverseArray(array, d, n-1)
    reverseArray(array, 0, n-1)

#juggling algo
def leftRotate(array, d):
    n = len(array)

    for i in range(math.gcd(n, d)): 
        j = i
        temp = array[j]
        while True:
            k = j + d

            if k >= n:
                k = k - n
            
            if k == i:
                break
            
            array[j] = array[k]
            j = k
        array[j] = temp
        

def printArray(arr, size):
    for i in range(size):
        print ("%d" % arr[i], end=" ")
    
    print('\n')

if __name__=='__main__':
    arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    printArray(arr, len(arr))
    #leftRotate(arr, 4)
    reversalLeftRotate(arr, 4)
    printArray(arr, len(arr))