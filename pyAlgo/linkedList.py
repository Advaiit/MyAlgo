class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def push(self, val):
        new_node = Node(val)
        new_node.next = self.head
        self.head = new_node

    def append(self, val):
        new_node = Node(val)  

        if self.head is None:
            self.head = new_node
            return            

        temp = self.head

        while temp.next is not None:
            temp = temp.next
        
        temp.next = new_node

    def printList(self, h=None):
        if h is None:
            if self.head is None:
                print('Linked list is empty')
                return
        
        cur = self.head if h is None else h

        while cur:
            print(cur.data, end="==>")
            cur = cur.next
        print("\n")
    
    def reverseLinkedListUtil(self, h):
        if h is None:
            return None

        if h.next is None:
            self.head = h
            return h

        result = self.reverseLinkedListUtil(h.next)

        result.next = h

        return h
    
    def reverseLinkedListR(self):
        new_head = self.reverseLinkedListUtil(self.head).next = None
        return new_head

    def reverseLinkedListI(self):
        cur = self.head
        prev = None

        if cur is None:
            return

        while cur is not None:
            next = cur.next
            cur.next = prev
            prev = cur
            cur = next
        
        self.head = prev

    def printMiddle(self):
        slow = fast = self.head

        if self.head is None or self.head.next is None:
            return
        
        while fast and fast.next is not None:
            slow = slow.next
            fast = fast.next
            if fast is not None:
                fast = fast.next
        
        return slow.data

    def swapNodes(self, x, y):
        node1 = self.head
        node2 = self.head

        while  node1 is not None and node1.data != int(x):
            prev1 = node1
            node1 = node1.next

        while node2 is not None and node2.data != int(y):
            prev2 = node2
            node2 = node2.next
        
        if node1 is None or node2 is None:
            return
        
        prev1.next = node2
        prev2.next = node1

        temp = node1.next
        node1.next = node2.next
        node2.next = temp
    
    def reverseInGroupsUtil(self, h, k):
        count = k

        if h is None:
            return None

        node = h
        prev = None
        next = None

        while count != 0 and node is not None:
            next = node.next
            node.next = prev
            prev = node
            node = next
            count -= 1

        h.next = self.reverseInGroupsUtil(next, k)

        return prev
    
    def reverseInGroups(self, k):
        self.head = self.reverseInGroupsUtil(self.head, k)

    def getHead(self):
        return self.head
    
    def setHead(self, h):
        self.head = h

    def isPalindromeUtil(self, list_1, list_2):
        if list_1.next is None:
            if list_1.data == list_2.data:
                return list_2.next, True
            else:
                return list_2.next, False
            
        list_2, is_palindrome = self.isPalindromeUtil(list_1.next, list_2)

        if list_1.data == list_2.data and is_palindrome:
            return list_2.next, True
        else:
            return list_2.next, False

    def isPalindrome(self):
        _, is_p = self.isPalindromeUtil(self.head, self.head)
        return is_p       
    
    #Create new list that is union of list_1 and list_2
    def union(self, list_1, list_2):
        assert(list_1 is not None and list_2 is not None), "Atleast one of the list is invalid"

        h_map = {}
        temp = list_1

        while temp is not None:
            h_map[temp.data] = [1, 0] if temp.data not in h_map else [h_map[temp.data][0] + 1, 0]
            temp = temp.next
        
        temp = list_2

        while temp is not None:
            h_map[temp.data] = [0, 1] if temp.data not in h_map else [h_map[temp.data][0],h_map[temp.data][1] + 1]
            temp = temp.next
        
        print(h_map)
        
        for key in h_map:
            maxKeyCount = max(h_map[key][0], h_map[key][1])
            while maxKeyCount > 0:
                self.append(key)
                maxKeyCount -= 1

    #Create new list that is intersection of list_1 and list_2
    def intersect(self, list_1, list_2):
        assert(list_1 is not None and list_2 is not None), "Atleast one of the list is invalid"

        h_map = {}
        temp = list_1

        while temp is not None:
            h_map[temp.data] = 1 if temp.data not in h_map else h_map[temp.data] + 1
            temp = temp.next
        
        temp = list_2

        while temp is not None:
            if temp.data in h_map:
                self.append(temp.data)
                h_map[temp.data] -= 1
                if temp.data == 0:
                    del h_map[temp.data] 
            temp = temp.next

if __name__ == '__main__':
    ll = LinkedList()

    ll.append(1)
    ll.append(2)
    ll.append(3)
    ll.append(4)
    ll.append(3)
    ll.append(2)
    ll.append(1)

    ll2 = LinkedList()

    ll2.append(67)
    ll2.append(76)
    ll2.append(11)
    ll2.append(99)
    ll2.append(3)
    ll2.append(4)
    ll2.append(3)
    ll2.append(2)

    ll3 = LinkedList()

    print("List 1: ")
    ll.printList()

    print("List 2: ")
    ll2.printList()

    ll3.intersect(ll.getHead(), ll2.getHead())

    print("List 3: ")
    ll3.printList()
    
    #ll3.printList()

    #ll.printList()

    #print('IsPalindrome: ', ll.isPalindrome())

    #print('Reversing LinkedList')
    #ll.reverseLinkedListR()
    #ll.reverseLinkedListI()

    #print("LL middle: ", ll.printMiddle())

    #ll.swapNodes(2, 200)

    #ll.reverseInGroups(3)

    #ll.printList()