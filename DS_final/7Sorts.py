def shell_sort(arr):
    """
    希尔排序：内部排序，不稳定排序算法

    步骤：
    1. 初始化间隔（gap）为数组长度的一半。
    2. 对于每个间隔，进行插入排序，将间隔内的元素排序。
    3. 缩小间隔，重复第2步，直到间隔为1。

    参数：
    - arr：待排序的列表

    变量：
    - n：列表长度
    - gap：当前间隔大小
    - temp：用于交换元素的临时变量
    - i，j：循环变量

    """
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2

def heapify(arr, n, i):
    """
    堆排序的辅助函数

    参数：
    - arr：待排序的列表
    - n：列表长度
    - i：当前节点的索引

    """
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2
    if l < n and arr[l] > arr[largest]:
        largest = l
    if r < n and arr[r] > arr[largest]:
        largest = r
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def heap_sort(arr):
    """
    堆排序：内部排序，不稳定排序算法

    步骤：
    1. 建立最大堆（Max Heap）。
    2. 不断将堆顶元素与堆尾元素交换，然后修复堆。
    3. 重复步骤2，直到整个数组有序。

    参数：
    - arr：待排序的列表

    变量：
    - n：列表长度
    - i：循环变量

    """
    n = len(arr)
    for i in range(n//2 - 1, -1, -1):
        heapify(arr, n, i)
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

def quick_sort(arr):
    """
    快速排序：内部排序，不稳定排序算法

    步骤：
    1. 选择一个基准元素。
    2. 将小于基准的元素放在左边，大于基准的元素放在右边。
    3. 递归地对左右两部分进行排序。

    参数：
    - arr：待排序的列表

    变量：
    - pivot：基准元素
    - left，middle，right：用于存放左、中、右子数组的列表

    """
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

def selection_sort(arr):
    """
    选择排序：内部排序，不稳定排序算法

    步骤：
    1. 在未排序部分中找到最小元素。
    2. 将最小元素交换到已排序部分的末尾。
    3. 重复步骤1和2，直到整个数组有序。

    参数：
    - arr：待排序的列表

    变量：
    - min_idx：最小元素的索引
    - i，j：循环变量

    """
    for i in range(len(arr)):
        min_idx = i
        for j in range(i+1, len(arr)):
            if arr[min_idx] > arr[j]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

def bubble_sort(arr):
    """
    冒泡排序：内部排序，稳定排序算法

    步骤：
    1. 从列表的第一个元素开始，比较相邻的元素。
    2. 如果前一个元素大于后一个元素，则交换它们。
    3. 重复步骤1和2，直到没有任何交换发生，或者整个列表有序为止。

    参数：
    - arr：待排序的列表

    变量：
    - n：列表长度
    - i，j：循环变量

    """
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

def insertion_sort(arr):
    """
    插入排序：内部排序，稳定排序算法

    步骤：
    1. 从第二个元素开始，将当前元素插入已排序的子数组中的正确位置。
    2. 比较当前元素与已排序子数组的元素，向右移动大于当前元素的元素。
    3. 插入当前元素到正确位置。

    参数：
    - arr：待排序的列表

    变量：
    - key：当前元素
    - j：循环变量

    """
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
