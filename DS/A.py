# // 必要include
# /*
#     判斷一個數字 M 是否為 11 的倍數。
#     輸入: 數字的個數 M，以及每個數字的字串表示。
# */

# 輸入處理數字個數 M
M = int(input())

for _ in range(M):
    # 輸入數字字串表示
    num_str = input()
    odd_sum = even_sum = 0
    
    # 獲得字串長度
    len_num = len(num_str)
    
    # 計算奇數位置和偶數位置的數字和
    for j in range(len_num):
        if j % 2 == 0:
            odd_sum += int(num_str[j])
        else:
            even_sum += int(num_str[j])
    
    # 計算 diff == AB差
    diff = odd_sum - even_sum
    
    if diff % 11 == 0:
        print('YES')
    else:
        print('NO')
