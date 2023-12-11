
import sys

def dfs(map, x, y, visited):
    """ 使用深度優先搜尋標記所有連接感染者的群體 """
    # 檢查座標是否越界或已造訪過，或目前位置不是人
    if x < 0 or y < 0 or x >= len(map) or y >= len(map[0]) or visited[x][y] or map[x][y] == '.':
        return
    visited[x][y] = True # 標記目前位置已訪問，全域變數
    # 遍歷周圍8個方位
    for dx in [-1, 0, 1]:
        for dy in [-1, 0, 1]:
            if dx != 0 or dy != 0:
                dfs(map, x + dx, y + dy, visited)

def count_infected_groups(map):
    """ 計算地圖上被感染的人群數量 """
    m, n = len(map), len(map[0]) # 取得地圖的行數和列數
    visited = [[False for _ in range(n)] for _ in range(m)] # 初始化已造訪過，最重要

    groups = 0 # 初始化感染群，最重要
    for i in range(m):
        for j in range(n):
            # 對於每一個未造訪的感染者 'C'，進行深度優先搜尋，將同一群的遍歷，避免下次被計數
            if map[i][j] == 'C' and not visited[i][j]:
                dfs(map, i, j, visited)
                groups += 1
    return groups

def main():
    """
    感染的人（表示為 'C'）可以向8個方向擴散，影響周圍的正常人（表示為 'P'）
    任務是確定地圖上有多少個被感染的人群。

    解決方案，使用深度優先搜尋（DFS）演算法。 
    對於每一個感染者 'C'，我們可以使用DFS來標記所有與之相連的、透過潛在擴散路徑相連的感染者
    這樣就可以識別出一個獨立的感染群體。"""
    m, n = map(int, sys.stdin.readline().strip().split())  # 使用 sys.stdin 讀取地圖的尺寸
    grid  = [sys.stdin.readline().strip() for _ in range(m)]  # 使用 sys.stdin 逐行讀取地圖數據存入二維矩陣grid
    print(count_infected_groups(grid))

if __name__ == "__main__":
    main()
