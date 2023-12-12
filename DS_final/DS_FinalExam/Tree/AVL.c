/* AVL 樹節點結構體 */
TreeNode struct TreeNode {
    int val;
    int height;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

/* 構造函數 */
TreeNode *newTreeNode(int val) {
    TreeNode *node;

    node = (TreeNode *)malloc(sizeof(TreeNode));
    node->val = val;
    node->height = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* 獲取節點高度 */
int height(TreeNode *node) {
    // 空節點高度為 -1 ，葉節點高度為 0
    if (node != NULL) {
        return node->height;
    }
    return -1;
}

/* 更新節點高度 */
void updateHeight(TreeNode *node) {
    int lh = height(node->left);
    int rh = height(node->right);
    // 節點高度等於最高子樹高度 + 1
    if (lh > rh) {
        node->height = lh + 1;
    } else {
        node->height = rh + 1;
    }
}

/* 獲取平衡因數 */
int balanceFactor(TreeNode *node) {
    // 空節點平衡因數為 0
    if (node == NULL) {
        return 0;
    }
    // 節點平衡因數 = 左子樹高度 - 右子樹高度
    return height(node->left) - height(node->right);
}

/* 右旋操作 */
TreeNode *rightRotate(TreeNode *node) {
    TreeNode *child, *grandChild;
    child = node->left;
    grandChild = child->right;
    // 以 child 為原點，將 node 向右旋轉
    child->right = node;
    node->left = grandChild;
    // 更新節點高度
    updateHeight(node);
    updateHeight(child);
    // 返回旋轉後子樹的根節點
    return child;
}

/* 左旋操作 */
TreeNode *leftRotate(TreeNode *node) {
    TreeNode *child, *grandChild;
    child = node->right;
    grandChild = child->left;
    // 以 child 為原點，將 node 向左旋轉
    child->left = node;
    node->right = grandChild;
    // 更新節點高度
    updateHeight(node);
    updateHeight(child);
    // 返回旋轉後子樹的根節點
    return child;
}

/* 執行旋轉操作，使該子樹重新恢復平衡 */
TreeNode *rotate(TreeNode *node) {
    // 獲取節點 node 的平衡因數
    int bf = balanceFactor(node);
    // 左偏樹
    if (bf > 1) {
        if (balanceFactor(node->left) >= 0) {
            // 右旋
            return rightRotate(node);
        } else {
            // 先左旋後右旋
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    // 右偏樹
    if (bf < -1) {
        if (balanceFactor(node->right) <= 0) {
            // 左旋
            return leftRotate(node);
        } else {
            // 先右旋後左旋
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }
    // 平衡樹，無須旋轉，直接返回
    return node;
}

/* 插入節點 */
void insert(AVLTree *tree, int val) {
    tree->root = insertHelper(tree->root, val);
}

/* 遞迴插入節點（輔助函數） */
TreeNode *insertHelper(TreeNode *node, int val) {
    if (node == NULL) {
        return newTreeNode(val);
    }
    /* 1. 查找插入位置，並插入節點 */
    if (val < node->val) {
        node->left = insertHelper(node->left, val);
    } else if (val > node->val) {
        node->right = insertHelper(node->right, val);
    } else {
        // 重複節點不插入，直接返回
        return node;
    }
    // 更新節點高度
    updateHeight(node);
    /* 2. 執行旋轉操作，使該子樹重新恢復平衡 */
    node = rotate(node);
    // 返回子樹的根節點
    return node;
}

/* 刪除節點 */
// 由於引入了 stdio.h ，此處無法使用 remove 關鍵字
void removeItem(AVLTree *tree, int val) {
    TreeNode *root = removeHelper(tree->root, val);
}

/* 遞迴刪除節點（輔助函數） */
TreeNode *removeHelper(TreeNode *node, int val) {
    TreeNode *child, *grandChild;
    if (node == NULL) {
        return NULL;
    }
    /* 1. 查找節點，並刪除之 */
    if (val < node->val) {
        node->left = removeHelper(node->left, val);
    } else if (val > node->val) {
        node->right = removeHelper(node->right, val);
    } else {
        if (node->left == NULL || node->right == NULL) {
            child = node->left;
            if (node->right != NULL) {
                child = node->right;
            }
            // 子節點數量 = 0 ，直接刪除 node 並返回
            if (child == NULL) {
                return NULL;
            } else {
                // 子節點數量 = 1 ，直接刪除 node
                node = child;
            }
        } else {
            // 子節點數量 = 2 ，則將中序遍歷的下個節點刪除，並用該節點替換當前節點
            TreeNode *temp = node->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            int tempVal = temp->val;
            node->right = removeHelper(node->right, temp->val);
            node->val = tempVal;
        }
    }
    // 更新節點高度
    updateHeight(node);
    /* 2. 執行旋轉操作，使該子樹重新恢復平衡 */
    node = rotate(node);
    // 返回子樹的根節點
    return node;
}

