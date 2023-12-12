#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    int num;                 // 員工編號
    int score;               // 分數
    char name[10];           // 姓名
    struct employee *llink;  // 左指標欄，指向前一節點
    struct employee *rlink;  // 右指標欄，指向後一節點
};

typedef struct employee node;
typedef node *link;

link findnode(link head, int num) {
    link ptr = head;        // 從頭節點開始
    while (ptr != NULL) {   // 遍歷直到結尾
        if (ptr->num == num) // 如果找到編號
            return ptr;     // 返回該節點
        ptr = ptr->rlink;   // 否則繼續到下一個節點
    }
    return NULL;           // 沒找到返回NULL
}

link insertnode(link head, link ptr, int num, int score, char name[10]) {
    link newnode = (link)malloc(sizeof(node)); // 為新節點分配記憶體
    if (newnode == NULL) {
        printf("記憶體分配失敗\n");
        exit(1);
    }
    memset(newnode, 0, sizeof(node));  // 初始化新節點
    newnode->num = num;                // 設置新節點的值
    newnode->score = score;
    strcpy(newnode->name, name);

    if (head == NULL) {                // 如果串列為空
        return newnode;                // 直接返回新節點作為首節點
    } else {
        if (ptr == NULL) {             // 如果插入點為NULL，插入到串列首
            newnode->rlink = head;     // 新節點的右指標指向目前的首節點
            head->llink = newnode;     // 目前首節點的左指標指向新節點
            return newnode;            // 新節點成為新的首節點
        } else {
            // 插入到ptr節點後面
            newnode->rlink = ptr->rlink; // 新節點的右指標指向ptr的下一節點
            if (ptr->rlink != NULL) {
                ptr->rlink->llink = newnode; // 如果ptr的下一節點不為NULL，設置其左指標為新節點
            }
            ptr->rlink = newnode; // ptr的右指標設為新節點
            newnode->llink = ptr; // 新節點的左指標指向ptr
        }
    }
    return head; // 返回更新後的串列首節點
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
    printf("員工編號分數\n");
    printf("===========\n");
    for(i=0; i<3; i++)
        for(j=0; j<4; j++)
            printf("%d %d\n", data[j*3+i][0], data[j*3+i][1]);
    printf("\n");

    head = (link)malloc(sizeof(node)); // 建立串列首
    if (head == NULL) {
        printf("Error!! 記憶體配置失敗\n");
        exit(1);
    } else {
        memset(head, 0, sizeof(node));
        head->num = data[0][0];
        strcpy(head->name, namedata[0]);
        head->score = data[0][1];
        llinknode = head;
    }

    for(i=1; i<12; i++) { // 建立串列
        newnode = (link)malloc(sizeof(node));
        memset(newnode, 0, sizeof(node));
        newnode->num = data[i][0];
        strcpy(newnode->name, namedata[i]);
        newnode->score = data[i][1];
        llinknode->rlink = newnode;
        newnode->llink = llinknode;
        llinknode = newnode;
    }

    while(1) {
        printf("請輸入要插入其後的員工編號, 如輸入的編號不在此串列中, \n");
        printf("新輸入的員工節點將視為此串列的串列首, 要結束插入過程, 請輸入 -1 : ");
        scanf("%d", &position);
        if(position == -1) // 迴圈中斷條件
            break;
        ptr = findnode(head, position);
        printf("請輸入新插入的員工編號: ");
        scanf("%d", &new_num);
        printf("請輸入新插入的員工分數: ");
        scanf("%d", &new_score);
        printf("請輸入新插入的員工姓名: ");
        scanf("%s", new_name);
        head = insertnode(head, ptr, new_num, new_score, new_name);
    }

    printf("\n員工編號 姓名 分數\n");
    printf("=====================\n");
    ptr = head;
    while(ptr != NULL) {
        printf("%d %s %d\n", ptr->num, ptr->name, ptr->score);
        ptr = ptr->rlink;
    }

    system("pause");
    return 0;
}
