import sys

def license_plate_value(plate):
    """ 將車牌轉換為數值以便排序 """
    value = 0
    for char in plate:
        if 'A' <= char <= 'Z':  # 如果字元是大寫字母
            value = value * 52 + ord(char) - ord('A')
        else:  # 如果字元是小寫字母
            value = value * 52 + ord(char) - ord('a') + 26
    return value

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

def count_swaps(plates_values):
    swap_count = 0
    n = len(plates_values)

    # Create a list of tuples where each tuple contains the value and its original index
    indexed_plates = [(value, index) for index, value in enumerate(plates_values)]
    # Sort the list based on the values
    indexed_plates.sort()

    j = 0
    for sorted_index, (value, original_index) in enumerate(indexed_plates):
        # Calculate the difference between the sorted position and the original position
        if sorted_index == original_index + j:
            pass
        else:
            swap_count += abs(sorted_index - (original_index + j) )
            j += 1
        
    return swap_count


def main():

    num_plates = int(sys.stdin.readline().strip())  # 讀取車牌數量
    plates = sys.stdin.readline().strip().split()  # 讀取車牌列表
    plates_value = [license_plate_value(plate) for plate in plates] # Convert plates to their numeric values for easier comparison
    print(count_swaps(plates_value))  # 輸出所需的最小交換次數

if __name__ == "__main__":
    main()
