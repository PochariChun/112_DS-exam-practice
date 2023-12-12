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
    s_data *ptr; /* 存取指標 */
    s_data *head; /* 串列開頭指標 */
    s_data *new_data; /* 新增元素所在位置指標 */

    head = (s_data*)malloc(sizeof(s_data)); /* 建立串列首 */
    head->next = NULL;
    ptr = head;

    do {
        printf("(1)新增 (2)離開 => ");
        scanf("%d", &select);
        if (select != 2) {
            printf("請輸入 姓名 學號 數學成績 英文成績: ");
            new_data = (s_data*)malloc(sizeof(s_data)); /* 新增下一元素 */
            scanf("%s %s %d %d", new_data->name, new_data->no, &new_data->Math, &new_data->Eng);
            ptr->next = new_data; /* 存取指標設定為新元素所在位置 */
            new_data->next = NULL; /* 下一元素的next先設定為NULL */
            ptr = ptr->next;
            student_no++;
        }
    } while (select != 2);

    ptr = head->next;
    putchar('\n');
    while (ptr != NULL) {
        printf("姓名: %s 學號: %s 數學成績: %d 英文成績: %d\n", ptr->name, ptr->no, ptr->Math, ptr->Eng);
        Msum += ptr->Math;
        Esum += ptr->Eng;
        ptr = ptr->next; /* 將ptr移往下一元素 */
    }

    printf("\n本串列學生數學平均成績: %.2f 英文平均成績: %.2f\n", Msum / student_no, Esum / student_no);
    system("pause");
    return 0;
}
