/* 選擇排序 */
void selectionSort(int nums[], int n) {
    // 外迴圈：未排序區間為 [i, n-1]
    for (int i = 0; i < n - 1; i++) {
        // 內迴圈：找到未排序區間內的最小元素
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[k])
                k = j; // 記錄最小元素的索引
        }
        // 將該最小元素與未排序區間的首個元素交換
        int temp = nums[i];
        nums[i] = nums[k];
        nums[k] = temp;
    }
}

/* 冒泡排序 */
void bubbleSort(int nums[], int size) {
    // 外迴圈：未排序區間為 [0, i]
    for (int i = size - 1; i > 0; i--) {
        // 內迴圈：將未排序區間 [0, i] 中的最大元素交換至該區間的最右端
        for (int j = 0; j < size - 1 - i; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

/* 冒泡排序（標誌優化）*/
void bubbleSortWithFlag(int nums[], int size) {
    // 外迴圈：未排序區間為 [0, i]
    for (int i = size - 1; i > 0; i--) {
        bool flag = false;
        // 內迴圈：將未排序區間 [0, i] 中的最大元素交換至該區間的最右端
        for (int j = 0; j < size - 1 - i; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
                flag = true;
            }
        }
        if (!flag)
            break;
    }
}

/* 插入排序 */
void insertionSort(int nums[], int size) {
    // 外迴圈：已排序元素數量為 1, 2, ..., n
    for (int i = 1; i < size; i++) {
        int base = nums[i], j = i - 1;
        // 內迴圈：將 base 插入到已排序部分的正確位置
        while (j >= 0 && nums[j] > base) {
            // 將 nums[j] 向右移動一位
            nums[j + 1] = nums[j];
            j--;
        }
        // 將 base 賦值到正確位置
        nums[j + 1] = base;
    }
}

/* 元素交換 */
void swap(int nums[], int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

/* 快速排序類 */
// 快速排序類-哨兵劃分
int partition(int nums[], int left, int right) {
    // 以 nums[left] 為基準數
    int i = left, j = right;
    while (i < j) {
        while (i < j && nums[j] >= nums[left]) {
            // 從右向左找首個小於基準數的元素
            j--;
        }
        while (i < j && nums[i] <= nums[left]) {
            // 從左向右找首個大於基準數的元素
            i++;
        }
        // 交換這兩個元素
        swap(nums, i, j);
    }
    // 將基準數交換至兩子陣列的分界線
    swap(nums, i, left);
    // 返回基準數的索引
    return i;
}

/* 快速排序類 */
// 快速排序類-哨兵劃分
int partition(int nums[], int left, int right) {
    // 以 nums[left] 為基準數
    int i = left, j = right;
    while (i < j) {
        while (i < j && nums[j] >= nums[left]) {
            // 從右向左找首個小於基準數的元素
            j--;
        }
        while (i < j && nums[i] <= nums[left]) {
            // 從左向右找首個大於基準數的元素
            i++;
        }
        // 交換這兩個元素
        swap(nums, i, j);
    }
    // 將基準數交換至兩子陣列的分界線
    swap(nums, i, left);
    // 返回基準數的索引
    return i;
}

// 快速排序類-快速排序
void quickSort(int nums[], int left, int right) {
    // 子陣列長度為 1 時終止遞迴
    if (left >= right) {
        return;
    }
    // 哨兵劃分
    int pivot = partition(nums, left, right);
    // 遞迴左子陣列、右子陣列
    quickSort(nums, left, pivot - 1);
    quickSort(nums, pivot + 1, right);
}

/* 快速排序類（中位基準數優化） */
// 選取三個元素的中位數
int medianThree(int nums[], int left, int mid, int right) {
    // 此處使用異或運算來簡化代碼
    // 異或規則為 0 ^ 0 = 1 ^ 1 = 0, 0 ^ 1 = 1 ^ 0 = 1
    if ((nums[left] < nums[mid]) ^ (nums[left] < nums[right]))
        return left;
    else if ((nums[mid] < nums[left]) ^ (nums[mid] < nums[right]))
        return mid;
    else
        return right;
}

/* 哨兵劃分（三數取中值） */ 
int partitionMedian(int nums[], int left, int right) {
    // 選取三個候選元素的中位數
    int med = medianThree(nums, left, (left + right) / 2, right);
    // 將中位數交換至陣列最左端
    swap(nums, left, med);
    // 以 nums[left] 為基準數
    int i = left, j = right;
    while (i < j) {
        while (i < j && nums[j] >= nums[left])
            j--; // 從右向左找首個小於基準數的元素
        while (i < j && nums[i] <= nums[left])
            i++;          // 從左向右找首個大於基準數的元素
        swap(nums, i, j); // 交換這兩個元素
    }
    swap(nums, i, left); // 將基準數交換至兩子陣列的分界線
    return i;            // 返回基準數的索引
}


/* 合併左子陣列和右子陣列 */
void merge(int *nums, int left, int mid, int right) {
    // 左子陣列區間 [left, mid], 右子陣列區間 [mid+1, right]
    // 創建一個臨時陣列 tmp ，用於存放合併後的結果
    int tmpSize = right - left + 1;
    int *tmp = (int *)malloc(tmpSize * sizeof(int));
    // 初始化左子陣列和右子陣列的起始索引
    int i = left, j = mid + 1, k = 0;
    // 當左右子陣列都還有元素時，比較並將較小的元素複製到臨時陣列中
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            tmp[k++] = nums[i++];
        } else {
            tmp[k++] = nums[j++];
        }
    }
    // 將左子陣列和右子陣列的剩餘元素複製到臨時陣列中
    while (i <= mid) {
        tmp[k++] = nums[i++];
    }
    while (j <= right) {
        tmp[k++] = nums[j++];
    }
    // 將臨時陣列 tmp 中的元素複製回原陣列 nums 的對應區間
    for (k = 0; k < tmpSize; ++k) {
        nums[left + k] = tmp[k];
    }
    // 釋放記憶體
    free(tmp);
}

/* 歸併排序 */
void mergeSort(int *nums, int left, int right) {
    // 終止條件
    if (left >= right)
        return; // 當子陣列長度為 1 時終止遞迴
    // 劃分階段
    int mid = (left + right) / 2;    // 計算中點
    mergeSort(nums, left, mid);      // 遞迴左子陣列
    mergeSort(nums, mid + 1, right); // 遞迴右子陣列
    // 合併階段
    merge(nums, left, mid, right);
}

/* 堆的長度為 n ，從節點 i 開始，從頂至底堆化 */
void siftDown(int nums[], int n, int i) {
    while (1) {
        // 判斷節點 i, l, r 中值最大的節點，記為 ma
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int ma = i;
        if (l < n && nums[l] > nums[ma])
            ma = l;
        if (r < n && nums[r] > nums[ma])
            ma = r;
        // 若節點 i 最大或索引 l, r 越界，則無須繼續堆化，跳出
        if (ma == i) {
            break;
        }
        // 交換兩節點
        int temp = nums[i];
        nums[i] = nums[ma];
        nums[ma] = temp;
        // 迴圈向下堆化
        i = ma;
    }
}

/* 堆排序 */
void heapSort(int nums[], int n) {
    // 建堆操作：堆化除葉節點以外的其他所有節點
    for (int i = n / 2 - 1; i >= 0; --i) {
        siftDown(nums, n, i);
    }
    // 從堆中提取最大元素，迴圈 n-1 輪
    for (int i = n - 1; i > 0; --i) {
        // 交換根節點與最右葉節點（交換首元素與尾元素）
        int tmp = nums[0];
        nums[0] = nums[i];
        nums[i] = tmp;
        // 以根節點為起點，從頂至底進行堆化
        siftDown(nums, i, 0);
    }
}

/* 桶排序 */
void bucketSort(float nums[], int size) {
    // 初始化 k = n/2 個桶，預期向每個桶分配 2 個元素
    int k = size / 2;
    float **buckets = calloc(k, sizeof(float *));
    for (int i = 0; i < k; i++) {
        // 每個桶最多可以分配 k 個元素
        buckets[i] = calloc(ARRAY_SIZE, sizeof(float));
    }

    // 1. 將陣列元素分配到各個桶中
    for (int i = 0; i < size; i++) {
        // 輸入資料範圍為 [0, 1)，使用 num * k 映射到索引範圍 [0, k-1]
        int bucket_idx = nums[i] * k;
        int j = 0;
        // 如果桶中有資料且資料小於當前值 nums[i], 要將其放到當前桶的後面，相當於 cpp 中的 push_back
        while (buckets[bucket_idx][j] > 0 && buckets[bucket_idx][j] < nums[i]) {
            j++;
        }
        float temp = nums[i];
        while (j < ARRAY_SIZE && buckets[bucket_idx][j] > 0) {
            swap(&temp, &buckets[bucket_idx][j]);
            j++;
        }
        buckets[bucket_idx][j] = temp;
    }

    // 2. 對各個桶執行排序
    for (int i = 0; i < k; i++) {
        qsort(buckets[i], ARRAY_SIZE, sizeof(float), compare_float);
    }

    // 3. 遍歷桶合併結果
    for (int i = 0, j = 0; j < k; j++) {
        for (int l = 0; l < ARRAY_SIZE; l++) {
            if (buckets[j][l] > 0) {
                nums[i++] = buckets[j][l];
            }
        }
    }

    // 釋放上述分配的記憶體
    for (int i = 0; i < k; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

/* 計數排序 */
// 簡單實現，無法用於排序物件
void countingSortNaive(int nums[], int size) {
    // 1. 統計陣列最大元素 m
    int m = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i] > m) {
            m = nums[i];
        }
    }
    // 2. 統計各數字的出現次數
    // counter[num] 代表 num 的出現次數
    int *counter = calloc(m, sizeof(int));
    for (int i = 0; i < size; i++) {
        counter[nums[i]]++;
    }
    // 3. 遍歷 counter ，將各元素填入原陣列 nums
    int i = 0;
    for (int num = 0; num < m + 1; num++) {
        for (int j = 0; j < counter[num]; j++, i++) {
            nums[i] = num;
        }
    }
    // 4. 釋放記憶體
    free(counter);
}

/* 計數排序 */
// 完整實現，可排序對象，並且是穩定排序
void countingSort(int nums[], int size) {
    // 1. 統計陣列最大元素 m
    int m = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i] > m) {
            m = nums[i];
        }
    }
    // 2. 統計各數字的出現次數
    // counter[num] 代表 num 的出現次數
    int *counter = calloc(m, sizeof(int));
    for (int i = 0; i < size; i++) {
        counter[nums[i]]++;
    }
    // 3. 求 counter 的首碼和，將“出現次數”轉換為“尾索引”
    // 即 counter[num]-1 是 num 在 res 中最後一次出現的索引
    for (int i = 0; i < m; i++) {
        counter[i + 1] += counter[i];
    }
    // 4. 倒序遍歷 nums ，將各元素填入結果陣列 res
    // 初始化陣列 res 用於記錄結果
    int *res = malloc(sizeof(int) * size);
    for (int i = size - 1; i >= 0; i--) {
        int num = nums[i];
        res[counter[num] - 1] = num; // 將 num 放置到對應索引處
        counter[num]--;              // 令首碼和自減 1 ，得到下次放置 num 的索引
    }
    // 使用結果陣列 res 覆蓋原陣列 nums
    memcpy(nums, res, size * sizeof(int));
    // 5. 釋放記憶體
    free(counter);
}


/* 獲取元素 num 的第 k 位元，其中 exp = 10^(k-1) */
int digit(int num, int exp) {
    // 傳入 exp 而非 k 可以避免在此重複執行昂貴的次方計算
    return (num / exp) % 10;
}

/* 計數排序（根據 nums 第 k 位元排序） */
void countingSortDigit(int nums[], int size, int exp) {
    // 十進位的位範圍為 0~9 ，因此需要長度為 10 的桶陣列
    int *counter = (int *)malloc((sizeof(int) * 10));
    // 統計 0~9 各數字的出現次數
    for (int i = 0; i < size; i++) {
        // 獲取 nums[i] 第 k 位，記為 d
        int d = digit(nums[i], exp);
        // 統計數字 d 的出現次數
        counter[d]++;
    }
    // 求首碼和，將“出現個數”轉換為“陣列索引”
    for (int i = 1; i < 10; i++) {
        counter[i] += counter[i - 1];
    }
    // 倒序遍歷，根據桶內統計結果，將各元素填入 res
    int *res = (int *)malloc(sizeof(int) * size);
    for (int i = size - 1; i >= 0; i--) {
        int d = digit(nums[i], exp);
        int j = counter[d] - 1; // 獲取 d 在陣列中的索引 j
        res[j] = nums[i];       // 將當前元素填入索引 j
        counter[d]--;           // 將 d 的數量減 1
    }
    // 使用結果覆蓋原陣列 nums
    for (int i = 0; i < size; i++) {
        nums[i] = res[i];
    }
}

/* 基數排序 */
void radixSort(int nums[], int size) {
    // 獲取陣列的最大元素，用於判斷最大位元數
    int max = INT32_MIN;
    for (size_t i = 0; i < size - 1; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    // 按照從低位元到高位的順序遍歷
    for (int exp = 1; max >= exp; exp *= 10)
        // 對陣列元素的第 k 位元執行計數排序
        // k = 1 -> exp = 1
        // k = 2 -> exp = 10
        // 即 exp = 10^(k-1)
        countingSortDigit(nums, size, exp);
}
