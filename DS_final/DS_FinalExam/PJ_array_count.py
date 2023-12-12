def report_and_leave(n, a, b):
    # 初始化參與者的清單
    participants = list(range(1, n + 1))
    leave_order = []  # 離開的順序
    index = a - 1  # 從編號 a 的人開始報數

    while len(participants) > 1:
        # 計算報到 b 的人的索引
        index = (index + b - 1) % len(participants)
        # 記錄離開的人的編號
        leave_order.append(participants.pop(index))

    # 加入最後一個留下的人
    leave_order.append(participants[0])

    return leave_order
def main():
    n, a, b = map(int, input().split())
    leaving_order = report_and_leave(n, a, b)
    print(" ".join(map(str, leaving_order)))

if __name__ == "__main__":
    main()
# # 範例輸入
# n, a, b = 5, 1, 3
# # 範例輸出  
# print(*report_and_leave(n, a, b))
