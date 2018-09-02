class Sort:
    def __init__(self):
        return

    def merge(self, array, l, m, r):
        size1 = m-l+1
        size2 = r - m

        arr1 = [0] * size1
        arr2 = [0] * size2

        for i in range(size1):
            arr1[i] = array[l + i]

        for j in range(size2):
            arr2[j] = array[m + 1 + j]

        i = j = 0
        k = l

        while i < size1 and j < size2:
            if arr1[i] < arr2[j]:
                array[k] = arr1[i]
                i += 1
            else:
                array[k] = arr2[j]
                j += 1
            k+=1
        
        while i < size1:
            array[k] = arr1[i]
            i += 1
            k += 1
        
        while j < size2:
            array[k] = arr2[j]
            j += 1
            k += 1


    def mergeSort(self, array, l, r):
        m = (l + r)/2

        if(l < r):
            self.mergeSort(array, l, m)
            self.mergeSort(array, m+1, r)
            self.merge(array, l, m, r)
        
if __name__=='__main__':
    a = [7, 4, 54, 23, 65, 34, 23, 67, 34, 67, 234 ,65, 34, 31]
    a_len = len(a)

    sort = Sort()
    
    sort.mergeSort(a, 0, a_len-1)

    print('Sorted Array: ')
    print(a)