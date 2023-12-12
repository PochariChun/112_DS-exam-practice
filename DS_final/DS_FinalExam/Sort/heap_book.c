#include <stdio.h>

void heap(int*, int);
void ad_heap(int*, int, int);

int main(void) {
    int i, size, data[9] = {0, 5, 6, 4, 8, 3, 2, 7, 1}; // ��l�}�C���e
    size = 9;

    printf("��l�}�C:");
    for (i = 1; i < size; i++) {
        printf("[%2d] ", data[i]);
    }

    heap(data, size); // �إ߰�n��

    printf("\n�Ƨǵ��G:");
    for (i = 1; i < size; i++) {
        printf("[%2d] ", data[i]);
    }
    printf("\n");
    return 0;
}

void heap(int *data, int size) {
    int i,j;
    for (i = (size / 2); i > 0; i--) { // �إ߰�n��`�I
        ad_heap(data, i, size - 1);
    }

    for (i = size - 1; i > 1; i--) { // ��n�Ƨ�
        int tmp = data[i + 1]; // �Y���`�I�洫
        data[i + 1] = data[i];
        data[1] = tmp;
        ad_heap(data, 1, i); // �B�z�Ѿl�`�I
        printf("\n�B�z�L�{�G");
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

    data[j / 2] = tmp; // ���w��ڬ��`�I
}
