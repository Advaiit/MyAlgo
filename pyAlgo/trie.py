
NUM_CHARS = 26

def char_to_index(c):
    if c >= 'a' and c <= 'z':
        return ord(c) - ord('a')
    #@TODO: Add conditions for capital letters and invalids

class TrieNode:
    def __init__(self):
        self.nodes = [None for i in range(NUM_CHARS)]
        self.isLeaf = False

class Trie:
    def __init__(self):
        self.rootNode = TrieNode()

    def insertString(self, str):
        assert(str is not None), "String is not valid"
        
        strLen = len(str)
        temp = self.rootNode

        for i in range(strLen):
            index = char_to_index(str[i])

            if temp.nodes[index] is None:
                temp.nodes[index] = TrieNode()
            
            temp = temp.nodes[index]
        
        temp.isLeaf = True

        return True

    def isFreeNode(self, node):
        assert(node is not None), "Node is invalid"

        for i in range(NUM_CHARS):
            if node.nodes[i] is not None:
                return False
        
        return True

    def searchString(self, str):
        assert(str is not None), "String is not valid"

        strLen = len(str)
        temp = self.rootNode

        for i in range(strLen):
            index = char_to_index(str[i])

            if temp.nodes[index] is None:
                return False
            
            temp = temp.nodes[index]

        return temp.isLeaf

    def deleteStringUtil(self, node, str, count, strLen):
        assert(str is not None), "String is not valid"

        if count == strLen:
            if node.isLeaf is False:
                return False
            
            node.isLeaf = False

            if(self.isFreeNode(node)):
                return True
            
            return False
        
        else:
            index = char_to_index(str[count])

            if node.nodes[index] is None:
                return False

            if self.deleteStringUtil(node.nodes[index], str, count+1, strLen):
                node.nodes[index] = None
                return  not node.isLeaf and self.isFreeNode(node)
            else:
                return False


    def deleteString(self, str):
        return self.deleteStringUtil(self.rootNode, str, 0, len(str))

if __name__ == '__main__':
    t = Trie()

    strArray = ["hello", "how", "house", "jug", "jugger"]

    for i in range(len(strArray)):
        t.insertString(strArray[i])
    
    print("Search string", strArray[0], "result: ", t.searchString(strArray[0]))
    print("Search string", strArray[1], "result: ", t.searchString(strArray[1]))
    print("Search string", strArray[2], "result: ", t.searchString(strArray[2]))
    print("Search string", strArray[3], "result: ", t.searchString(strArray[3]))
    print("Search string", strArray[4], "result: ", t.searchString(strArray[4]))
    print("Search string", "xyz", "result: ", t.searchString("xyz"))

    # print ("deleting jugger")
    # t.deleteString("jugger")

    print ("deleting jug")
    t.deleteString("jug")

    print ("deleting hello")
    t.deleteString("hello")

    print("Search string", strArray[0], "result: ", t.searchString(strArray[0]))
    print("Search string", strArray[1], "result: ", t.searchString(strArray[1]))
    print("Search string", strArray[2], "result: ", t.searchString(strArray[2]))
    print("Search string", strArray[3], "result: ", t.searchString(strArray[3]))
    print("Search string", strArray[4], "result: ", t.searchString(strArray[4]))


