/* 鏈表節點結構體 */
typedef struct ListNode {
    int val;               // 節點值
    struct ListNode *next; // 指向下一節點的指標
} ListNode;

/* 構造函數 */
ListNode *newListNode(int val) {
    ListNode *node;
    node = (ListNode *) malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

/*初始化*/
/* 初始化鏈表 1 -> 3 -> 2 -> 5 -> 4 */
// 初始化各個節點
ListNode* n0 = newListNode(1);
ListNode* n1 = newListNode(3);
ListNode* n2 = newListNode(2);
ListNode* n3 = newListNode(5);
ListNode* n4 = newListNode(4);
// 構建節點之間的引用
n0->next = n1;
n1->next = n2;
n2->next = n3;
n3->next = n4;

/* 插入：在鏈表的節點 n0 之後插入節點 P */
void insert(ListNode *n0, ListNode *P) {
    ListNode *n1 = n0->next;
    P->next = n1;
    n0->next = P;
}

/* 刪除：刪除鏈表的節點 n0 之後的首個節點 */
// 注意：stdio.h 佔用了 remove 關鍵字
void removeItem(ListNode *n0) {
    if (!n0->next)
        return;
    // n0 -> P -> n1
    ListNode *P = n0->next;
    ListNode *n1 = P->next;
    n0->next = n1;
    // 釋放記憶體
    free(P);
}

/* 訪問：鏈表中索引為 index 的節點 */
ListNode *access(ListNode *head, int index) {
    while (head && head->next && index) {
        head = head->next;
        index--;
    }
    return head;
}

/* 查找：在鏈表中查找值為 target 的首個節點 */
int find(ListNode *head, int target) {
    int index = 0;
    while (head) {
        if (head->val == target)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}


/* 雙向：雙向鏈表節點結構體 */
typedef struct ListNode {
    int val;               // 節點值
    struct ListNode *next; // 指向後繼節點的指標
    struct ListNode *prev; // 指向前驅節點的指標
} ListNode;

/* 構造函數 */
ListNode *newListNode(int val) {
    ListNode *node;
    node = (ListNode *) malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

