#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    int num;         // 員工編號
    int score;       // 薪資
    char name[10];   // 員工姓名
    struct employee *next; // 指向下一個員工的指標
};

typedef struct employee node; // 將 struct employee 定義為 node
typedef node *link;           // 將 node* 定義為 link

link del_ptr(link head, link ptr); // 函數原型聲明

int main() {
    link head, ptr, newnode;   // 定義頭指標、當前指標和新節點指標
    int i, j, find;            // 迴圈變數和搜尋變數
    int findword = 0;          // 搜尋關鍵字
    char namedata[12][10] = {"Allen", "Scott", "Marry", "John", "Mark", "Ricky", "Lisa", "Jasica", "Hanson", "Amy", "Bob", "Jack"}; // 員工名稱陣列
    int data[12][2] = { {1001, 32367}, {1002, 24388}, {1003, 27556}, {1007, 31299}, {1012, 42660}, {1014, 25676}, {1018, 44145}, {1043, 52182}, {1031, 32769}, {1037, 21100}, {1041, 32196}, {1046, 25776} }; // 員工編號和薪資資料

    printf("員工編號\n");
    printf("------\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("%5d [%5d] ", data[j * 3 + i][0], data[j * 3 + i][1]);
        }
        printf("\n");
    }

    head = (link)malloc(sizeof(node)); // 分配記憶體給串列首
    if (!head) {
        printf("Error!! 記憶體配置失敗!\n");
        exit(1);
    }
    head->num = data[0][0];
    strcpy(head->name, namedata[0]);
    head->score = data[0][1];
    head->next = NULL;

    ptr = head;
    for (i = 1; i < 12; i++) { // 建立串列
        newnode = (link)malloc(sizeof(node));
        newnode->num = data[i][0];
        strcpy(newnode->name, namedata[i]);
        newnode->score = data[i][1];
        newnode->next = NULL;
        ptr->next = newnode;
        ptr = ptr->next;
    }

    while (1) {
        printf("\n請輸入要刪除的員工編號, 要結束刪除過程, 請輸入 -1: ");
        scanf("%d", &findword);
        if (findword == -1) { // 迴圈中斷條件
            break;
        } else {
            ptr = head;
            find = 0;
            while (ptr != NULL) {
                if (ptr->num == findword) {
                    ptr = del_ptr(head, ptr);
                    find++;
                    head = ptr;
                    break;
                }
                ptr = ptr->next;
            }
            if (find == 0) {
                printf("查無此編號員工\n");
            }
        }
    }

    ptr = head;
    printf("\n員工座號\t姓名\t薪資\n");
    printf("======\t======\t======\n");
    while (ptr != NULL) {
        printf("%5d\t%-10s\t%5d\n", ptr->num, ptr->name, ptr->score);
        ptr = ptr->next;
    }

    system("pause"); // 暫停程式運行
    return 0; // 程式結束
}

link del_ptr(link head, link ptr) {
    link top;
    top = head;
    if (ptr->num == head->num) { // 刪除點在串列首
        head = head->next;
        printf("已刪除第 %d 號員工 姓名: %s 薪資: %d\n", ptr->num, ptr->name, ptr->score);
    } else {
        while (top->next != ptr) { // 找到刪除點的前一個位置
            top = top->next;
        }
        if (ptr->next == NULL) { // 刪除在串列尾的節點
            top->next = NULL;
        } else { // 刪除在串列中的任一節點
            top->next = ptr->next;
        }
        printf("已刪除第 %d 號員工 姓名: %s 薪資: %d\n", ptr->num, ptr->name, ptr->score);
    }
    free(ptr); // 釋放記憶體空間
    return head; // 回傳串列
}
