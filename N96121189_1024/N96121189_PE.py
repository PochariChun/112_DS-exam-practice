m, n = map(int, input().split())
matrix = []
for i in range(m):
    row = list(map(int, input().split()))
    matrix.append(row)

p, q = map(int, input().split())
matrix2 = []
for i in range(p):
    row = list(map(int, input().split()))
    matrix2.append(row)

matrix3 = []
for i in range(m):
    row = [0]*q
    matrix3.append(row)
for i in range(m):
    for k in range(q):
        sum= 0
        for j in range(p):
            x = matrix[i][j]*matrix2[j][k]
            sum += x
        matrix3[i][k] = sum
        print(matrix3[i][k], end=' ')    
    print('')

