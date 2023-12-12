def maximalSquare(matrix):
    if not matrix:
        return 0

    m, n = len(matrix), len(matrix[0])
    dp = [[0] * n for _ in range(m)]
    max_side = 0

    for i in range(m):
        for j in range(n):
            if matrix[i][j] == '1':
                dp[i][j] = 1
                if i > 0 and j > 0:
                    dp[i][j] += min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
                max_side = max(max_side, dp[i][j])

    return max_side * max_side

def main():
    # 使用者輸入矩陣的行數和列數
    m, n = map(int, input().split())

    # 使用者輸入矩陣的元素
    matrix = []
    for _ in range(m):
        row = input().split()
        matrix.append(row)

    # 計算結果並輸出
    result = maximalSquare(matrix)
    print(result)

if __name__ == "__main__":
    main()
