/* 二叉樹節點結構體 */
typedef struct TreeNode {
    int val;                // 節點值
    int height;             // 節點高度
    struct TreeNode *left;  // 左子節點指針
    struct TreeNode *right; // 右子節點指針
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

/* 初始化二叉樹 */
// 初始化節點
TreeNode *n1 = newTreeNode(1);
TreeNode *n2 = newTreeNode(2);
TreeNode *n3 = newTreeNode(3);
TreeNode *n4 = newTreeNode(4);
TreeNode *n5 = newTreeNode(5);
// 構建節點之間的引用（指針）
n1->left = n2;
n1->right = n3;
n2->left = n4;
n2->right = n5;

/* 層序遍歷 */
int *levelOrder(TreeNode *root, int *size) {
    /* 輔助佇列 */
    int front, rear;
    int index, *arr;
    TreeNode *node;
    TreeNode **queue;

    /* 輔助佇列 */
    queue = (TreeNode **)malloc(sizeof(TreeNode *) * MAX_SIZE);
    // 佇列指標
    front = 0, rear = 0;
    // 加入根節點
    queue[rear++] = root;
    // 初始化一個列表，用於保存遍歷序列
    /* 輔助陣列 */
    arr = (int *)malloc(sizeof(int) * MAX_SIZE);
    // 陣列指標
    index = 0;
    while (front < rear) {
        // 佇列出隊
        node = queue[front++];
        // 保存節點值
        arr[index++] = node->val;
        if (node->left != NULL) {
            // 左子節點入隊
            queue[rear++] = node->left;
        }
        if (node->right != NULL) {
            // 右子節點入隊
            queue[rear++] = node->right;
        }
    }
    // 更新陣列長度的值
    *size = index;
    arr = realloc(arr, sizeof(int) * (*size));

    // 釋放輔助陣列空間
    free(queue);
    return arr;
}

/* 前序遍歷 */
void preOrder(TreeNode *root, int *size) {
    if (root == NULL)
        return;
    // 訪問優先順序：根節點 -> 左子樹 -> 右子樹
    arr[(*size)++] = root->val;
    preOrder(root->left, size);
    preOrder(root->right, size);
}

/* 中序遍歷 */
void inOrder(TreeNode *root, int *size) {
    if (root == NULL)
        return;
    // 訪問優先順序：左子樹 -> 根節點 -> 右子樹
    inOrder(root->left, size);
    arr[(*size)++] = root->val;
    inOrder(root->right, size);
}

/* 後序遍歷 */
void postOrder(TreeNode *root, int *size) {
    if (root == NULL)
        return;
    // 訪問優先順序：左子樹 -> 右子樹 -> 根節點
    postOrder(root->left, size);
    postOrder(root->right, size);
    arr[(*size)++] = root->val;
}

/* 陣列表示下的二叉樹結構體 */
typedef struct {
    int *tree;
    int size;
} ArrayBinaryTree;

/* 構造函數 */
ArrayBinaryTree *newArrayBinaryTree(int *arr, int arrSize) {
    ArrayBinaryTree *abt = (ArrayBinaryTree *)malloc(sizeof(ArrayBinaryTree));
    abt->tree = malloc(sizeof(int) * arrSize);
    memcpy(abt->tree, arr, sizeof(int) * arrSize);
    abt->size = arrSize;
    return abt;
}

/* 析構函數 */
void delArrayBinaryTree(ArrayBinaryTree *abt) {
    free(abt->tree);
    free(abt);
}

/* 節點數量 */
int size(ArrayBinaryTree *abt) {
    return abt->size;
}

/* 獲取索引為 i 節點的值 */
int val(ArrayBinaryTree *abt, int i) {
    // 若索引越界，則返回 INT_MAX ，代表空位
    if (i < 0 || i >= size(abt))
        return INT_MAX;
    return abt->tree[i];
}

/* 層序遍歷 */
int *levelOrder(ArrayBinaryTree *abt, int *returnSize) {
    int *res = (int *)malloc(sizeof(int) * size(abt));
    int index = 0;
    // 直接遍歷陣列
    for (int i = 0; i < size(abt); i++) {
        if (val(abt, i) != INT_MAX)
            res[index++] = val(abt, i);
    }
    *returnSize = index;
    return res;
}

/* 深度優先遍歷 */
void dfs(ArrayBinaryTree *abt, int i, char *order, int *res, int *index) {
    // 若為空位，則返回
    if (val(abt, i) == INT_MAX)
        return;
    // 前序遍歷
    if (strcmp(order, "pre") == 0)
        res[(*index)++] = val(abt, i);
    dfs(abt, left(i), order, res, index);
    // 中序遍歷
    if (strcmp(order, "in") == 0)
        res[(*index)++] = val(abt, i);
    dfs(abt, right(i), order, res, index);
    // 後序遍歷
    if (strcmp(order, "post") == 0)
        res[(*index)++] = val(abt, i);
}

/* 前序遍歷 */
int *preOrder(ArrayBinaryTree *abt, int *returnSize) {
    int *res = (int *)malloc(sizeof(int) * size(abt));
    int index = 0;
    dfs(abt, 0, "pre", res, &index);
    *returnSize = index;
    return res;
}

/* 中序遍歷 */
int *inOrder(ArrayBinaryTree *abt, int *returnSize) {
    int *res = (int *)malloc(sizeof(int) * size(abt));
    int index = 0;
    dfs(abt, 0, "in", res, &index);
    *returnSize = index;
    return res;
}

/* 後序遍歷 */
int *postOrder(ArrayBinaryTree *abt, int *returnSize) {
    int *res = (int *)malloc(sizeof(int) * size(abt));
    int index = 0;
    dfs(abt, 0, "post", res, &index);
    *returnSize = index;
    return res;
}


