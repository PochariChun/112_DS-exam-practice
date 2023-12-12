#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data; // �`�I���
    struct tree *left, *right; // ���k�l�`�I����
};

typedef struct tree node; // node �� struct tree ���O�W
typedef node *btree; // btree �� node* ���O�W

btree create_tree(btree, int); // �إߤG���𪺨�ƭ쫬
void inorder(btree ptr); // ���Ǩ��X�Ƶ{������ƭ쫬

int main() {
    int i, data[] = {5, 6, 24, 8, 12, 3, 17, 1, 9}; // ��l�Ƽƾڰ}�C
    btree root = NULL; // ��l�Ʈڸ`�I

    for(i = 0; i < 9; i++) {
        root = create_tree(root, data[i]); // �إߤG����
    }

    printf("=== ���Ǩ��X���G ===\n");
    inorder(root); // ���Ǩ��X
    printf("\n");

    system("pause"); // Windows �t�μȰ��R�O
    return 0;
}

// �إߤG������
btree create_tree(btree root, int val) {
    btree newnode, current, backup = NULL;

    newnode = (btree)malloc(sizeof(node)); // �ʺA���t�O���鵹�s�`�I
    newnode->data = val; // �]�w�s�`�I�����
    newnode->left = NULL; // ��l�ƥ��l�`�I
    newnode->right = NULL; // ��l�ƥk�l�`�I

    if(root == NULL) {
        root = newnode; // �p�G�ڸ`�I���šA�h�s�`�I�����ڸ`�I
    } else {
        for(current = root; current != NULL;) {
            backup = current; // �O�s��e�`�I
            if(val < current->data) {
                current = current->left; // �V������
            } else {
                current = current->right; // �V�k����
            }
        }
        if(val < backup->data) {
            backup->left = newnode; // �s�`�I�������l�`�I
        } else {
            backup->right = newnode; // �s�`�I�����k�l�`�I
        }
    }
    return root; // ��^�ڸ`�I
}

// ���Ǩ��X�Ƶ{��
void inorder(btree ptr) {
    if (ptr != NULL) {
        inorder(ptr->left); // ���j�X�ݥ��l��
        printf(" [%d] ", ptr->data); // ��X�`�I���
        inorder(ptr->right); // ���j�X�ݥk�l��
    }
}
