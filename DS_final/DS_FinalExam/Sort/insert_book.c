#include <stdio.h>
#include <stdlib.h>

#define SIZE 8 /* Define array size */

/* Declare the insertion sort function */
void inser(int data[]);

/* Declare the function to print array */
void showdata(int data[]);

int main() {
    int data[SIZE] = {16, 25, 39, 27, 12, 8, 45, 63}; // Correct array initialization
    printf("原始陣列是: ");
    showdata(data);
    printf("\n");

    inser(data); // Perform insertion sort

    printf("排序後陣列是: ");
    showdata(data);
    printf("\n");

    system("pause");
    return 0;
}

void showdata(int data[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%3d ", data[i]); // Correct formatting for printf
    }
    printf("\n");
}

void inser(int data[]) {
    int i, j, tmp;
    for (i = 1; i < SIZE; i++) {
        tmp = data[i];
        j = i - 1;
        while (j >= 0 && tmp < data[j]) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = tmp;
    }
}
