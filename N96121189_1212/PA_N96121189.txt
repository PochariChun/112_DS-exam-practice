# M個數字
def oddoreven():
    row = []
    # 過濾掉輸入的非數字成為row，輸入會類似a1.a1aaa1a1a，我希望得到row = 1111
    expression = input()
    for char in expression:
        if char.isdigit():
            row.append(char)

    row = "".join(row)

    #在執行底下公式
    leng = len(row)
    odd = even = 0
    for j in range(leng):
        if j % 2 == 0:
            odd += int(row[j])
        else:
            even += int(row[j])
    diff = odd - even
    if diff % 11 == 0:
        print("YES")
    else:
        print("NO")

def main():
    M= int(input())
    for _ in range(M):
        oddoreven()

if __name__ == "__main__":
    main()
        
        
            
  
            
