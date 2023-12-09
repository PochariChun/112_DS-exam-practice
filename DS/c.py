# 读取矩阵的行数和列数
m, n = map(int, input().split())

# 读取矩阵元素并存储在列表中
matrix = []
for i in range(m):
    row = list(map(int, input().split()))
    matrix.append(row)

# 计算并输出转置矩阵
for i in range(n):
    for j in range(m):
        print(matrix[j][i], end=" ")
    print()