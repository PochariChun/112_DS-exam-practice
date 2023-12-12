# 就是有[就要有]，也就是stack問題，如果底部還有符號，那代表不成功
# 只有兩種符號 [] 和()
# M個超連結
M= int(input())
for i in range(M):
    jug = True
    stack = []
    row = input()
    leng = len(row)
    for j in range(leng):
        if row[j] == "[" :
            stack.append(row[j])
        elif row[j] == "(" :
            stack.append(row[j])

        elif row[j] == "]" :
            if stack:
                popp = stack.pop()
                if popp != "[":
                    jug = False
                    print("NOT VALID")
                    break
            else:
                jug = False
                print("NOT VALID")
                break

        elif row[j] == ")" :
            if stack:
                popp = stack.pop()
                if popp != "(":
                    jug = False
                    print("NOT VALID")
                    break
            else:
                jug = False
                print("NOT VALID")
                break
        else:
            continue
        
    if stack:
        jug = False
        print("NOT VALID")
    if jug:
        print("VALID")