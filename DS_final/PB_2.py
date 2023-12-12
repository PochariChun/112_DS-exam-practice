import sys

maxn = 100 + 100
INF = float('inf')

def floyd():
    for k in range(1, c + 1):
        for i in range(1, c + 1):
            for j in range(1, c + 1):
                dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]))

c, s = 7, 9
q = int(input())
dist = [[INF] * maxn for _ in range(maxn)]

dist[1][2] = dist[2][1] = 50
dist[1][3] = dist[3][1] = 60
dist[2][4] = dist[4][2] = 120
dist[2][5] = dist[5][2] = 90
dist[3][6] = dist[6][3] = 50
dist[4][6] = dist[6][4] = 80
dist[4][7] = dist[7][4] = 70
dist[5][7] = dist[7][5] = 40
dist[6][7] = dist[7][6] = 140

floyd()

for _ in range(q):
    c1, c2 = map(int, input().split())
    if dist[c1][c2] == INF:
        print("no path")
    else:
        print(dist[c1][c2])
