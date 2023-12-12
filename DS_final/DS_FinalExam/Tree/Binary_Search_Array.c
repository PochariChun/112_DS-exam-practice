#include <stdio.h>
#include <stdlib.h>

// �w�q�إߤG���𪺨��
void Btree_create(int *btree, int *data, int length) {
    int i, level;

    // �M����l�}�C
    for(i = 1; i < length; i++) { // �`���M���}�C�����C�Ӥ���
        // �q�𪺮ڸ`�I�}�l
        for(level = 1; btree[level] != 0; ) { // �M���G���𪽨���Ÿ`�I
            if(data[i] > btree[level]) // �p�G�}�C�����j���e��`�I��
                level = level * 2 + 1; // ���ʨ�k�l��
            else // �_�h
                level = level * 2; // ���ʨ쥪�l��
        }
        btree[level] = data[i]; // �N�}�C������J�G���𪺥��T��m
    }
}

int main() {
    int i;
    int length = 9;
    int data[] = {0, 6, 3, 5, 4, 7, 8, 9, 2}; // ��l�}�C
    int btree[16] = {0}; // ��l�ƤG����}�C

    // ���L��l�}�C
    printf("��l�}�C?�e:\n");
    for(i = 0; i < length; i++) // �M����l�}�C
        printf("[%2d] ", data[i]);
    printf("\n");

    // �إߤG����
    Btree_create(btree, data, length);

    // ���L�G���𤺮e
    printf("�G���𤺮e:\n");
    for(i = 1; i < 16; i++) // �M���G����}�C
        printf("[%2d] ", btree[i]);
    printf("\n");

    system("pause"); // �Ȱ��{��, ���ݥΤ�ާ@
    return 0;
}
