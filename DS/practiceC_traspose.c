#include <stdio.h>

int main() {
    int m, n;

    // 读取矩阵的行数和列数
    scanf("%d %d", &m, &n);

    // 读取矩阵元素并存储在数组中
    int matrix[10][10]; // 假设矩阵最大为 10x10
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 计算并输出转置矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix[j][i]);
            if (j < m - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
