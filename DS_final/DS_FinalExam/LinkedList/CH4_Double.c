#include <stdio.h>
#include <stdlib.h>

typedef struct student { // 定義學生結構
    char name[20];      // 學生姓名
    int Math;           // 數學成績
    int Eng;            // 英文成績
    char no[10];        // 學號
    struct student *rlink; // 指向下一個學生的指標
    struct student *llink; // 指向上一個學生的指標
} s_data;

int main() {
    int select;           // 選擇變數
    s_data *head;         // 串列開頭指標
    s_data *ptr;          // 存取指標

    // 初始化頭節點
    head = (s_data*) malloc(sizeof(s_data)); // 動態分配記憶體給頭節點
    head->llink = NULL;   // 初始化左指標
    head->rlink = NULL;   // 初始化右指標
    ptr = head;           // 設定存取指標為頭節點

    do {
        printf("(1)新增 (2)離開 => "); // 顯示選項
        scanf("%d", &select);          // 讀取使用者選擇

        if (select != 2) {
            printf("請輸入 姓名 學號 數學成績 英文成績: "); // 提示輸入信息
            s_data *new_data = (s_data*) malloc(sizeof(s_data)); // 為新學生分配記憶體

            // 讀取學生信息
            scanf("%s %s %d %d", new_data->name, new_data->no, &new_data->Math, &new_data->Eng);

            // 插入新節點到串列中
            ptr->rlink = new_data; // 設定當前節點的右指標指向新節點
            new_data->rlink = NULL; // 新節點的右指標設為NULL
            new_data->llink = ptr;  // 新節點的左指標指向前一節點
            ptr = new_data;         // 移動ptr到新節點
        }
    } while (select != 2);

    // 輸出學生信息
    ptr = head->rlink; // 設定ptr從頭節點的右指標開始
    putchar('\n');
    while (ptr != NULL) {
        printf("姓名: %s 學號: %s 數學成績: %d 英文成績: %d\n", ptr->name, ptr->no, ptr->Math, ptr->Eng);
        ptr = ptr->rlink; // 移動到下一個節點
    }

    // 結束程序
    system("pause"); // 在Windows環境下暫停程序
    return 0;
}
