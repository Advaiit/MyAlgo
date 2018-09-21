
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

    def inorderTraverse(self, root):
        if root is not None:
            self.inorderTraverse(root.left)
            print(root.data, end=" ")
            self.inorderTraverse(root.right)

    def inorderPrint(self):
        print("Inorder traversal: ", end=" ")
        self.inorderTraverse(self.rootNode)
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

