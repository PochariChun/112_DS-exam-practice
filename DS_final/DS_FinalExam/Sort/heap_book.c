#include <stdio.h>

void heap(int*, int);
void ad_heap(int*, int, int);

int main(void) {
    int i, size, data[9] = {0, 5, 6, 4, 8, 3, 2, 7, 1}; // 原始陣列內容
    size = 9;

    printf("原始陣列:");
    for (i = 1; i < size; i++) {
        printf("[%2d] ", data[i]);
    }

    heap(data, size); // 建立堆積樹

    printf("\n排序結果:");
    for (i = 1; i < size; i++) {
        printf("[%2d] ", data[i]);
    }
    printf("\n");
    return 0;
}

void heap(int *data, int size) {
    int i,j;
    for (i = (size / 2); i > 0; i--) { // 建立堆積樹節點
        ad_heap(data, i, size - 1);
    }

    for (i = size - 1; i > 1; i--) { // 堆積排序
        int tmp = data[i + 1]; // 頭尾節點交換
        data[i + 1] = data[i];
        data[1] = tmp;
        ad_heap(data, 1, i); // 處理剩餘節點
        printf("\n處理過程：");
        for(j=1;j<size;j++){
            printf("[%2d]",data[j]);
        }
    }
}

void ad_heap(int *data, int i, int size) {
    int j, tmp, post;
    tmp = data[i];
    j = 2 * i;
    post = 0;

    while (j <= size && post == 0) {
        if (j < size && data[j] < data[j + 1]) {
            j++;
        }

        if (tmp >= data[j]) {
            post = 1;
        }
        else{
        data[j / 2] = data[j];
        j = 2 * j;
        }
    }

    data[j / 2] = tmp; // 指定樹根為節點
}
