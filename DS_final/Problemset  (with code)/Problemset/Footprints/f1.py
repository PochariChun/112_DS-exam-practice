"""这个Python代码模拟了给定的C++代码的逻辑，对于每个测试案例，它计算字符串中的循环，并根据特定的规则确定是否输出 "Yes" 或 "No""""
def main():
    time = int(input())
    while time > 0:
        s = input()
        length = len(s)
        arr = [0] * length

        arr[0] += 1
        next_val = (int(s[0]) - 0) % length
        travel = length - 1

        while travel > 0:
            arr[next_val] += 1
            next_val = (next_val + (int(s[next_val]) - 0)) % length
            travel -= 1

        judge = all(i == 1 for i in arr)

        if judge == 0:
            print("No")
        else:
            print("Yes")
        time -= 1

if __name__ == "__main__":
    main()
