"""
程式目的：檢查括號序列是否有效。

程式描述：
1. 讀取測試案例的數量 'time'。
2. 對於每個測試案例：
   a. 讀取一個包含括號字符的字串 's'。
   b. 初始化一個堆疊 'st' 來跟蹤括號的匹配。
   c. 遍歷字串 's' 的每個字符：
      - 如果遇到左括號 '(' 或 '['，將其壓入堆疊 'st'。
      - 如果遇到右括號 ')' 或 ']'，檢查堆疊 'st' 的頂部元素是否與當前右括號匹配：
        - 若匹配，將頂部元素出堆疊。
        - 否則，將當前右括號壓入堆疊 'st'。
   d. 最後檢查堆疊 'st' 是否為空，若為空，輸出 "VALID"，否則輸出 "NOT VALID"。
3. 重複上述步驟對每個測試案例執行。

程式輸出：對於每個測試案例，輸出其括號序列是否有效。
"""

def main():
    time = int(input())  # 測試案例的數量
    while time > 0:
        s = input()  # 括號序列字串
        len_s = len(s)
        
        stack = []
        
        for i in range(len_s):
            if s[i] == '(' or s[i] == '[':
                stack.append(s[i])
            elif s[i] == ')' and stack and stack[-1] == '(':
                stack.pop()
            elif s[i] == ']' and stack and stack[-1] == '[':
                stack.pop()
            else:
                stack.append(s[i])
        
        if not stack:
            print("VALID")
        else:
            print("NOT VALID")
        
        time -= 1

if __name__ == "__main__":
    main()
