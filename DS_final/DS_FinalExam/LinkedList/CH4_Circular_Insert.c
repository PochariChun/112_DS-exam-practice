#include <stdio.h>
#include <stdlib.h>

// �w�q���u���c
struct employee {
    int num;         // ���u�s��
    int score;       // ���u����
    char name[10];   // ���u�m�W
    struct employee *next; // ���V�U�@�ӭ��u�����w
};

// �w�q���c�O�W
typedef struct employee node;
typedef node *link;

// ��ơG�ھڽs���M��`�I
link findnode(link head, int num) {
    link ptr = head; // �q�Y�`�I�}�l�M��
    while (ptr->next != head) {
        if (ptr->num == num) {
            return ptr; // ���۲Ÿ`�I�A��^���w
        }
        ptr = ptr->next;
    }
    return NULL; // �����`�I�A��^NULL
}

// ��ơG�R���`�I
link deletenode(link head, link del) {
    if (head == NULL) {
        printf("[������C�w�g�ŤF]\n");
        return NULL;
    }

    link CurNode, PreNode, TailNode;
    if (del == head) { // �n�R�����`�I�O��C��
        CurNode = head;
        // ���̫�@�Ӹ`�I
        while (CurNode->next != head) {
            CurNode = CurNode->next;
        }
        TailNode = CurNode; // �̫�@�Ӹ`�I
        head = head->next; // ���ʦ�C��
        TailNode->next = head; // ��s�̫�@�Ӹ`�I�����w
        return head;
    } else { // �n�R�����`�I���O��C��
        CurNode = head;
        // ���n�R���`�I���e�@�Ӹ`�I
        while (CurNode->next != del) {
            CurNode = CurNode->next;
        }
        PreNode = CurNode; // �e�@�Ӹ`�I
        CurNode = CurNode->next; // �n�R�����`�I
        PreNode->next = CurNode->next; // ��s�e�@�Ӹ`�I�����w
        return head;
    }
}

int main() {
    link head, ptr, newnode;
    int new_num, new_score;
    char new_name[10];
    int i, j, position = 0, find;
    // ��l�ƭ��u���
    char namedata[12][10] = {"Allen", "Scott", "Marry", "John", "Mark", "Ricky", "Lisa", "Jasica", "Hanson", "Amy", "Bob", "Jack"};
    int data[12][2] = { {1001, 32367}, {1002, 24388}, {1003, 27556}, {1007, 31299}, {1012, 42660}, {1014, 25676}, {1018, 44145}, {1043, 52182}, {1031, 32769}, {1037, 21100}, {1041, 32196}, {1046, 25776} };

    printf("���u�s�� �m�W �~��\n");
    printf("----------------------\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("%4d %s %5d\n", data[j * 3 + i][0], namedata[j * 3 + i], data[j * 3 + i][1]);
        }
    }
    printf("\n");

    // �إߦ�C��
    head = (link)malloc(sizeof(node));
    if (!head) {
        printf("Error!! �O����t�m����\n");
        exit(1);
    }
    head->num = data[0][0];
    strcpy(head->name, namedata[0]); // �ƻs�W�r
    head->score = data[0][1];
    head->next = NULL;

    ptr = head;
    // �إߨ�l���u�`�I
    for (i = 1; i < 12; i++) {
        newnode = (link)malloc(sizeof(node));
        newnode->num = data[i][0];
        strcpy(newnode->name, namedata[i]); // �ƻs�W�r
        newnode->score = data[i][1];
        newnode->next = NULL;
        ptr->next = newnode; // �N�e�@�Ӹ`�I���V�s�`�I
        ptr = newnode;
    }
    newnode->next = head; // �Φ�������C

    while (1) {
        printf("\n�п�J�n�R�������u�s��, �n�������J�L�{, �п�J-1: ");
        scanf("%d", &position);
        if (position == -1) {
            break; // ���_�j��
        } else {
            ptr = findnode(head, position);
            if (ptr == NULL) {
                printf("��C���S�o�Ӹ`�I�C\n");
                break;
            } else {
                head = deletenode(head, ptr);
                printf("�w�R�����u �s��: %d �m�W: %s �~��: %d\n", ptr->num, ptr->name, ptr->score);
            }
        }
    }

    // ��ܳѾl���u���
    printf("\n���u�s��\t�m�W\t�~��\n");
    printf("--------------------------\n");
    ptr = head;
    do {
        printf("%4d\t%-10s\t%5d\n", ptr->num, ptr->name, ptr->score);
        ptr = ptr->next;
    } while (ptr != head); // �M��������C

    system("pause");
    return 0;
}
