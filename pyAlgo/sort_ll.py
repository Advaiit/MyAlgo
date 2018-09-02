
from linkedList import Node
from linkedList import LinkedList

class SortLinkedList:
    def __init__(self):
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

    h = ll_sort.mergeSort(ll.getHead())

    print("Sorted: ")
    ll.printList(h)