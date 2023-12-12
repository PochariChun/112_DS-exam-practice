def calculate_water_accumulation(heights):
    n = len(heights)
    
    left_max = [0] * n
    right_max = [0] * n
    
    left_max[0] = heights[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i-1], heights[i])
        
    right_max[n-1] = heights[n-1]
    for i in range(n-2, -1, -1):
        right_max[i] = max(right_max[i+1], heights[i])
        
    water_accumulated = 0
    for i in range(n):
        water_accumulated += min(left_max[i], right_max[i]) - heights[i]
        
    return water_accumulated

def main():
    N = int(input())
    heights_sequence = list(map(int, input().split()))
    water = calculate_water_accumulation(heights_sequence)
    print(water)

if __name__ == "__main__":
    main()
