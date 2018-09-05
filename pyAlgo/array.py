import math

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
    leftRotate(arr, 4)
    printArray(arr, len(arr))