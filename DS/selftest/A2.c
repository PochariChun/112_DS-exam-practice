// 必要include
#include<stdio.h>
#include<string.h>
/*
    判斷一個數字 M 是否為 11 的倍數。
    輸入: 數字的個數 M，以及每個數字的字串表示。
*/
int main(){
    // 輸入處理數字個數M
    int M;
    scanf("%d",&M);
    // 輸入數字字串表示
    char num[100001];
    for (int i =0;i<M;i++){
        scanf("%d",&num);
        int odd_sum= 0;int even_sum= 0;
        // 獲得字串長度
        int len = strlen(num);
        // A字符轉為數字，計算奇數位置的數字和
        // B字符轉為數字，計算偶數位置的數字和
        for(int j=0;j<len;j++){
            if (j%2 == 0){
                // num[j] 是ASCII，ASCII - '0'的ASCII = 偏移量 數字值 
                odd_sum += num[j] - '0';
            }else{
                even_sum += num[j] - '0';
            }                 
        }
        // 計算diff == AB差
        int diff =odd_sum - even_sum; 
        if diff % 11

    }

    
    // A字符轉為數字，計算奇數位置的數字和
    // B字符轉為數字，計算偶數位置的數字和
    // 計算diff == AB差
    // 判斷是否為11倍數: !ABd? "Yes" 不是 "No"



}






//////////////////////////////////////////////////////////////
// 輸入要處理的數字個數M
// 輸入一個數字的字串表示
// 獲得字串長度
// 將字符轉換為數字，計算位於奇數位置的數字之和
// 將字符轉換為數字，計算位於偶數位置的數字之和
// 計算奇數位和偶數位的差
// 判斷差是否為11的倍數
// 若是11的倍數，輸出"YES"
// 若不是11的倍數，輸出"NO"

