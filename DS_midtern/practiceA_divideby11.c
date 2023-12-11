#include <stdio.h>
#include <string.h>
/*
    請判斷一數 M 是否為 11 的倍數。
*/

int main() {
    int M;
    scanf("%d", &M);  // 輸入要處理的數字個數M
    
    for (int i = 0; i < M; i++) {
        char* number_str=NULL;
        scanf("%ms",&number_str);
        int odd_sum = 0, even_sum = 0;
        int len = strlen(number_str);  // 獲得字串長度
        
        for (int j = 0; j < len; j++) {
            if (j % 2 == 0) {
                odd_sum += number_str[j] - '0';  // 將字符轉換為數字，計算位於奇數位置的數字之和
            } else {
                even_sum += number_str[j] - '0';  // 將字符轉換為數字，計算位於偶數位置的數字之和
            }
        }
        
        if (odd_sum  == even_sum) {  // 判斷差是否為11的倍數
            printf("YES\n");  // 若是11的倍數，輸出"YES"
        } else {
            printf("NO\n");  // 若不是11的倍數，輸出"NO"
        }
        free(number_str);
    }
    
    return 0;
}
