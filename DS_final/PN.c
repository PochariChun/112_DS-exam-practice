#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 函数：将车牌转换为数值以便排序。
int license_plate_value(char *plate)
{
    int value = 0, i;
    for (i = 0; i < 3; i++)
    {
        char char_value = plate[i];
        if ('A' <= char_value && char_value <= 'Z')
        {
            // 如果字符是大写字母
            value = value * 52 + char_value - 'A';
        }
        else
        {
            // 如果字符是小写字母
            value = value * 52 + char_value - 'a' + 26;
        }
    }
    return value;
}

// 函数：计算排序车牌所需的最少交换次数。
int count_swaps(char **plates, int num_plates)
{
    int i, j, count = 0;
    for (i = 0; i < num_plates - 1; i++)
    {
        for (j = i + 1; j < num_plates; j++)
        {
            // 比较两个车牌，如果不符合排序规则，则计数
            if (license_plate_value(plates[i]) > license_plate_value(plates[j]))
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int num_plates, i;
    char **plates; // 使用指针数组来动态分配内存

    // 读取车牌数量
    scanf("%d", &num_plates);

    // 动态分配内存以存储车牌信息
    plates = (char **)malloc(num_plates * sizeof(char *));
    for (i = 0; i < num_plates; i++)
    {
        plates[i] = (char *)malloc(4 * sizeof(char)); // 每个车牌有3个字符加上一个结束符
        scanf("%s", plates[i]);
    }

    // 输出排序车牌所需的最少交换次数
    printf("%d\n", count_swaps(plates, num_plates));

    // 释放内存
    for (i = 0; i < num_plates; i++)
    {
        free(plates[i]);
    }
    free(plates);

    return 0;
}
