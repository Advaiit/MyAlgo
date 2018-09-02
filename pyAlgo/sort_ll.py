
from linkedList import Node
from linkedList import LinkedList

class SortLinkedList:
    def __init__(self):
        self.debug_count = 0
        return

    def sortedMerge(self, a, b):
        if a is None:
            return b
        
        if b is None:
            return a

        if a.data < b.data:
            a.next = self.sortedMerge(a.next, b)
            return a
        else:
            b.next = self.sortedMerge(a, b.next)
            return b


    def splitList(self, head):
        fast = slow = head

        if head is None or head.next is None:
            return None, None

        while fast.next is not None:
            fast = fast.next

            if fast.next is not None:
                fast = fast.next
                slow = slow.next

        a = head
        b = slow.next
        slow.next = None

        return a, b

    def mergeSort(self, head):

        if head is None or head.next is None:
            return head
        
        a, b = self.splitList(head)

        a = self.mergeSort(a)
        b = self.mergeSort(b)
        
        return self.sortedMerge(a, b)

    def quickSortUtil(self, head):
        pivot = head

        if head is None or head.next is None:
            return head, head, head

        head = head.next
        pivot.next = None

        itr = head
        prev = None
        less_than_pivot = head
        last_of_less_than_pivot = None

        while itr is not None:
            if itr.data < pivot.data:
                if itr is less_than_pivot or prev is None:
                    last_of_less_than_pivot = less_than_pivot
                else:
                    prev.next = itr.next
                    itr.next = less_than_pivot
                    less_than_pivot = itr
                    itr = prev

                    if last_of_less_than_pivot is None:
                        last_of_less_than_pivot = less_than_pivot
                
            prev = itr
            itr = itr.next

                
        listA = less_than_pivot
        listB = last_of_less_than_pivot.next
        last_of_less_than_pivot.next = None

        return listA, listB, pivot

    def quickSort(self, head):
        if head is not None and head.next is not None:

            listA, listB, pivot = self.quickSortUtil(head)

            # print(self.debug_count)
            # self.debug_count += 1

            listA = self.quickSort(listA)
            listB = self.quickSort(listB)

            temp = listA
            while temp.next is not None:
                temp = temp.next

            temp.next = pivot
            pivot.next = listB

            return listA
        else:
            return head
    
if __name__ == '__main__':
    ll = LinkedList()
    ll_sort = SortLinkedList()

    ll.append(156)
    ll.append(4345)
    ll.append(45)
    ll.append(455)
    ll.push(10)
    ll.push(2060)
    ll.push(30)

    print("Unsorted: ")
    ll.printList()

    #h = ll_sort.mergeSort(ll.getHead())
    h = ll_sort.quickSort(ll.getHead())

    print("Sorted: ")
    ll.printList(h)