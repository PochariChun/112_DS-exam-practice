# // 必要include
# /*
#     判斷一個數字 M 是否為 11 的倍數。
#     輸入: 數字的個數 M，以及每個數字的字串表示。
# */
M = int(input())
for _ in range(M):
    num = input()
    odd = even = 0
    leng = len(num)
    for i in range(leng):
        if i % 2 == 0:
            odd += int(num[i])
        else:
            even += int(num[i])
    diff = odd - even
    if diff % 11 == 0:
        print("Yes")
    else:
        print("No")
