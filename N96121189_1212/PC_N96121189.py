import sys

def bubble_sort(arr):
    rest = 0
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                rest+=1
    return rest

def main():

    kingdom = int(input().strip())     
    for _ in range(kingdom):
        city_num = input()  
        city_value = list(map(int,input().strip().split()))
        print(bubble_sort(city_value)) 

if __name__ == "__main__":
    main()
