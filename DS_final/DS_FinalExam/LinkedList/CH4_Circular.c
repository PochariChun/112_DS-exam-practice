#include <stdio.h>
#include <stdlib.h>

struct student { // 定義學生結構
    char name[20]; // 學生姓名
    char no[10]; // 學生編號
    struct student *next; // 指向下一個學生的指針
};

typedef struct student s_data; // 將struct student重新定義為s_data

int main() {
    s_data *head; // 串列開頭指標
    s_data *ptr; // 存取指標
    s_data *new_data; // 新增元素所在位置指標
    int select; // 用戶選擇

    head = (s_data*)malloc(sizeof(s_data)); // 動態分配記憶體給串列首元素
    ptr = head; // 設定存取指標為串列首
    ptr->next = NULL; // 目前無下一個元素

    do {
        printf("(1)新增 (2)離開=> ");
        scanf("%d", &select); // 讀取用戶選擇
        if (select != 2) {
            printf("請輸入 姓名 學號: ");
            new_data = (s_data*)malloc(sizeof(s_data)); // 為新元素分配記憶體
            scanf("%s %s", new_data->name, new_data->no); // 讀取學生資料
            ptr->next = new_data; // 連接到鏈表
            new_data->next = NULL; // 新元素的下一個指針設為NULL
            ptr = new_data; // 更新存取指標
        }
    } while (select != 2);

    ptr->next = head; // 將最後一個節點的指標欄指向串列首

    // 以下代碼用於打印並釋放鏈表
    ptr = head->next; // 從第一個有效元素開始
    while (ptr != head) { // 遍歷直到回到串列首
        printf("姓名: %s, 學號: %s\n", ptr->name, ptr->no); // 打印學生資料
        s_data *temp = ptr; // 暫存當前指標
        ptr = ptr->next; // 移動到下一個元素
        free(temp); // 釋放當前元素記憶體
    }
    free(head); // 釋放串列首元素記憶體

    return 0;
}
