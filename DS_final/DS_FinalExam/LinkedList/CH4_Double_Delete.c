#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    int num;         // ���u�s��
    int score;       // ���u�~��
    char name[10];   // ���u�m�W
    struct employee *llink;  // ���V�e�@�Ӹ`�I�����w
    struct employee *rlink;  // ���V�U�@�Ӹ`�I�����w
};

typedef struct employee node;  // �w�q node �� employee ���c���s�W��
typedef node *link;  // �w�q link �� node ���w���s�W��

link findnode(link head, int num) {  // �b����M����w�s�����`�I
    link ptr;
    ptr = head;
    while (ptr != NULL) {
        if (ptr->num == num)
            return ptr;
        ptr = ptr->rlink;
    }
    return NULL;
}

link deletenode(link head, link del) {  // �R�����w�`�I
    if (head == NULL) {  // �p�G���O�Ū�
        printf("[��C�O�Ū�]\n");
        return NULL;
    }
    if (del == NULL) {  // �p�G�n�R�����`�I���b���
        printf("[���~: ���O��C�����`�I]\n");
        return NULL;
    }
    if (del == head) {  // �p�G�R�����O�Ĥ@�Ӹ`�I
        head = head->rlink;
        if (head != NULL) {
            head->llink = NULL;
        }
    } else {
        if (del->rlink == NULL) {  // �p�G�R�����O�̫�@�Ӹ`�I
            del->llink->rlink = NULL;
        } else {  // �R���������`�I
            del->llink->rlink = del->rlink;
            del->rlink->llink = del->llink;
        }
    }
    free(del);  // ����Q�R���`�I���O����
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

    printf("�u�s�� �s\n");
    printf(" -\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("[%2d][%8d]", data[j * 3 + i][0], data[j * 3 + i][1]);
        }
        printf("\n");
    }

    // �إ�����`�I
    head = (link)malloc(sizeof(node));
    if (head == NULL) {
        printf("Error!! �O����t�m����\n");
        exit(1);
    } else {
        memset(head, 0, sizeof(node));  // ��l�Ƹ`�I
        head->num = data[0][0];
        strcpy(head->name, namedata[0]);  // �ƻs�W��
        head->score = data[0][1];
        llinknode = head;
    }

    // �إ߾l�U���`�I
    for (i = 1; i < 12; i++) {
        newnode = (link)malloc(sizeof(node));
        memset(newnode, 0, sizeof(node));
        newnode->num = data[i][0];
        strcpy(newnode->name, namedata[i]);  // �ƻs�W��
        newnode->score = data[i][1];
        llinknode->rlink = newnode;
        newnode->llink = llinknode;
        llinknode = newnode;
    }

    // �R���`�I�ާ@
    while (1) {
        printf("\n�п�J�n�R�������u�s��, �n�������J�L�{, �п�J-1: ");
        scanf("%d", &position);
        if (position == -1)  // �פ����
            break;
        else {
            ptr = findnode(head, position);
            head = deletenode(head, ptr);
        }
    }

    // ��ܳѾl�����
    printf("\n\t���u�s��\t�m�W\t\t�~��\n");
    printf("\t=========================\n");
    ptr = head;
    while (ptr != NULL) {
        printf("\t[%2d]\t[%-10s]\t[%8d]\n", ptr->num, ptr->name, ptr->score);
        ptr = ptr->rlink;
    }

    system("pause");  // Windows �t�μȰ�
    return 0;
}
