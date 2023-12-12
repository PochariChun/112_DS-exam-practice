def count_shortest_path(grid):
    # 使用DP，找出最短路徑，'#'為不可以走的，'$'為可以走的, 'F'式出口, 'S'是起點

def main():
    N = int(input())
    m, n = map(int, input().strip().split())  # 從標準輸入讀取 M 和 N
    grid = [input().strip() for _ in range(m)]  # 讀取地圖資訊
    print(count_shortest_path(grid))
if __name__ == "__main__":
    main()
