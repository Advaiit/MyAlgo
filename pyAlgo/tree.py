
import queue

class TreeNode:
    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None

def maxOfArray(array):
    max = -999
    for i in range(len(array)):
        if max < array[i]:
            max = array[i]
    
    return max

class Tree:
    def __init__(self, key=None):
        if key is not None:
            self.rootNode = TreeNode(key)
        else:
            self.rootNode = None

    #Level order insert
    def insert(self, key):
        newNode = TreeNode(key)
        q = queue.Queue()
        q.put(self.rootNode)

        while q.empty() is not True:
            temp = q.get()

            if temp.left is None:
                temp.left = newNode
                return
            elif temp.right is None:
                temp.right = newNode
                return
            else:
                q.put(temp.left)
                q.put(temp.right)
        
        return

    def preorderTraverse(self, root):
        if root is not None:
            print(root.data, end=" ")
            self.preorderTraverse(root.left)
            self.preorderTraverse(root.right)

    def preorderPrint(self):
        print("Preorder traversal: ", end=" ")
        self.preorderTraverse(self.rootNode)
        print("\n")
        
    def isLeafNode(self, node):
        return node.left is None and node.right is None

    def deleteLeafNode(self, node, x_node):
        if not self.isLeafNode(x_node):
            print ("x_node is not leaf node")

        if node is not None:
            if node.left == x_node:
                node.left = None
            elif node.right == x_node:
                node.right = None
            else:
                self.deleteLeafNode(node.left, x_node)
                self.deleteLeafNode(node.right, x_node)

    #Replaces with data of last node and deletes last node
    def delete(self, key):
        key_node = None
        temp = None
        q = queue.Queue()

        q.put(self.rootNode)

        while q.empty() is not True:
            temp = q.get()

            if temp.data == key and key_node is None:
                key_node = temp
            
            if temp.left is not None:
                q.put(temp.left)
            if temp.right is not None:
                q.put(temp.right)

        key_node.data = temp.data
        self.deleteLeafNode(self.rootNode, temp)
        return

    # def constructFromArray(self, array):
    #     if self.rootNode is not None:
    #         print("root already initiated")
        
    #     assert(array is not None), "parent array is None"\

    #     array_len = len(array)
    #     self.rootNode = TreeNode(array[0])

    #     q = queue.Queue()
    #     q.put(self.rootNode)

    #     i = 0
    #     while q.empty() is not True:
    #         temp = q.get()
    #         print (temp.data)

    #         left_index = (i * 2) + 1
    #         right_index = (i * 2) + 2

    #         while array[i] == -2:
    #             i += 1

    #         if left_index < array_len and array[left_index] != -2:
    #             temp.left = TreeNode(array[left_index])
    #             q.put(temp.left)
            
    #         while array[i] == -2:
    #             i += 1

    #         if right_index < array_len and array[right_index] != -2:
    #             temp.right = TreeNode(array[right_index])
    #             q.put(temp.right)
            
    #         i += 1

    # def constructFromParentArray(self, parent_array):
    #     def getParentIndex(i):
    #         if parent_array[parent_array[i]] == -1:
    #             return 0
    #         else:
    #             return parent_array[i]

    #     if self.rootNode is not None:
    #         print("root already initiated")

    #     assert(parent_array is not None), "parent array is None"
        
    #     array_len = len(parent_array)
    #     array_tree = [-2 for i in range(maxOfArray(parent_array) * 2 + 3)]

    #     #Convert parent array into array tree
    #     for i in range(array_len):
    #         if parent_array[i] == -1:
    #             array_tree[0] = i
    #         elif array_tree[(getParentIndex(i) * 2) + 1] == -2:
    #             array_tree[getParentIndex(i) * 2 + 1] = i
    #         elif array_tree[(getParentIndex(i) * 2) + 2] == -2:
    #             array_tree[getParentIndex(i) * 2 + 2] = i

    #     print("Array Tree: ", array_tree)

    #     #Convert array tree into linked tree
    #     self.constructFromArray(array_tree)
    
    def putInDiagonalList(self, list, data, leftCount, rightCount):
        while list[leftCount][rightCount] != -1:
            rightCount += 1
        list[leftCount][rightCount] = data

    def diagonalTraverseUtil(self,node, list, leftCount, rightCount):
        if node is not None:
            self.putInDiagonalList(list, node.data, leftCount, rightCount)
            self.diagonalTraverseUtil(node.left, list, leftCount + 1, rightCount)
            self.diagonalTraverseUtil(node.right, list, leftCount, rightCount + 1)

    def diagonalTraversal(self):
        l = [[-1 for i in range(10)] for j in range(10)]
        self.diagonalTraverseUtil(self.rootNode, l, 0, 0)

        for i in range(10):
            for j in range(10):
                if l[i][j] != -1:
                    print(l[i][j], end=" ")
            print(" ")

        return

if __name__=='__main__':
    t = Tree(0)
    t1 = Tree()
    
    for i in range(1, 10):
        t.insert(i)

    print("Diagonal Traversal")

    t.diagonalTraversal()

    # parent_array = [1, 5, 5, 2, 2, -1, 3]

    # t1.constructFromParentArray(parent_array)

    # t1.preorderPrint()

    # print("Delete 3")
    # t.delete(3)

    # print("Delete 9")
    # t.delete(9)

    # t.preorderPrint()

