#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    int num, score;
    char name[10];
    struct employee *next;
};

typedef struct employee node;
typedef node *link;

link findnode(link head, int num) {
    link ptr = head;
    while (ptr != NULL) {
        if (ptr->num == num)
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

link insertnode(link head, link ptr, int num, int score, char name[10]) {
    link insertNode = (link)malloc(sizeof(node));
    if (!insertNode)
        return NULL;

    insertNode->num = num;
    insertNode->score = score;
    strcpy(insertNode->name, name);
    insertNode->next = NULL;

    if (ptr == NULL) { // 插入第一個節點
        insertNode->next = head;
        return insertNode;
    } else {
        if (ptr->next == NULL) { // 插入最後一個節點
            ptr->next = insertNode;
        } else { // 插入中間節點
            insertNode->next = ptr->next;
            ptr->next = insertNode;
        }
        return head;
    }
}

int main() {
    link head, ptr, newnode;
    int new_num, new_score;
    char new_name[10];
    int i, j, position = 0, find;
    int data[12][2] = { {1001, 32367}, {1002, 24388}, {1003, 27556}, {1007, 31299},
                        {1012, 42660}, {1014, 25676}, {1018, 44145}, {1043, 52182},
                        {1031, 32769}, {1037, 21100}, {1041, 32196}, {1046, 25776} };
    char namedata[12][10] = { "Allen", "Scott", "Marry", "John", "Mark", "Ricky",
                              "Lisa", "Jasica", "Hanson", "Amy", "Bob", "Jack" };

    head = (link)malloc(sizeof(node));
    if (!head) {
        printf("Error!! 記憶體配置失敗\n");
        exit(1);
    }

    head->num = data[0][0];
    strcpy(head->name, namedata[0]);
    head->score = data[0][1];
    head->next = NULL;
    ptr = head;

    for (i = 1; i < 12; i++) {
        newnode = (link)malloc(sizeof(node));
        newnode->num = data[i][0];
        strcpy(newnode->name, namedata[i]);
        newnode->score = data[i][1];
        newnode->next = NULL;
        ptr->next = newnode;
        ptr = ptr->next;
    }

    while (1) {
        printf("\n請輸入要插入其後的員工編號, 如輸入的編號不在此串列中, ");
        printf("新輸入的員工節點將視為此串列的串列首, 要結束插入過程, 請輸入-1: ");
        scanf("%d", &position);
        if (position == -1) // 迴圈中斷條件
            break;
        else
            ptr = findnode(head, position);

        printf("請輸入新插入的員工編號: ");
        scanf("%d", &new_num);
        printf("請輸入新插入的員工薪水: ");
        scanf("%d", &new_score);
        printf("請輸入新插入的員工姓名: ");
        scanf("%s", new_name);

        head = insertnode(head, ptr, new_num, new_score, new_name);
    }

    ptr = head;
    printf("\n員工編號 姓名 薪水\n");
    printf("======= ====== =====\n");
    while (ptr != NULL) {
        printf("%7d %-7s %5d\n", ptr->num, ptr->name, ptr->score);
        ptr = ptr->next;
    }

    system("pause");
    return 0;
}
