M = int(input())

while M>0:
    uptri = 1
    dwtri = 1


    for i in range(5):
        row = list(map(int,input().split()))
        for j in range(5):
            cur_num = row[j]
            if i > j and cur_num:
                uptri = 0
            if i < j and cur_num:
                dwtri = 0
    if uptri:
        print("0")
    elif dwtri:
        print("1")
    else:
        print("-1")
    M -= 1



