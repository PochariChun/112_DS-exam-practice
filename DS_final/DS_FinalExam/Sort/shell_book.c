#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

void shell(int *, int);
void showdata(int *);

int main(void) {
    int data[SIZE] = {16, 25, 39, 27, 12, 8, 45, 63};
    printf("��l�}�C�O: ");
    showdata(data);
    printf("---------------------------------------\n");

    shell(data, SIZE);

    printf("\n�Ƨǫ�}�C�O: ");
    return 0;
}

void showdata(int data[]) {
    int i;
    for (i = 0; i < SIZE; i++) {
        printf("%3d ", data[i]);
    }
    printf("\n");
}

void shell(int data[], int size) {
    int i, j, tmp, jmp;
    int k = 1;
    jmp = size / 2;

    while (jmp != 0) {
        for (i = jmp; i < size; i++) {
            tmp = data[i];
            j = i - jmp;
            while (j >= 0 && tmp < data[j]) {
                data[j + jmp] = data[j];
                j = j - jmp;
            }
            data[j + jmp] = tmp;
        }

        printf("���j %d ���Ƨǵ��G: ", k++);
        showdata(data);
        printf("---------------------------------------\n");

        jmp = jmp / 2;
    }
}
