#include <stdio.h>
#include <stdlib.h>

struct tree { // 定義二元樹的結點結構
    int data; // 存儲數據
    struct tree *left, *right; // 指向左子樹和右子樹的指針
};

typedef struct tree node; // 定義結構別名 'node'
typedef node *btree; // 定義指向結構的指針別名 'btree'

btree creat_tree(btree, int); // 前置聲明函數

int main() {
    int i, data[] = {5, 6, 24, 8, 12, 3, 17, 1, 9}; // 初始化數據陣列
    btree ptr = NULL; // 初始化指針
    btree root = NULL; // 初始化根節點

    for(i = 0; i < 9; i++) { // 逐個插入數據到樹中
        ptr = creat_tree(ptr, data[i]);
    }

    printf("左子樹:\n");
    root = ptr->left; // 指向左子樹
    while (root != NULL) {
        printf("%d\n", root->data); // 輸出左子樹數據
        root = root->left; // 移至下一個左節點
    }

    printf("\n右子樹:\n");
    root = ptr->right; // 指向右子樹
    while(root != NULL) {
        printf("%d\n", root->data); // 輸出右子樹數據
        root = root->right; // 移至下一個右節點
    }

    system("pause"); // Windows平台下暫停程序
    return 0;
}

btree creat_tree(btree root, int val) {
    btree newnode, current, backup;
    newnode = (btree)malloc(sizeof(node)); // 分配記憶體給新節點
    newnode->data = val; // 設定數據
    newnode->left = NULL; // 初始化左子樹
    newnode->right = NULL; // 初始化右子樹

    if(root == NULL) {
        root = newnode; // 如果樹是空的，設定新節點為根
    } else {
        for (current = root; current != NULL;) {
            backup = current; // 儲存前一個節點
            if(current->data > val) {
                current = current->left; // 移動到左子樹
            } else {
                current = current->right; // 移動到右子樹
            }
        }

        if(backup->data > val) {
            backup->left = newnode; // 插入到左子樹
        } else {
            backup->right = newnode; // 插入到右子樹
        }
    }

    return root; // 返回樹的根節點
}
