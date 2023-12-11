def max_profit_min_price(prices):
    min_price = float('inf')  # 初始最低價格為正無限大
    max_profit = 0  # 初始最大收益為0
    
    for current_price in prices:
        if current_price < min_price:
            min_price = current_price
        else:
            cur_profit = current_price - min_price
            if cur_profit > max_profit:
                max_profit = cur_profit
    
    return max_profit

M = int(input())  # 用於存儲測試案例數量

for _ in range(M):  # 開始處理每個測試案例
    N = int(input())  # 從輸入中讀取價格數量
    prices = list(map(int, input().split()))  # 從輸入中讀取價格數組，並轉換為整數列表
    
    result = max_profit_min_price(prices)  # 調用函數計算最大收益
    print(result)  # 輸出最大收益
