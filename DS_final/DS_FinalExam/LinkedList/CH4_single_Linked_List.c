#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    char name[20];
    int Math;
    int Eng;
    char no[10];
    struct student *next;
} s_data;

int main() {
    int select, student_no = 0;
    float Msum = 0, Esum = 0;
    s_data *ptr; /* �s������ */
    s_data *head; /* ��C�}�Y���� */
    s_data *new_data; /* �s�W�����Ҧb��m���� */

    head = (s_data*)malloc(sizeof(s_data)); /* �إߦ�C�� */
    head->next = NULL;
    ptr = head;

    do {
        printf("(1)�s�W (2)���} => ");
        scanf("%d", &select);
        if (select != 2) {
            printf("�п�J �m�W �Ǹ� �ƾǦ��Z �^�妨�Z: ");
            new_data = (s_data*)malloc(sizeof(s_data)); /* �s�W�U�@���� */
            scanf("%s %s %d %d", new_data->name, new_data->no, &new_data->Math, &new_data->Eng);
            ptr->next = new_data; /* �s�����г]�w���s�����Ҧb��m */
            new_data->next = NULL; /* �U�@������next���]�w��NULL */
            ptr = ptr->next;
            student_no++;
        }
    } while (select != 2);

    ptr = head->next;
    putchar('\n');
    while (ptr != NULL) {
        printf("�m�W: %s �Ǹ�: %s �ƾǦ��Z: %d �^�妨�Z: %d\n", ptr->name, ptr->no, ptr->Math, ptr->Eng);
        Msum += ptr->Math;
        Esum += ptr->Eng;
        ptr = ptr->next; /* �Nptr�����U�@���� */
    }

    printf("\n����C�ǥͼƾǥ������Z: %.2f �^�奭�����Z: %.2f\n", Msum / student_no, Esum / student_no);
    system("pause");
    return 0;
}
