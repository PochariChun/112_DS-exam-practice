import sys
import heapq

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[] for i in range(vertices)]
    
    def add_edge(self, u, v, w):
        self.graph[u].append((v, w))
        self.graph[v].append((u, w))

    def prim_mst(self, start):
        visited = [False] * self.V
        min_heap = [(0, start)]
        mst_edges = []
        total_cost = 0

        while min_heap:
            weight, u = heapq.heappop(min_heap)

            if visited[u]:
                continue

            visited[u] = True
            total_cost += weight

            if u != start:  # Skip adding the start vertex itself
                mst_edges.append(u)

            for v, w in self.graph[u]:
                if not visited[v]:
                    heapq.heappush(min_heap, (w, v))

        return mst_edges, total_cost

def read_input():
    edges = []
    start = int(input().strip())
    while True:
        u, v, w = map(int, input().split())
        if u == -1:
            break
        edges.append((u, v, w))
    return start, edges

def main():
    start, edges = read_input()
    max_vertex = max(max(u, v) for u, v, _ in edges)
    g = Graph(max_vertex + 1)  # +1 because vertices are 0-indexed

    for u, v, w in edges:
        g.add_edge(u, v, w)

    mst_edges, total_cost = g.prim_mst(start)

    # Output
    for i, v in enumerate(mst_edges, 1):
        print(f"{i}: <{start},{v}>")
        start = v
    print(f"The cost of minimum spanning tree: {total_cost}")

if __name__ == "__main__":
    main()
