def min_height_most_volume(heights):
    most_volume = float('-inf')  # 初始化为负无穷
    leng = len(heights)
    
    for i in range(leng):
        for j in range(i+1, leng):
            min_height = min(heights[i], heights[j])  # 选择两个高度中的较小者
            cur_volume = min_height * (j - i)
            if cur_volume > most_volume:
                most_volume = cur_volume
    
    return most_volume

# M个dam
M = int(input())
# 每个dam N筆
N = int(input())

for _ in range(M):
    row = list(map(int, input().split()))
    most_volume = min_height_most_volume(row)
    print(most_volume)
