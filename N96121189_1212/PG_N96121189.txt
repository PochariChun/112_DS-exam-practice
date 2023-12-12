def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)

def fibonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        a, b = 0, 1
        for _ in range(2, n + 1):
            a, b = b, a + b
        return b

def main():
    m = int(input())
    for _ in range(m):
        n = int(input())
        result = fibonacci(factorial(n) % 19)
        print(result)
        # print('A:',result)

if __name__ == "__main__":
    main()
