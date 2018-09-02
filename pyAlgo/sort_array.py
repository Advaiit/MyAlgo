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

    def swap(self, array, index1, index2):
        temp = array[index1]
        array[index1] = array[index2]
        array[index2] = temp

    def mergeSort(self, array, l, r):
        m = (l + r)/2

        if(l < r):
            self.mergeSort(array, l, m)
            self.mergeSort(array, m+1, r)
            self.merge(array, l, m, r)

    def quickSortUtil(self, array, l, r):
        pivot = array[r]
        sorted_array_end = l
        itr = l

        while(itr < r):
            if array[itr] < pivot:
                self.swap(array, itr, sorted_array_end)
                itr += 1  
                sorted_array_end += 1
            else:
                itr += 1

        self.swap(array, sorted_array_end, r)

        return sorted_array_end

    def quickSort(self, array, l, r):
        if(l < r):
            p = self.quickSortUtil(array, l, r)
            self.quickSort(array, l, p-1)
            self.quickSort(array, p+1, r)
        
if __name__=='__main__':
    a = [7, 4, 54, 23, 65, 34, 23, 67, 34, 67, 234 ,65, 34, 31]
    a_len = len(a)

    sort = Sort()
    
    sort.mergeSort(a, 0, a_len-1)
    #sort.quickSort(a, 0, a_len-1)

    print('Sorted Array: ')
    print(a)