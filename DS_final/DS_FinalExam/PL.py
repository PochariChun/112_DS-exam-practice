import sys

def dfs(map, x, y, visited):
    if x < 0 or y < 0 or x >= len(map) or y >= len(map[0]) or visited[x][y] or map[x][y] == '.':
        return
    visited[x][y] = True
    for dx in [-1, 0, 1]:
        for dy in [-1, 0, 1]:
            if dx != 0 or dy != 0:
                dfs(map, x + dx, y + dy, visited)

def count_infected_groups(map):
    m, n = len(map), len(map[0])
    visited = [[False for _ in range(n)] for _ in range(m)]
    groups = 0
    for i in range(m):
        for j in range(n):
            if map[i][j] == 'C' and not visited[i][j]:
                dfs(map, i, j, visited)
                groups += 1
    return groups

def main():
    m, n = map(int, input().strip().split())  # 從標準輸入讀取 M 和 N
    grid = [input().strip() for _ in range(m)]  # 讀取地圖資訊
    print(grid)
    # print(count_infected_groups(grid))

if __name__ == "__main__":
    main()