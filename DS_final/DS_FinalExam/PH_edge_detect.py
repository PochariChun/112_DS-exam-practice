def find_boundary(M, N, grid):
    boundary_map = [['_'] * N for _ in range(M)]
    
    for i in range(1, M - 1):
        for j in range(1, N - 1):
            if grid[i][j] == 1:
                # 只要有0在附近就是邊界，邊界圖標示為1
                if grid[i-1][j] == 0 or grid[i+1][j] == 0 or grid[i][j-1] == 0 or grid[i][j+1] == 0:
                    boundary_map[i][j] = '0'
    
    return boundary_map

def main():
    M, N = map(int, input().split())
    grid = []
    
    for _ in range(M):
        row = list(map(int, input().split()))
        grid.append(row)
    
    boundary_map = find_boundary(M, N, grid)
    print(boundary_map)
    
    for row in boundary_map:
        print(' '.join(row))

if __name__ == "__main__":
    main()
