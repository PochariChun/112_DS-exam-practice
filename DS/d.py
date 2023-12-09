sequence = list(map(int, input().split()))
stack = []

current = 1
i = 0
jug = True

while i < 3:
    if sequence[i] > current:
        stack.append(current)
        current += 1
    elif sequence[i] == current:
        current += 1
        i += 1
    else:
        if stack:
            popped = stack.pop()
            if popped != sequence[i]:
                jug = False
                print("No")
                break
            else:
                i += 1
        else:
            jug = False
            print("No")
            break

if jug:
    print("Yes")
