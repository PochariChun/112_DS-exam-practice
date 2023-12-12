#include <stdio.h>
#include <stdlib.h>

typedef struct student { // �w�q�ǥ͵��c
    char name[20];      // �ǥͩm�W
    int Math;           // �ƾǦ��Z
    int Eng;            // �^�妨�Z
    char no[10];        // �Ǹ�
    struct student *rlink; // ���V�U�@�Ӿǥͪ�����
    struct student *llink; // ���V�W�@�Ӿǥͪ�����
} s_data;

int main() {
    int select;           // ����ܼ�
    s_data *head;         // ��C�}�Y����
    s_data *ptr;          // �s������

    // ��l���Y�`�I
    head = (s_data*) malloc(sizeof(s_data)); // �ʺA���t�O���鵹�Y�`�I
    head->llink = NULL;   // ��l�ƥ�����
    head->rlink = NULL;   // ��l�ƥk����
    ptr = head;           // �]�w�s�����Ь��Y�`�I

    do {
        printf("(1)�s�W (2)���} => "); // ��ܿﶵ
        scanf("%d", &select);          // Ū���ϥΪ̿��

        if (select != 2) {
            printf("�п�J �m�W �Ǹ� �ƾǦ��Z �^�妨�Z: "); // ���ܿ�J�H��
            s_data *new_data = (s_data*) malloc(sizeof(s_data)); // ���s�ǥͤ��t�O����

            // Ū���ǥͫH��
            scanf("%s %s %d %d", new_data->name, new_data->no, &new_data->Math, &new_data->Eng);

            // ���J�s�`�I���C��
            ptr->rlink = new_data; // �]�w��e�`�I���k���Ы��V�s�`�I
            new_data->rlink = NULL; // �s�`�I���k���г]��NULL
            new_data->llink = ptr;  // �s�`�I�������Ы��V�e�@�`�I
            ptr = new_data;         // ����ptr��s�`�I
        }
    } while (select != 2);

    // ��X�ǥͫH��
    ptr = head->rlink; // �]�wptr�q�Y�`�I���k���ж}�l
    putchar('\n');
    while (ptr != NULL) {
        printf("�m�W: %s �Ǹ�: %s �ƾǦ��Z: %d �^�妨�Z: %d\n", ptr->name, ptr->no, ptr->Math, ptr->Eng);
        ptr = ptr->rlink; // ���ʨ�U�@�Ӹ`�I
    }

    // �����{��
    system("pause"); // �bWindows���ҤU�Ȱ��{��
    return 0;
}
