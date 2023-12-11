
// 目的：計算多個測試案例中每段區間的最大收益
// 輸入：M - 測試案例的數量
//       每個測試案例包括 N - 價格數量
//       價格數組 - 包含 N 個整數的數組，代表股票的價格
// 輸出：每個測試案例的最大收益

#include <stdio.h>
#include <limits.h>

// 函數用來計算每段區間的最大收益和最低價格
void max_profit_min_price(int current_price, int *max_profit, int *min_price) {
    if (current_price < *min_price) {
        *min_price = current_price;
    } else {
        int cur_profit = current_price - *min_price;
        if (cur_profit > *max_profit) {
            *max_profit = cur_profit;
        }
    }
}

int main() {
    int M;  // 用於存儲測試案例數量
    int N;  // 用於存儲每個測試案例中的價格數量

    scanf("%d", &M);  // 從輸入中讀取測試案例數量
    
    for (int i = 0; i < M; i++) {  // 開始處理每個測試案例
        int current_price = 0;  // 用於存儲當前價格
        int min_price = INT_MAX;  // 初始最低價格為正無限大
        int max_profit = 0;  // 初始最大收益為0
        
        scanf("%d", &N);  // 從輸入中讀取價格數量
        
        for (int j = 0; j < N; j++) {  // 開始處理每個價格
            scanf("%d", &current_price);  // 從輸入中讀取當前價格
            max_profit_min_price(current_price, &max_profit, &min_price);  // 調用函數計算最大收益和最低價格
        }
        
        printf("%d\n", max_profit);  // 輸出最大收益
    }
    
    return 0;
}
