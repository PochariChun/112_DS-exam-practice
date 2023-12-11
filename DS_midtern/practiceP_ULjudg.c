#include <stdio.h>

int main()
{
    int M;
    scanf("%d", &M);

    while (M > 0)
    {
        int is_upper_triangle = 1;
        int is_lower_triangle = 1;

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                int x;
                scanf("%d", &x);

                // 判断是否为上三角矩阵
                if (i > j && x != 0)
                {
                    is_upper_triangle = 0;
                }
                // 判断是否为下三角矩阵
                if (i < j && x != 0)
                {
                    is_lower_triangle = 0;
                }
            }
        }

        if (is_upper_triangle && !is_lower_triangle)
        {
            printf("0\n");
        }
        else if (!is_upper_triangle && is_lower_triangle)
        {
            printf("1\n");
        }
        else
        {
            printf("-1\n");
        }

        M--;
    }

    return 0;
}
