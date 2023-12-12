#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    int num;         // 員工編號
    int score;       // 員工薪水
    char name[10];   // 員工姓名
    struct employee *llink;  // 指向前一個節點的指針
    struct employee *rlink;  // 指向下一個節點的指針
};

typedef struct employee node;  // 定義 node 為 employee 結構的新名稱
typedef node *link;  // 定義 link 為 node 指針的新名稱

link findnode(link head, int num) {  // 在鏈表中尋找指定編號的節點
    link ptr;
    ptr = head;
    while (ptr != NULL) {
        if (ptr->num == num)
            return ptr;
        ptr = ptr->rlink;
    }
    return NULL;
}

link deletenode(link head, link del) {  // 刪除指定節點
    if (head == NULL) {  // 如果鏈表是空的
        printf("[串列是空的]\n");
        return NULL;
    }
    if (del == NULL) {  // 如果要刪除的節點不在鏈表中
        printf("[錯誤: 不是串列中的節點]\n");
        return NULL;
    }
    if (del == head) {  // 如果刪除的是第一個節點
        head = head->rlink;
        if (head != NULL) {
            head->llink = NULL;
        }
    } else {
        if (del->rlink == NULL) {  // 如果刪除的是最後一個節點
            del->llink->rlink = NULL;
        } else {  // 刪除中間的節點
            del->llink->rlink = del->rlink;
            del->rlink->llink = del->llink;
        }
    }
    free(del);  // 釋放被刪除節點的記憶體
    return head;
}

int main() {
    link head, ptr;
    link llinknode = NULL;
    link newnode = NULL;
    int new_num, new_score;
    char new_name[10];
    int i, j, position = 0, find;
    int data[12][2] = {{1001, 32367}, {1002, 24388}, {1003, 27556}, {1007, 31299},
                       {1012, 42660}, {1014, 25676}, {1018, 44145}, {1043, 52182},
                       {1031, 32769}, {1037, 21100}, {1041, 32196}, {1046, 25776}};
    char namedata[12][10] = {"Allen", "Scott", "Marry", "John", 
                             "Mark", "Ricky", "Lisa", "Jasica", 
                             "Hanson", "Amy", "Bob", "Jack"};

    printf("工編號 編\n");
    printf(" -\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("[%2d][%8d]", data[j * 3 + i][0], data[j * 3 + i][1]);
        }
        printf("\n");
    }

    // 建立鏈表首節點
    head = (link)malloc(sizeof(node));
    if (head == NULL) {
        printf("Error!! 記憶體配置失敗\n");
        exit(1);
    } else {
        memset(head, 0, sizeof(node));  // 初始化節點
        head->num = data[0][0];
        strcpy(head->name, namedata[0]);  // 複製名稱
        head->score = data[0][1];
        llinknode = head;
    }

    // 建立餘下的節點
    for (i = 1; i < 12; i++) {
        newnode = (link)malloc(sizeof(node));
        memset(newnode, 0, sizeof(node));
        newnode->num = data[i][0];
        strcpy(newnode->name, namedata[i]);  // 複製名稱
        newnode->score = data[i][1];
        llinknode->rlink = newnode;
        newnode->llink = llinknode;
        llinknode = newnode;
    }

    // 刪除節點操作
    while (1) {
        printf("\n請輸入要刪除的員工編號, 要結束插入過程, 請輸入-1: ");
        scanf("%d", &position);
        if (position == -1)  // 終止條件
            break;
        else {
            ptr = findnode(head, position);
            head = deletenode(head, ptr);
        }
    }

    // 顯示剩餘的鏈表
    printf("\n\t員工編號\t姓名\t\t薪水\n");
    printf("\t=========================\n");
    ptr = head;
    while (ptr != NULL) {
        printf("\t[%2d]\t[%-10s]\t[%8d]\n", ptr->num, ptr->name, ptr->score);
        ptr = ptr->rlink;
    }

    system("pause");  // Windows 系統暫停
    return 0;
}
