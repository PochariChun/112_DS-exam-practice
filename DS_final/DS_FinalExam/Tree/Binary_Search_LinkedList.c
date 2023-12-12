#include <stdio.h>
#include <stdlib.h>

struct tree { // �w�q�G���𪺵��I���c
    int data; // �s�x�ƾ�
    struct tree *left, *right; // ���V���l��M�k�l�𪺫��w
};

typedef struct tree node; // �w�q���c�O�W 'node'
typedef node *btree; // �w�q���V���c�����w�O�W 'btree'

btree creat_tree(btree, int); // �e�m�n�����

int main() {
    int i, data[] = {5, 6, 24, 8, 12, 3, 17, 1, 9}; // ��l�Ƽƾڰ}�C
    btree ptr = NULL; // ��l�ƫ��w
    btree root = NULL; // ��l�Ʈڸ`�I

    for(i = 0; i < 9; i++) { // �v�Ӵ��J�ƾڨ��
        ptr = creat_tree(ptr, data[i]);
    }

    printf("���l��:\n");
    root = ptr->left; // ���V���l��
    while (root != NULL) {
        printf("%d\n", root->data); // ��X���l��ƾ�
        root = root->left; // ���ܤU�@�ӥ��`�I
    }

    printf("\n�k�l��:\n");
    root = ptr->right; // ���V�k�l��
    while(root != NULL) {
        printf("%d\n", root->data); // ��X�k�l��ƾ�
        root = root->right; // ���ܤU�@�ӥk�`�I
    }

    system("pause"); // Windows���x�U�Ȱ��{��
    return 0;
}

btree creat_tree(btree root, int val) {
    btree newnode, current, backup;
    newnode = (btree)malloc(sizeof(node)); // ���t�O���鵹�s�`�I
    newnode->data = val; // �]�w�ƾ�
    newnode->left = NULL; // ��l�ƥ��l��
    newnode->right = NULL; // ��l�ƥk�l��

    if(root == NULL) {
        root = newnode; // �p�G��O�Ū��A�]�w�s�`�I����
    } else {
        for (current = root; current != NULL;) {
            backup = current; // �x�s�e�@�Ӹ`�I
            if(current->data > val) {
                current = current->left; // ���ʨ쥪�l��
            } else {
                current = current->right; // ���ʨ�k�l��
            }
        }

        if(backup->data > val) {
            backup->left = newnode; // ���J�쥪�l��
        } else {
            backup->right = newnode; // ���J��k�l��
        }
    }

    return root; // ��^�𪺮ڸ`�I
}
