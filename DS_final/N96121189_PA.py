# M個數字
def oddoreven():
    row1, row2 = input().split(".")
    row = row1 + row2
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
        
        
            
