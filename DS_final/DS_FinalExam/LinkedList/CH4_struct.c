#include <stdio.h>
#include <ctype.h> // 引入字元測試與轉換函數標頭檔

struct student {
    int id;
    char name[10];
};

void new_student(struct student *new_one) {
    new_one->id = 1000 + new_one->id;
    for(int i = 0; new_one->name[i] != '\0'; i++) {
        new_one->name[i] = toupper(new_one->name[i]);
    }
    printf("新學生id: %d\n", new_one->id); // 把new_one的值印出來
    printf("新學生姓名: %s\n", new_one->name); // 把new_one的值印出來
}

int main(void) {
    struct student john = {291, "john"};
    new_student(&john);
    printf("\n");
    printf("學號：%d\n", john.id); // 把john的值印出來
    printf("姓名：%s\n", john.name); // 把john的值印出來
    return 0;
}
