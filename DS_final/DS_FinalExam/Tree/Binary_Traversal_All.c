#include <stdio.h>
#include <stdlib.h>

// 定義二元樹的結構
struct tree {
    int data;
    struct tree *left, *right;
};

typedef struct tree node;
typedef node *btree;

// 函數原型宣告
btree create_tree(btree, int);
void inorder(btree);
void postorder(btree);
void preorder(btree);

// 建立二元樹函數
btree create_tree(btree root, int val) {
    btree newnode, current, backup;
    newnode = (btree)malloc(sizeof(node)); // 分配記憶體給新節點
    newnode->data = val; // 設置新節點的數據
    newnode->left = NULL; // 新節點左子樹設為 NULL
    newnode->right = NULL; // 新節點右子樹設為 NULL

    if(root == NULL) {
        root = newnode; // 如果樹為空，新節點成為根節點
    } else {
        for(current = root; current != NULL;) {
            backup = current;
            if(current->data > val) {
                current = current->left; // 向左子樹移動
            } else {
                current = current->right; // 向右子樹移動
            }
        }

        if(backup->data > val) {
            backup->left = newnode; // 新節點連接到左子樹
        } else {
            backup->right = newnode; // 新節點連接到右子樹
        }
    }

    return root;
}

// 中序走訪副程式
void inorder(btree ptr) {
    if (ptr != NULL) {
        inorder(ptr->left); // 遞迴左子樹
        printf("[%2d] ", ptr->data); // 輸出節點數據
        inorder(ptr->right); // 遞迴右子樹
    }
}

// 後序走訪副程式
void postorder(btree ptr) {
    if (ptr != NULL) {
        postorder(ptr->left); // 遞迴左子樹
        postorder(ptr->right); // 遞迴右子樹
        printf("[%2d] ", ptr->data); // 輸出節點數據
    }
}

// 前序走訪副程式
void preorder(btree ptr) {
    if (ptr != NULL) {
        printf("[%2d] ", ptr->data); // 輸出節點數據
        preorder(ptr->left); // 遞迴左子樹
        preorder(ptr->right); // 遞迴右子樹
    }
}

int main() {
    int i, data[] = {7, 4, 1, 5, 16, 8, 11, 12, 15, 9, 2};
    btree ptr = NULL;

    for(i = 0; i < 11; i++) {
        ptr = create_tree(ptr, data[i]); // 建立二元樹
    }

    printf("===== 中序式走訪結果: =====\n");
    inorder(ptr); // 中序走訪
    printf("\n");

    printf("===== 後序式走訪結果: =====\n");
    postorder(ptr); // 後序走訪
    printf("\n");

    printf("===== 前序式走訪結果: =====\n");
    preorder(ptr); // 前序走訪
    printf("\n");

    system("pause");
    return 0;
}
