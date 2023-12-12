#include <stdio.h>
#include <stdlib.h>

// 定義建立二元樹的函數
void Btree_create(int *btree, int *data, int length) {
    int i, level;

    // 遍歷原始陣列
    for(i = 1; i < length; i++) { // 循環遍歷陣列中的每個元素
        // 從樹的根節點開始
        for(level = 1; btree[level] != 0; ) { // 遍歷二元樹直到找到空節點
            if(data[i] > btree[level]) // 如果陣列元素大於當前樹節點值
                level = level * 2 + 1; // 移動到右子樹
            else // 否則
                level = level * 2; // 移動到左子樹
        }
        btree[level] = data[i]; // 將陣列元素放入二元樹的正確位置
    }
}

int main() {
    int i;
    int length = 9;
    int data[] = {0, 6, 3, 5, 4, 7, 8, 9, 2}; // 原始陣列
    int btree[16] = {0}; // 初始化二元樹陣列

    // 打印原始陣列
    printf("原始陣列?容:\n");
    for(i = 0; i < length; i++) // 遍歷原始陣列
        printf("[%2d] ", data[i]);
    printf("\n");

    // 建立二元樹
    Btree_create(btree, data, length);

    // 打印二元樹內容
    printf("二元樹內容:\n");
    for(i = 1; i < 16; i++) // 遍歷二元樹陣列
        printf("[%2d] ", btree[i]);
    printf("\n");

    system("pause"); // 暫停程式, 等待用戶操作
    return 0;
}
