m, n = map(int, input().split())
matrix = []
for i in range(m):
    row = list(map(int, input().split()))
    matrix.append(row)

for i in range(n):
    for j in range(m):
        print(matrix[j][i],end=" ")
    print("")
    