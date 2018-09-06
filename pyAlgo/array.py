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

def binarySearchOnRotated(arr, x, l, r):
    if l <= r:    
        m = math.floor(((l + r) / 2))
        
        if arr[m] == x:
            return True
        
        if arr[m] > x:
            if arr[m] > arr[r]:
                if x == arr[r]:
                    return True
                if x > arr[r]:
                    return binarySearchOnRotated(arr, x, l, m-1)
                else:
                    return binarySearchOnRotated(arr, x, m+1, r)
            else:
                return binarySearchOnRotated(arr, x, l, m-1)
        else:
            if arr[m] < arr[l]:
                if arr[l] == x:
                    return True
                if arr[l] < x:
                    return binarySearchOnRotated(arr, x, l, m-1)
                else:
                    return binarySearchOnRotated(arr, x, m+1, r)
            else:
                return binarySearchOnRotated(arr, x, m+1, r)
    else:
        return False

def moveAllZerosToEnd(array):
    n = len(array)
    count = 0

    for i in range(n):
        if(array[i] != 0):
            array[count] = array[i]
            count += 1
    
    while count < n:
        array[count] = 0
        count += 1

#Find maximum value of Sum( i*arr[i]) with only rotations on given array allowed
def maxRotatedSummation(array):
    n = len(array)

    summation = 0
    single_summation = 0
    maximum = -99999

    for i in range(n):
        summation += i * array[i]
        single_summation += array[i]
    
    print("summation: ", summation, single_summation)

    maximum = summation

    for i in range(n):
        summation = (summation - (single_summation - array[0])) + (array[0] * (n-1))
        maximum = max(maximum, summation)
        leftRotate(array, 1)

    return maximum

if __name__=='__main__':
    arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
    printArray(arr, len(arr))
    #leftRotate(arr, 4)
    reversalLeftRotate(arr, 4)
    printArray(arr, len(arr))

    i = 8
    print("BinarySearch {} on rotated: ".format(i), binarySearchOnRotated(arr, i, 0, len(arr)-1))

    arr1 = [10, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    print("Max rotated: ", maxRotatedSummation(arr1))

    arr2 = [1, 2, 0, 4, 3, 0, 5, 0]
    moveAllZerosToEnd(arr2)
    print("Move all zeros: ", arr2)

    # for i in range(1, 15):
    #     print("BinarySearch {} on rotated: ".format(i), binarySearchOnRotated(arr, i, 0, len(arr)-1))