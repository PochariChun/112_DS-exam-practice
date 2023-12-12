def graph_bfs(graph: GraphAdjList, start_vet: Vertex) -> list[Vertex]:
    """廣度優先遍歷 BFS"""
    # 使用鄰接表來表示圖，以便獲取指定頂點的所有鄰接頂點
    # 頂點遍歷序列
    res = []
    # 雜湊表，用於記錄已被訪問過的頂點
    visited = set[Vertex]([start_vet])
    # 佇列用於實現 BFS
    que = deque[Vertex]([start_vet])
    # 以頂點 vet 為起點，迴圈直至訪問完所有頂點
    while len(que) > 0:
        vet = que.popleft()  # 隊首頂點出隊
        res.append(vet)  # 記錄訪問頂點
        # 遍歷該頂點的所有鄰接頂點
        for adj_vet in graph.adj_list[vet]:
            if adj_vet in visited:
                continue  # 跳過已被訪問的頂點
            que.append(adj_vet)  # 只入隊未訪問的頂點
            visited.add(adj_vet)  # 標記該頂點已被訪問
    # 返回頂點遍歷序列
    return res
/* 節點佇列結構體 */
typedef struct {
    Vertex *vertices[MAX_SIZE];
    int front, rear, size;
} Queue;

/* 構造函數 */
Queue *newQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = q->size = 0;
    return q;
}

/* 判斷佇列是否為空 */
int isEmpty(Queue *q) {
    return q->size == 0;
}

/* 入隊操作 */
void enqueue(Queue *q, Vertex *vet) {
    q->vertices[q->rear] = vet;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->size++;
}

/* 出隊操作 */
Vertex *dequeue(Queue *q) {
    Vertex *vet = q->vertices[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return vet;
}

/* 檢查頂點是否已被訪問 */
int isVisited(Vertex **visited, int size, Vertex *vet) {
    // 遍歷查找節點，使用 O(n) 時間
    for (int i = 0; i < size; i++) {
        if (visited[i] == vet)
            return 1;
    }
    return 0;
}

/* 廣度優先遍歷 BFS */
// 使用鄰接表來表示圖，以便獲取指定頂點的所有鄰接頂點
void graphBFS(GraphAdjList *graph, Vertex *startVet, Vertex **res, int *resSize, Vertex **visited, int *visitedSize) {
    // 佇列用於實現 BFS
    Queue *queue = newQueue();
    enqueue(queue, startVet);
    visited[(*visitedSize)++] = startVet;
    // 以頂點 vet 為起點，迴圈直至訪問完所有頂點
    while (!isEmpty(queue)) {
        Vertex *vet = dequeue(queue); // 隊首頂點出隊
        res[(*resSize)++] = vet;      // 記錄訪問頂點
        // 遍歷該頂點的所有鄰接頂點
        AdjListNode *node = findNode(graph, vet);
        while (node != NULL) {
            // 跳過已被訪問的頂點
            if (!isVisited(visited, *visitedSize, node->vertex)) {
                enqueue(queue, node->vertex);             // 只入隊未訪問的頂點
                visited[(*visitedSize)++] = node->vertex; // 標記該頂點已被訪問
            }
            node = node->next;
        }
    }
    // 釋放記憶體
    free(queue);
}
