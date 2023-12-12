#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data; // 節點資料
    struct tree *left, *right; // 左右子節點指標
};

typedef struct tree node; // node 為 struct tree 的別名
typedef node *btree; // btree 為 node* 的別名

btree create_tree(btree, int); // 建立二元樹的函數原型
void inorder(btree ptr); // 中序走訪副程式的函數原型

int main() {
    int i, data[] = {5, 6, 24, 8, 12, 3, 17, 1, 9}; // 初始化數據陣列
    btree root = NULL; // 初始化根節點

    for(i = 0; i < 9; i++) {
        root = create_tree(root, data[i]); // 建立二元樹
    }

    printf("=== 中序走訪結果 ===\n");
    inorder(root); // 中序走訪
    printf("\n");

    system("pause"); // Windows 系統暫停命令
    return 0;
}

// 建立二元樹函數
btree create_tree(btree root, int val) {
    btree newnode, current, backup = NULL;

    newnode = (btree)malloc(sizeof(node)); // 動態分配記憶體給新節點
    newnode->data = val; // 設定新節點的資料
    newnode->left = NULL; // 初始化左子節點
    newnode->right = NULL; // 初始化右子節點

    if(root == NULL) {
        root = newnode; // 如果根節點為空，則新節點成為根節點
    } else {
        for(current = root; current != NULL;) {
            backup = current; // 保存當前節點
            if(val < current->data) {
                current = current->left; // 向左移動
            } else {
                current = current->right; // 向右移動
            }
        }
        if(val < backup->data) {
            backup->left = newnode; // 新節點成為左子節點
        } else {
            backup->right = newnode; // 新節點成為右子節點
        }
    }
    return root; // 返回根節點
}

// 中序走訪副程式
void inorder(btree ptr) {
    if (ptr != NULL) {
        inorder(ptr->left); // 遞迴訪問左子樹
        printf(" [%d] ", ptr->data); // 輸出節點資料
        inorder(ptr->right); // 遞迴訪問右子樹
    }
}
