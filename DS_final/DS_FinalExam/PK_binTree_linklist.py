class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.value = key

def insert(root, key):
    if root is None:
        return Node(key)
    else:
        # 確保處理重複值：這裡我們選擇將重複值放到右邊
        if root.value <= key:
            root.right = insert(root.right, key)
        else:
            root.left = insert(root.left, key)
    return root

def tree_height(node):
    if node is None:
        return 0
    else:
        left_height = tree_height(node.left)
        right_height = tree_height(node.right)
        return max(left_height, right_height) + 1

# 從標準輸入讀取數據
m = int(input())
values = list(map(int, input().split()))

# 創建並計算二元搜尋樹的高度
root = None
for value in values:
    root = insert(root, value)

height = tree_height(root)
print(height)
