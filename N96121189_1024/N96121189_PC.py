# 每行N個測試數字
N= int(input())
# M個測試資料
M= int(input())
for _ in range(M):
    # 現在出的牌=cur
    cur = 1
    stack = []
    jug = True
    # B指定順序為 row
    row = list(map(int , input().split()))
    # 遍歷row中N數字
    for i in range(N):
        # print(f"i={i}")
        # print(f"Cur={cur}")
        while jug:
            # if A cur < B指定 ex : 1<5，1存入stack，A玩下一張卡
            if row[i] > cur:
                stack.append(cur)
                cur += 1
            # if A cur = B指定 ex : 1=1，A玩下一張卡，B也指定下一個i++，也就是break
            elif row[i] == cur:
                if cur < N:
                    cur += 1
                break
            else:
                # if A cur > B指定，取stack找牌
                if stack:
                    popp = stack.pop()
                    if popp == row[i]:
                        break
                    else:
                        jug = False
                        print("No")
                        break

                else:
                    jug = False
                    print("No")
                    break
    if jug:
        print("Yes")


        

