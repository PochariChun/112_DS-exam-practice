/* 基於鏈表實現的佇列 */
typedef struct {
    ListNode *front, *rear;
    int queSize;
} LinkedListQueue;

/* 構造函數 */
LinkedListQueue *newLinkedListQueue() {
    LinkedListQueue *queue = (LinkedListQueue *)malloc(sizeof(LinkedListQueue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->queSize = 0;
    return queue;
}

/* 析構函數 */
void delLinkedListQueue(LinkedListQueue *queue) {
    // 釋放所有節點
    for (int i = 0; i < queue->queSize && queue->front != NULL; i++) {
        ListNode *tmp = queue->front;
        queue->front = queue->front->next;
        free(tmp);
    }
    // 釋放 queue 結構體
    free(queue);
}

/* 獲取佇列的長度 */
int size(LinkedListQueue *queue) {
    return queue->queSize;
}

/* 判斷佇列是否為空 */
bool empty(LinkedListQueue *queue) {
    return (size(queue) == 0);
}

/* 入隊 */
void push(LinkedListQueue *queue, int num) {
    // 尾節點處添加 node
    ListNode *node = newListNode(num);
    // 如果佇列為空，則令頭、尾節點都指向該節點
    if (queue->front == NULL) {
        queue->front = node;
        queue->rear = node;
    }
    // 如果佇列不為空，則將該節點添加到尾節點後
    else {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->queSize++;
}

/* 訪問隊首元素 */
int peek(LinkedListQueue *queue) {
    assert(size(queue) && queue->front);
    return queue->front->val;
}

/* 出隊 */
void pop(LinkedListQueue *queue) {
    int num = peek(queue);
    ListNode *tmp = queue->front;
    queue->front = queue->front->next;
    free(tmp);
    queue->queSize--;
}

/* 列印佇列 */
void printLinkedListQueue(LinkedListQueue *queue) {
    int *arr = malloc(sizeof(int) * queue->queSize);
    // 拷貝鏈表中的資料到陣列
    int i;
    ListNode *node;
    for (i = 0, node = queue->front; i < queue->queSize; i++) {
        arr[i] = node->val;
        node = node->next;
    }
    printArray(arr, queue->queSize);
    free(arr);
}

