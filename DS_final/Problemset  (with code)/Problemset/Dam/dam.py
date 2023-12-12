def main():
    data = int(input())  # 输入测试案例数量
    for _ in range(data):
        num = int(input())  # 输入每个测试案例的元素数量
        height = list(map(int, input().split()))  # 输入每个测试案例的元素列表

        left = 0
        right = num - 1
        max_c = 0

        while right > left:
            value = height[left]

            if height[left] > height[right]:
                value = height[right]

            cap = value * (right - left)

            if max_c < cap:
                max_c = cap

            if height[left] > height[right]:
                right -= 1
            else:
                left += 1

        print(max_c)  # 输出每个测试案例的最大容量

if __name__ == "__main__":
    main()
