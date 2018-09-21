from tree import TreeNode
from tree import Tree

class ExpressionTree:
    def __init__(self):
        self.rootNode = None
    
    def isOperator(self, x):
        return x == '+' or x == '-' or x == '/' or x == '*'

    def constructFromPostfix(self, postfix_expr):
        exp_stack = []

        for i in range(len(postfix_expr)):
            if(self.isOperator(postfix_expr[i])):
                temp = TreeNode(postfix_expr[i])

                assert(not exp_stack == []), "Recheck given postfix expression"
                temp.right = exp_stack.pop()

                assert(not exp_stack == []), "Recheck given postfix expression"
                temp.left = exp_stack.pop()

                exp_stack.append(temp)
            else:
                exp_stack.append(TreeNode(postfix_expr[i]))
            
        self.rootNode = exp_stack.pop()
        return self.rootNode
    
    def operation(self, operator, var1, var2):
        if operator == '+':
            return var1 + var2
        elif operator == '-':
            return var1 - var2
        elif operator == '*':
            return var1 * var2
        elif operator == '/':
            return var1 / var2

    def evaluateUtil(self, root):
        assert(root is not None), "Invalid expression tree"

        if root.left is None and root.right is None:
            return int(root.data)
        
        return self.operation(root.data, self.evaluateUtil(root.left), self.evaluateUtil(root.right))

    def evaluate(self):
        return self.evaluateUtil(self.rootNode)

if __name__=='__main__':
    postfix = "92+21*3*-"
    t = Tree()
    e_t = ExpressionTree()
    t.inorderTraverse(e_t.constructFromPostfix(postfix))
    print("\n")
    print("Evaluation: ", e_t.evaluate())