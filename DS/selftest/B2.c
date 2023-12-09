// 目的：計算多個測試案例中每段區間的最大收益
// 輸入：M - 測試案例的數量
//       每個測試案例包括 N - 價格數量
//       價格數組 - 包含 N 個整數的數組，代表股票的價格
// 輸出：每個測試案例的最大收益

    // 函數用來計算每段區間的最大收益和最低價格

    
// 錯誤處: 1. <limit的s>
// 2. int '*'max_profit
// 3. printf("%d",v) 沒有&
// 4. max_profit_low_price(變數, '&位址'不是*)

#include<stdio.h>
#include<limits.h>
void max_profit_low_price(int cur_price, int *max_profit, int *min_price){
    if (cur_price < *min_price){
        *min_price = cur_price;
    } else{
        int cur_profit = cur_price - *min_price;
        if (cur_profit > *max_profit){
            *max_profit = cur_profit;
        }
    }
}
int main(){
    int M;int N;
    scanf("%d",&M);
    for (int i = 0; i <M; i++){
        int max_profit = 0;
        int min_price = INT_MAX;
        int cur_price = 0;
        scanf("%d",&N);
        for (int i = 0; i <M; i++){
            scanf("%d",&cur_price);
            max_profit_low_price(cur_price, &max_profit, &min_price);
        }
        printf("%d\n",max_profit);

    }
    return 0;

}
    // 用於存儲測試案例數量
    // 用於存儲每個測試案例中的價格數量
    // 從輸入中讀取測試案例數量
    // 開始處理每個測試案例
    // 用於存儲當前價格
    // 初始最低價格為正無限大
    // 初始最大收益為0
    // 從輸入中讀取價格數量
    // 開始處理每個價格
    // 從輸入中讀取當前價格
    // 調用函數計算最大收益和最低價格
    // 輸出最大收益
