/* 檢查頂點是否已被訪問 */
int isVisited(Vertex **res, int size, Vertex *vet) {
    // 遍歷查找節點，使用 O(n) 時間
    for (int i = 0; i < size; i++) {
        if (res[i] == vet) {
            return 1;
        }
    }
    return 0;
}

/* 深度優先遍歷 DFS 輔助函數 */
void dfs(GraphAdjList *graph, Vertex **res, int *resSize, Vertex *vet) {
    // 記錄訪問頂點
    res[(*resSize)++] = vet;
    // 遍歷該頂點的所有鄰接頂點
    AdjListNode *node = findNode(graph, vet);
    while (node != NULL) {
        // 跳過已被訪問的頂點
        if (!isVisited(res, *resSize, node->vertex)) {
            // 遞迴訪問鄰接頂點
            dfs(graph, res, resSize, node->vertex);
        }
        node = node->next;
    }
}

/* 深度優先遍歷 DFS */
// 使用鄰接表來表示圖，以便獲取指定頂點的所有鄰接頂點
void graphDFS(GraphAdjList *graph, Vertex *startVet, Vertex **res, int *resSize) {
    dfs(graph, res, resSize, startVet);
}
