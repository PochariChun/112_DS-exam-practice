/* 雙向鏈表節點 */
typedef struct DoublyListNode {
    int val;                     // 節點值
    struct DoublyListNode *next; // 後繼節點
    struct DoublyListNode *prev; // 前驅節點
} DoublyListNode;

/* 構造函數 */
DoublyListNode *newDoublyListNode(int num) {
    DoublyListNode *new = (DoublyListNode *)malloc(sizeof(DoublyListNode));
    new->val = num;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

/* 析構函數 */
void delDoublyListNode(DoublyListNode *node) {
    free(node);
}

/* 基於雙向鏈表實現的雙向佇列 */
typedef struct {
    DoublyListNode *front, *rear; // 頭節點 front ，尾節點 rear
    int queSize;                  // 雙向佇列的長度
} LinkedListDeque;

/* 構造函數 */
LinkedListDeque *newLinkedListDeque() {
    LinkedListDeque *deque = (LinkedListDeque *)malloc(sizeof(LinkedListDeque));
    deque->front = NULL;
    deque->rear = NULL;
    deque->queSize = 0;
    return deque;
}

/* 析構函數 */
void delLinkedListdeque(LinkedListDeque *deque) {
    // 釋放所有節點
    for (int i = 0; i < deque->queSize && deque->front != NULL; i++) {
        DoublyListNode *tmp = deque->front;
        deque->front = deque->front->next;
        free(tmp);
    }
    // 釋放 deque 結構體
    free(deque);
}

/* 獲取佇列的長度 */
int size(LinkedListDeque *deque) {
    return deque->queSize;
}

/* 判斷佇列是否為空 */
bool empty(LinkedListDeque *deque) {
    return (size(deque) == 0);
}

/* 入隊 */
void push(LinkedListDeque *deque, int num, bool isFront) {
    DoublyListNode *node = newDoublyListNode(num);
    // 若鏈表為空，則令 front 和 rear 都指向node
    if (empty(deque)) {
        deque->front = deque->rear = node;
    }
    // 隊首入隊操作
    else if (isFront) {
        // 將 node 添加至鏈表頭部
        deque->front->prev = node;
        node->next = deque->front;
        deque->front = node; // 更新頭節點
    }
    // 隊尾入隊操作
    else {
        // 將 node 添加至鏈表尾部
        deque->rear->next = node;
        node->prev = deque->rear;
        deque->rear = node;
    }
    deque->queSize++; // 更新佇列長度
}

/* 隊首入隊 */
void pushFirst(LinkedListDeque *deque, int num) {
    push(deque, num, true);
}

/* 隊尾入隊 */
void pushLast(LinkedListDeque *deque, int num) {
    push(deque, num, false);
}

/* 訪問隊首元素 */
int peekFirst(LinkedListDeque *deque) {
    assert(size(deque) && deque->front);
    return deque->front->val;
}

/* 訪問隊尾元素 */
int peekLast(LinkedListDeque *deque) {
    assert(size(deque) && deque->rear);
    return deque->rear->val;
}

/* 出隊 */
int pop(LinkedListDeque *deque, bool isFront) {
    if (empty(deque))
        return -1;
    int val;
    // 隊首出隊操作
    if (isFront) {
        val = peekFirst(deque); // 暫存頭節點值
        DoublyListNode *fNext = deque->front->next;
        if (fNext) {
            fNext->prev = NULL;
            deque->front->next = NULL;
            delDoublyListNode(deque->front);
        }
        deque->front = fNext; // 更新頭節點
    }
    // 隊尾出隊操作
    else {
        val = peekLast(deque); // 暫存尾節點值
        DoublyListNode *rPrev = deque->rear->prev;
        if (rPrev) {
            rPrev->next = NULL;
            deque->rear->prev = NULL;
            delDoublyListNode(deque->rear);
        }
        deque->rear = rPrev; // 更新尾節點
    }
    deque->queSize--; // 更新佇列長度
    return val;
}

/* 隊首出隊 */
int popFirst(LinkedListDeque *deque) {
    return pop(deque, true);
}

/* 隊尾出隊 */
int popLast(LinkedListDeque *deque) {
    return pop(deque, false);
}

/* 列印佇列 */
void printLinkedListDeque(LinkedListDeque *deque) {
    int *arr = malloc(sizeof(int) * deque->queSize);
    // 拷貝鏈表中的資料到陣列
    int i;
    DoublyListNode *node;
    for (i = 0, node = deque->front; i < deque->queSize; i++) {
        arr[i] = node->val;
        node = node->next;
    }
    printArray(arr, deque->queSize);
    free(arr);
}

