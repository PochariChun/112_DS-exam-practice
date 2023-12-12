def report_and_leave(n, a, b):
    participants = list(range(1, n + 1))
    leave_order = []  
    index = a - 1  

    while len(participants) > 1:
        index = (index + b - 1) % len(participants)
        leave_order.append(participants.pop(index))

    leave_order.append(participants[0])

    return leave_order
def main():
    n, a, b = map(int, input().split())
    leaving_order = report_and_leave(n, a, b)
    print(" ".join(map(str, leaving_order)))

if __name__ == "__main__":
    main()

