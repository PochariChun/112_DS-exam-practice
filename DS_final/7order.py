class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def inorder_to_preorder(root):
    """
    将中序遍历转换为前序遍历

    参数：
    - root：二叉树的根节点

    返回值：
    - 前序遍历结果的列表
    """
    if root is None:
        return []
    result = []
    result.append(root.value)
    result += inorder_to_preorder(root.left)
    result += inorder_to_preorder(root.right)
    return result

def inorder_to_postorder(root):
    """
    将中序遍历转换为后序遍历

    参数：
    - root：二叉树的根节点

    返回值：
    - 后序遍历结果的列表
    """
    if root is None:
        return []
    result = []
    result += inorder_to_postorder(root.left)
    result += inorder_to_postorder(root.right)
    result.append(root.value)
    return result

def build_tree(inorder, preorder):
    """
    根据中序和前序遍历构建二叉树

    参数：
    - inorder：中序遍历结果的列表
    - preorder：前序遍历结果的列表

    返回值：
    - 构建的二叉树的根节点
    """
    if not inorder or not preorder:
        return None
    root_value = preorder[0]
    root = TreeNode(root_value)
    root_index = inorder.index(root_value)
    root.left = build_tree(inorder[:root_index], preorder[1:root_index + 1])
    root.right = build_tree(inorder[root_index + 1:], preorder[root_index + 1:])
    return root

def build_tree_post(inorder, postorder):
    """
    根据中序和后序遍历构建二叉树

    参数：
    - inorder：中序遍历结果的列表
    - postorder：后序遍历结果的列表

    返回值：
    - 构建的二叉树的根节点
    """
    if not inorder or not postorder:
        return None
    root_value = postorder[-1]
    root = TreeNode(root_value)
    root_index = inorder.index(root_value)
    root.left = build_tree_post(inorder[:root_index], postorder[:root_index])
    root.right = build_tree_post(inorder[root_index + 1:], postorder[root_index:-1])
    return root

# 示例用法
inorder = [4, 2, 5, 1, 6, 3, 7]
preorder = [1, 2, 4, 5, 3, 6, 7]
postorder = [4, 5, 2, 6, 7, 3, 1]

root_pre = build_tree(inorder, preorder)
root_post = build_tree_post(inorder, postorder)

pre_order = inorder_to_preorder(root_pre)
post_order = inorder_to_postorder(root_post)

print("前序遍历结果：", pre_order)
print("后序遍历结果：", post_order)
##########################################################
# 实现操作符的优先级
def precedence(op):
    if op in "+-":
        return 1
    if op in "*/":
        return 2
    return 0

# 中序表达式转换为前序表达式
def infix_to_prefix(expression):
    operators = []
    output = []
    
    for token in reversed(expression):
        if token.isalnum():  # 操作数直接输出
            output.append(token)
        elif token == ')':
            operators.append(token)
        elif token == '(':
            while operators and operators[-1] != ')':
                output.append(operators.pop())
            operators.pop()  # 弹出 '('
        else:
            while operators and precedence(operators[-1]) >= precedence(token):
                output.append(operators.pop())
            operators.append(token)
    
    while operators:
        output.append(operators.pop())
    
    return ''.join(reversed(output))

# 中序表达式转换为后序表达式
def infix_to_postfix(expression):
    operators = []
    output = []
    
    for token in expression:
        if token.isalnum():  # 操作数直接输出
            output.append(token)
        elif token == '(':
            operators.append(token)
        elif token == ')':
            while operators and operators[-1] != '(':
                output.append(operators.pop())
            operators.pop()  # 弹出 '('
        else:
            while operators and precedence(operators[-1]) >= precedence(token):
                output.append(operators.pop())
            operators.append(token)
    
    while operators:
        output.append(operators.pop())
    
    return ''.join(output)

# 前序表达式计算
def evaluate_prefix(expression):
    stack = []
    for token in reversed(expression):
        if token.isalnum():  # 操作数入栈
            stack.append(int(token))
        else:
            operand1 = stack.pop()
            operand2 = stack.pop()
            if token == '+':
                stack.append(operand1 + operand2)
            elif token == '-':
                stack.append(operand1 - operand2)
            elif token == '*':
                stack.append(operand1 * operand2)
            elif token == '/':
                stack.append(operand1 / operand2)
    return stack[0]

# 后序表达式计算
def evaluate_postfix(expression):
    stack = []
    for token in expression:
        if token.isalnum():  # 操作数入栈
            stack.append(int(token))
        else:
            operand2 = stack.pop()
            operand1 = stack.pop()
            if token == '+':
                stack.append(operand1 + operand2)
            elif token == '-':
                stack.append(operand1 - operand2)
            elif token == '*':
                stack.append(operand1 * operand2)
            elif token == '/':
                stack.append(operand1 / operand2)
    return stack[0]

# 示例用法
infix_expression = "A+B*C-(D/E+F)*G"
prefix_expression = infix_to_prefix(infix_expression)
postfix_expression = infix_to_postfix(infix_expression)

print("中序表达式:", infix_expression)
print("前序表达式:", prefix_expression)
print("后序表达式:", postfix_expression)

variables = {'A': 1, 'B': 2, 'C': 3, 'D': 4, 'E': 5, 'F': 6, 'G': 7}

result_prefix = evaluate_prefix(prefix_expression)
result_postfix = evaluate_postfix(postfix_expression)

print("前序表达式计算结果:", result_prefix)
print("后序表达式计算结果:", result_postfix)
