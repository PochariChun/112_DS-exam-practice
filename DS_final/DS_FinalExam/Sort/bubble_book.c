#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, tmp;
    int data[8] = {16, 25, 39, 27, 12, 8, 45, 63}; // ��l���

    printf("��w�ƧǪk:\n��l��Ƭ�:");
    for (i = 0; i < 8; i++)
        printf("%3d ", data[i]);
    printf("\n");

    for (i = 7; i >= 0; i--) { // ���˦���
        for (j = 0; j < i; j++) { // �������
            if (data[j] > data[j + 1]) { // �����,�p�Ĥ@�Ƹ��j�h��
                tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
        printf("��%d���ƧǪ����G�O: ", 8 - i); // ��U�����y�����G�L�X
        for (j = 0; j < 8; j++)
            printf("%3d ", data[j]);
        printf("\n");
    }

    printf("�Ƨǫᵲ�G��:");
    for (i = 0; i < 8; i++)
        printf("%3d ", data[i]);
    printf("\n");

    system("pause");
    return 0;
}
