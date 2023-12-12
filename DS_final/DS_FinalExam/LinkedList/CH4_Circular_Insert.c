#include <stdio.h>
#include <stdlib.h>

// 定義員工結構
struct employee {
    int num;         // 員工編號
    int score;       // 員工分數
    char name[10];   // 員工姓名
    struct employee *next; // 指向下一個員工的指針
};

// 定義結構別名
typedef struct employee node;
typedef node *link;

// 函數：根據編號尋找節點
link findnode(link head, int num) {
    link ptr = head; // 從頭節點開始尋找
    while (ptr->next != head) {
        if (ptr->num == num) {
            return ptr; // 找到相符節點，返回指針
        }
        ptr = ptr->next;
    }
    return NULL; // 未找到節點，返回NULL
}

// 函數：刪除節點
link deletenode(link head, link del) {
    if (head == NULL) {
        printf("[環狀串列已經空了]\n");
        return NULL;
    }

    link CurNode, PreNode, TailNode;
    if (del == head) { // 要刪除的節點是串列首
        CurNode = head;
        // 找到最後一個節點
        while (CurNode->next != head) {
            CurNode = CurNode->next;
        }
        TailNode = CurNode; // 最後一個節點
        head = head->next; // 移動串列首
        TailNode->next = head; // 更新最後一個節點的指針
        return head;
    } else { // 要刪除的節點不是串列首
        CurNode = head;
        // 找到要刪除節點的前一個節點
        while (CurNode->next != del) {
            CurNode = CurNode->next;
        }
        PreNode = CurNode; // 前一個節點
        CurNode = CurNode->next; // 要刪除的節點
        PreNode->next = CurNode->next; // 更新前一個節點的指針
        return head;
    }
}

int main() {
    link head, ptr, newnode;
    int new_num, new_score;
    char new_name[10];
    int i, j, position = 0, find;
    // 初始化員工資料
    char namedata[12][10] = {"Allen", "Scott", "Marry", "John", "Mark", "Ricky", "Lisa", "Jasica", "Hanson", "Amy", "Bob", "Jack"};
    int data[12][2] = { {1001, 32367}, {1002, 24388}, {1003, 27556}, {1007, 31299}, {1012, 42660}, {1014, 25676}, {1018, 44145}, {1043, 52182}, {1031, 32769}, {1037, 21100}, {1041, 32196}, {1046, 25776} };

    printf("員工編號 姓名 薪資\n");
    printf("----------------------\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("%4d %s %5d\n", data[j * 3 + i][0], namedata[j * 3 + i], data[j * 3 + i][1]);
        }
    }
    printf("\n");

    // 建立串列首
    head = (link)malloc(sizeof(node));
    if (!head) {
        printf("Error!! 記憶體配置失敗\n");
        exit(1);
    }
    head->num = data[0][0];
    strcpy(head->name, namedata[0]); // 複製名字
    head->score = data[0][1];
    head->next = NULL;

    ptr = head;
    // 建立其餘員工節點
    for (i = 1; i < 12; i++) {
        newnode = (link)malloc(sizeof(node));
        newnode->num = data[i][0];
        strcpy(newnode->name, namedata[i]); // 複製名字
        newnode->score = data[i][1];
        newnode->next = NULL;
        ptr->next = newnode; // 將前一個節點指向新節點
        ptr = newnode;
    }
    newnode->next = head; // 形成環狀串列

    while (1) {
        printf("\n請輸入要刪除的員工編號, 要結束插入過程, 請輸入-1: ");
        scanf("%d", &position);
        if (position == -1) {
            break; // 中斷迴圈
        } else {
            ptr = findnode(head, position);
            if (ptr == NULL) {
                printf("串列中沒這個節點。\n");
                break;
            } else {
                head = deletenode(head, ptr);
                printf("已刪除員工 編號: %d 姓名: %s 薪資: %d\n", ptr->num, ptr->name, ptr->score);
            }
        }
    }

    // 顯示剩餘員工資料
    printf("\n員工編號\t姓名\t薪資\n");
    printf("--------------------------\n");
    ptr = head;
    do {
        printf("%4d\t%-10s\t%5d\n", ptr->num, ptr->name, ptr->score);
        ptr = ptr->next;
    } while (ptr != head); // 遍歷環狀串列

    system("pause");
    return 0;
}
