/* 查找節點 */
TreeNode *search(BinarySearchTree *bst, int num) {
    TreeNode *cur = bst->root;
    // 迴圈查找，越過葉節點後跳出
    while (cur != NULL) {
        if (cur->val < num) {
            // 目標節點在 cur 的右子樹中
            cur = cur->right;
        } else if (cur->val > num) {
            // 目標節點在 cur 的左子樹中
            cur = cur->left;
        } else {
            // 找到目標節點，跳出迴圈
            break;
        }
    }
    // 返回目標節點
    return cur;
}

/* 插入節點 */
void insert(BinarySearchTree *bst, int num) {
    // 若樹為空，則初始化根節點
    if (bst->root == NULL) {
        bst->root = newTreeNode(num);
        return;
    }
    TreeNode *cur = bst->root, *pre = NULL;
    // 迴圈查找，越過葉節點後跳出
    while (cur != NULL) {
        // 找到重複節點，直接返回
        if (cur->val == num) {
            return;
        }
        pre = cur;
        if (cur->val < num) {
            // 插入位置在 cur 的右子樹中
            cur = cur->right;
        } else {
            // 插入位置在 cur 的左子樹中
            cur = cur->left;
        }
    }
    // 插入節點
    TreeNode *node = newTreeNode(num);
    if (pre->val < num) {
        pre->right = node;
    } else {
        pre->left = node;
    }
}

/* 刪除節點 */
// 由於引入了 stdio.h ，此處無法使用 remove 關鍵字
void removeItem(BinarySearchTree *bst, int num) {
    // 若樹為空，直接提前返回
    if (bst->root == NULL)
        return;
    TreeNode *cur = bst->root, *pre = NULL;
    // 迴圈查找，越過葉節點後跳出
    while (cur != NULL) {
        // 找到待刪除節點，跳出迴圈
        if (cur->val == num)
            break;
        pre = cur;
        if (cur->val < num) {
            // 待刪除節點在 root 的右子樹中
            cur = cur->right;
        } else {
            // 待刪除節點在 root 的左子樹中
            cur = cur->left;
        }
    }
    // 若無待刪除節點，則直接返回
    if (cur == NULL)
        return;
    // 判斷待刪除節點是否存在子節點
    if (cur->left == NULL || cur->right == NULL) {
        /* 子節點數量 = 0 or 1 */
        // 當子節點數量 = 0 / 1 時， child = nullptr / 該子節點
        TreeNode *child = cur->left != NULL ? cur->left : cur->right;
        // 刪除節點 cur
        if (pre->left == cur) {
            pre->left = child;
        } else {
            pre->right = child;
        }
    } else {
        /* 子節點數量 = 2 */
        // 獲取中序遍歷中 cur 的下一個節點
        TreeNode *tmp = cur->right;
        while (tmp->left != NULL) {
            tmp = tmp->left;
        }
        int tmpVal = tmp->val;
        // 遞迴刪除節點 tmp
        removeItem(bst, tmp->val);
        // 用 tmp 覆蓋 cur
        cur->val = tmpVal;
    }
}

