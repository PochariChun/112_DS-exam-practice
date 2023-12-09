seq = list(map(int, input().split()))
cur = 1
i = 0
stack = []
jug = True
while i < 3:
    if seq[i] > cur:
        stack.append(cur)
        cur +=1
    elif seq[i] == cur:
        i += 1
        cur += 1
    else:
        if stack:
            popp = stack.pop()
            if popp == seq[i]:
                i += 1
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
