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


if __name__=='__main__':
    postfix = "ab+ef*g*-"
    t = Tree()
    e_t = ExpressionTree()
    t.inorderTraverse(e_t.constructFromPostfix(postfix))
    print("\n")