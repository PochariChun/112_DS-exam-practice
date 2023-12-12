#include <stdio.h>
#include <stdlib.h>

// �w�q�G���𪺵��c
struct tree {
    int data;
    struct tree *left, *right;
};

typedef struct tree node;
typedef node *btree;

// ��ƭ쫬�ŧi
btree create_tree(btree, int);
void inorder(btree);
void postorder(btree);
void preorder(btree);

// �إߤG������
btree create_tree(btree root, int val) {
    btree newnode, current, backup;
    newnode = (btree)malloc(sizeof(node)); // ���t�O���鵹�s�`�I
    newnode->data = val; // �]�m�s�`�I���ƾ�
    newnode->left = NULL; // �s�`�I���l��]�� NULL
    newnode->right = NULL; // �s�`�I�k�l��]�� NULL

    if(root == NULL) {
        root = newnode; // �p�G�𬰪šA�s�`�I�����ڸ`�I
    } else {
        for(current = root; current != NULL;) {
            backup = current;
            if(current->data > val) {
                current = current->left; // �V���l�𲾰�
            } else {
                current = current->right; // �V�k�l�𲾰�
            }
        }

        if(backup->data > val) {
            backup->left = newnode; // �s�`�I�s���쥪�l��
        } else {
            backup->right = newnode; // �s�`�I�s����k�l��
        }
    }

    return root;
}

// ���Ǩ��X�Ƶ{��
void inorder(btree ptr) {
    if (ptr != NULL) {
        inorder(ptr->left); // ���j���l��
        printf("[%2d] ", ptr->data); // ��X�`�I�ƾ�
        inorder(ptr->right); // ���j�k�l��
    }
}

// ��Ǩ��X�Ƶ{��
void postorder(btree ptr) {
    if (ptr != NULL) {
        postorder(ptr->left); // ���j���l��
        postorder(ptr->right); // ���j�k�l��
        printf("[%2d] ", ptr->data); // ��X�`�I�ƾ�
    }
}

// �e�Ǩ��X�Ƶ{��
void preorder(btree ptr) {
    if (ptr != NULL) {
        printf("[%2d] ", ptr->data); // ��X�`�I�ƾ�
        preorder(ptr->left); // ���j���l��
        preorder(ptr->right); // ���j�k�l��
    }
}

int main() {
    int i, data[] = {7, 4, 1, 5, 16, 8, 11, 12, 15, 9, 2};
    btree ptr = NULL;

    for(i = 0; i < 11; i++) {
        ptr = create_tree(ptr, data[i]); // �إߤG����
    }

    printf("===== ���Ǧ����X���G: =====\n");
    inorder(ptr); // ���Ǩ��X
    printf("\n");

    printf("===== ��Ǧ����X���G: =====\n");
    postorder(ptr); // ��Ǩ��X
    printf("\n");

    printf("===== �e�Ǧ����X���G: =====\n");
    preorder(ptr); // �e�Ǩ��X
    printf("\n");

    system("pause");
    return 0;
}
