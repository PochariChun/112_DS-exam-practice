#include <stdio.h>
#include <stdlib.h>

struct student { // �w�q�ǥ͵��c
    char name[20]; // �ǥͩm�W
    char no[10]; // �ǥͽs��
    struct student *next; // ���V�U�@�Ӿǥͪ����w
};

typedef struct student s_data; // �Nstruct student���s�w�q��s_data

int main() {
    s_data *head; // ��C�}�Y����
    s_data *ptr; // �s������
    s_data *new_data; // �s�W�����Ҧb��m����
    int select; // �Τ���

    head = (s_data*)malloc(sizeof(s_data)); // �ʺA���t�O���鵹��C������
    ptr = head; // �]�w�s�����Ь���C��
    ptr->next = NULL; // �ثe�L�U�@�Ӥ���

    do {
        printf("(1)�s�W (2)���}=> ");
        scanf("%d", &select); // Ū���Τ���
        if (select != 2) {
            printf("�п�J �m�W �Ǹ�: ");
            new_data = (s_data*)malloc(sizeof(s_data)); // ���s�������t�O����
            scanf("%s %s", new_data->name, new_data->no); // Ū���ǥ͸��
            ptr->next = new_data; // �s�������
            new_data->next = NULL; // �s�������U�@�ӫ��w�]��NULL
            ptr = new_data; // ��s�s������
        }
    } while (select != 2);

    ptr->next = head; // �N�̫�@�Ӹ`�I����������V��C��

    // �H�U�N�X�Ω󥴦L���������
    ptr = head->next; // �q�Ĥ@�Ӧ��Ĥ����}�l
    while (ptr != head) { // �M������^���C��
        printf("�m�W: %s, �Ǹ�: %s\n", ptr->name, ptr->no); // ���L�ǥ͸��
        s_data *temp = ptr; // �Ȧs��e����
        ptr = ptr->next; // ���ʨ�U�@�Ӥ���
        free(temp); // �����e�����O����
    }
    free(head); // �����C�������O����

    return 0;
}
