"""
Floyd-Warshall算法：找到所有點對之間的最短路徑。

Floyd-Warshall算法遍歷圖中的每對節點，並嘗試找到更短的路徑。
"""
def floyd(dist):
    c = len(dist)
    for k in range(c):
        for i in range(c):
            for j in range(c):
                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

"""
廣度優先搜索（BFS）：找到從起始城市到目標城市的最短路徑。

BFS從起始城市開始，逐層擴展搜索，直到找到目標城市為止。
"""
def bfs(start, target, neighbors):
    queue = deque([(start, 0)])
    visited = set()

    while queue:
        current_city, distance = queue.popleft()
        if current_city == target:
            return distance

        for next_city in neighbors(current_city):
            if next_city not in visited:
                visited.add(next_city)
                queue.append((next_city, distance + 1))

    return -1  # 如果無法到達目標城市

"""
深度優先搜索（DFS）：用於標記連接的感染者群體。

DFS從給定的起點開始，遞歸地訪問周圍的節點並標記已訪問的節點，直到無法繼續訪問為止。
"""
def dfs(map, x, y, visited):
    if x < 0 or y < 0 or x >= len(map) or y >= len(map[0]) or visited[x][y] or map[x][y] == '.':
        return
    visited[x][y] = True

    for dx in [-1, 0, 1]:
        for dy in [-1, 0, 1]:
            if dx != 0 or dy != 0:
                dfs(map, x + dx, y + dy, visited)

"""
Bellman-Ford算法：找到帶權重的有向圖中的最短路徑。

Bellman-Ford算法遍歷所有節點，並反覆更新從起點到每個節點的最短距離，直到不再有更新為止。
"""
def bellman_ford(graph, start):
    dist = {node: float('inf') for node in graph}
    dist[start] = 0

    for _ in range(len(graph) - 1):
        for u, v, weight in graph:
            if dist[u] + weight < dist[v]:
                dist[v] = dist[u] + weight

    for u, v, weight in graph:
        if dist[u] + weight < dist[v]:
            return "圖包含負權重循環"

    return dist

"""
Kruskal算法：找到無向圖中的最小生成樹。

Kruskal算法按照權重對邊進行排序，然後選擇最小權重的邊，以確保不形成循環。
"""
class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)
        if root_x != root_y:
            if self.rank[root_x] < self.rank[root_y]:
                self.parent[root_x] = root_y
            elif self.rank[root_x] > self.rank[root_y]:
                self.parent[root_y] = root_x
            else:
                self.parent[root_y] = root_x
                self.rank[root_x] += 1

def kruskal(graph):
    mst = []
    graph.sort(key=lambda edge: edge[2])  # 根據權重對邊進行排序
    n = len(graph)
    disjoint_set = DisjointSet(n)

    for edge in graph:
        u, v, weight = edge
        if disjoint_set.find(u) != disjoint_set.find(v):
            mst.append(edge)
            disjoint_set.union(u, v)

    return mst

"""
Prim算法：找到無向圖中的最小生成樹。

Prim算法以某個節點開始，選擇與已選擇節點相連的最小權重邊，以構建最小生成樹。
"""
def prim(graph):
    vertices = list(graph.keys())
    n = len(vertices)
    visited = [False] * n
    minimum_spanning_tree = []
    
    start_node = vertices[0]
    visited[0] = True

    while len(minimum_spanning_tree) < n - 1:
        min_weight = float('inf')
        min_edge = None

        for u in range(n):
            if visited[u]:
                for v, weight in graph[vertices[u]]:
                    if not visited[vertices.index(v)] and weight < min_weight:
                        min_weight = weight
                        min_edge = (vertices[u], v, weight)

        if min_edge:
            u, v, weight = min_edge
            minimum_spanning_tree.append((u, v, weight))
            visited[vertices.index(v)] = True

    return minimum_spanning_tree

"""
Dijkstra算法：找到帶權重的有向圖中的最短路徑。

Dijkstra算法從起點開始，反覆選擇最短路徑，直到找到所有節點的最短路徑。
"""
def dijkstra(graph, start):
    vertices = list(graph.keys())
    n = len(vertices)
    dist = {vertex: float('inf') for vertex in vertices}
    dist[start] = 0
    visited = [False] * n

    for _ in range(n):
        min_dist = float('inf')
        min_vertex = None

        for i in range(n):
            if not visited[i] and dist[vertices[i]] < min_dist:
                min_dist = dist[vertices[i]]
                min_vertex = vertices[i]

        if min_vertex is None:
            break

        visited[vertices.index(min_vertex)] = True

        for neighbor, weight in graph[min_vertex]:
            alt = dist[min_vertex] + weight
            if alt < dist[neighbor]:
                dist[neighbor] = alt

    return dist
