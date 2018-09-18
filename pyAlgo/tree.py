
import queue

class TreeNode:
    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None


class Tree:

    def __init__(self, key):
        self.rootNode = TreeNode(key)

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
        
#@TODO: Complete delete function
    def delete(self, key):
        return False

if __name__=='__main__':
    t = Tree(0)
    
    for i in range(1, 10):
        t.insert(i)
    
    t.preorderPrint()
