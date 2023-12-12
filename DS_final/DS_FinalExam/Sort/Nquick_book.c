#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inputarr(int*, int);
void showdata(int*, int);
void quick(int*, int, int, int);

int process = 0;

int main(void) {
    int size, data[100] = {0};
    srand((unsigned)time(NULL));

    printf("請輸入陣列大小(100以下):");
    scanf("%d", &size);

    printf("您輸入的原始資料是:\n");
    inputarr(data, size);
    showdata(data, size);

    quick(data, 0, size - 1, process);

    printf("\n排序結果:\n");
    showdata(data, size);

    system("pause");
    return 0;
}

void inputarr(int data[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        data[i] = (rand() % 99) + 1;
    }
}

void showdata(int data[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%3d", data[i]);
    }
    printf("\n");
}

void quick(int data[], int left, int right, int process) {
    int i, j, tmp;
    int lf_idx, rg_idx;

    if (left < right) {
        lf_idx = left + 1;
        rg_idx = right;
        while (1) {
            for (i = left + 1; i <= right; i++) {
                if (data[i] >= data[left]) {
                    lf_idx = i;
                    break;
                }
            }

            for (j = right; j >= left + 1; j--) {
                if (data[j] <= data[left]) {
                    rg_idx = j;
                    break;
                }
            }

            if (lf_idx < rg_idx) {
                tmp = data[lf_idx];
                data[lf_idx] = data[rg_idx];
                data[rg_idx] = tmp;
            } else {
                break;
            }
        }

        if (lf_idx >= rg_idx) {
            tmp = data[left];
            data[left] = data[rg_idx];
            data[rg_idx] = tmp;
        }

        quick(data, left, rg_idx - 1, process);
        quick(data, rg_idx + 1, right, process);
    }
}
