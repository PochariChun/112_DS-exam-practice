#include <stdio.h>

int main() {
    int nums[17]; // 固定长度为17
    int count = 0;

    // 输入一串数字，格式如同 5 6 7 9 10 11 19 20 20 20 20 21 27 27 33 33 33 固定输出17个
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
      &nums[0], &nums[1], &nums[2], &nums[3], &nums[4], &nums[5], &nums[6], &nums[7],
      &nums[8], &nums[9], &nums[10], &nums[11], &nums[12], &nums[13], &nums[14], &nums[15], &nums[16]);
    int n = 17;
    // 使用冒泡排序对数字进行排序
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                // 交换两个元素的位置
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    // // 输出排序好的数字
    // for (int i = 0; i < 17; i++) {
    //     printf("%d ", nums[i]);
    // }

    // 将数字根据 0~8, 9~17, 18~26, 27~33 进行分组
    int groupCounts[4] = {0}; // 用于统计每个分组的数字数量

    for (int i = 0; i < 17; i++) {
        if (nums[i] >= 0 && nums[i] <= 8) {
            groupCounts[0]++;
        } else if (nums[i] >= 9 && nums[i] <= 17) {
            groupCounts[1]++;
        } else if (nums[i] >= 18 && nums[i] <= 26) {
            groupCounts[2]++;
        } else if (nums[i] >= 27 && nums[i] <= 33) {
            groupCounts[3]++;
        }
    }

    // 在4个分组中分别判断数字数量是否为3的倍数或3的倍數+2
    for (int i = 0; i < 4; i++) {
        if (groupCounts[i] % 3 != 0 && groupCounts[i] % 3 != 2) {
            printf("0");
            return 0;
        }
    }

    // 对4个分组逐一检查
    int cnt = 0;
    int two = 0;
    for (int i = 0; i < 4; i++) {
        int j = 0;
        while (j < groupCounts[i]) {
            int cnti = cnt + j;
            // printf("\ncnti = %d \n", cnti);
            // 同三
            if (nums[cnti] == nums[cnti + 1]){
                // printf("inside same 3\n");
                
                // 同三
                if (nums[cnti] == nums[cnti + 2]) {
                    j += 3; 
                }
                // 同二
                else{
                    if (two){
                        printf("0");
                        return 0;
                    }
                    else{
                        j += 2;
                        two++;
                    }

                }
            } 
            // 連三
            else if (nums[cnti] + 1 == nums[cnti + 1] ){
                // printf("inside con 3\n");
                // 連三
                if (nums[cnti] + 2 == nums[cnti + 2]) {
                    j += 3;
                } 
                // 連5
                else if (nums[cnti] + 2 == nums[cnti + 5]){
                    j += 6;
                } 
                // 連4
                else if (nums[cnti] + 2 == nums[cnti + 4]){
                    if (two){
                        printf("0");
                        return 0;
                    }
                    else{
                        j += 5;
                        two++;
                    }
                } 
                // 其他
                else {
                    printf("0");
                    return 0;
                }
            } 
            // 其他
            else {
                printf("0");
                return 0;
            }
        }
        cnt += groupCounts[i];
        // printf("\n cnt = %d \n", cnt);
    }
    // 若所有分组检查都通过就输出 1
    printf("1");
    return 0;
}
