"""
程式目的：檢查一串數字中是否存在一個數字序列，使得奇數位數之和等於偶數位數之和。

程式描述：
1. 讀取測試案例的數量 'time'。
2. 對於每個測試案例：
   a. 讀取一個包含數字和小數點 '.' 的字串 's'。
   b. 初始化變數 'len' 來表示字串 's' 的長度，'odd' 用於記錄奇數位數之和，'even' 用於記錄偶數位數之和，'cur' 用於跟蹤當前位數。
   c. 遍歷字串 's' 的每個字符：
      - 如果字符為小數點 '.'，則 'cur' 不變。
      - 如果 'cur' 為奇數，將字符轉換為整數，加到 'odd' 上，並將 'cur' 增加 1。
      - 如果 'cur' 為偶數，將字符轉換為整數，加到 'even' 上，並將 'cur' 增加 1。
   d. 最後，檢查 'odd' 是否等於 'even' 或者它們之間的差是否為 11 的倍數，如果是，輸出 "YES"，否則輸出 "NO"。
3. 重複上述步驟對每個測試案例執行。

程式輸出：對於每個測試案例，輸出 "YES" 如果滿足奇數位數之和等於偶數位數之和的條件，否則輸出 "NO"。
"""

def main():
    time = int(input())  # 測試案例的數量
    while time > 0:
        s = input()  # 包含數字和小數點的字串
        len_s = len(s)
        odd = 0
        even = 0
        cur = 0
        
        for i in range(len_s):
            if s[i] == '.':
                cur = cur
            elif cur % 2 == 1:
                odd += int(s[i])
                cur += 1
            elif cur % 2 == 0:
                even += int(s[i])
                cur += 1
        
        if odd == even or (odd - even) % 11 == 0:
            print("YES")
        else:
            print("NO")
        
        time -= 1

if __name__ == "__main__":
    main()
