M = int(input())

while M > 0:
    is_upper_triangle = 1
    is_lower_triangle = 1

    for i in range(5):
        row = list(map(int, input().split()))
        for j in range(5):
            x = row[j]

            # 判断是否为上三角矩阵
            if i > j and x != 0:
                is_upper_triangle = 0
            # 判断是否为下三角矩阵
            if i < j and x != 0:
                is_lower_triangle = 0

    if is_upper_triangle and not is_lower_triangle:
        print("0")
    elif not is_upper_triangle and is_lower_triangle:
        print("1")
    else:
        print("-1")

    M -= 1
