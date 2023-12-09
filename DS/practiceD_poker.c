#include <stdio.h>
#include <stdlib.h>

// 堆栈结构体
typedef struct {
    int *items; // 存储堆栈元素的数组
    int top;    // 栈顶指针
    int size;   // 堆栈的最大容量
} Stack;

// 初始化堆栈
void initialize(Stack *stack, int size) {
    stack->items = (int *)malloc(size * sizeof(int));
    stack->top = -1;
    stack->size = size;
}

// 检查堆栈是否为空
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// 检查堆栈是否已满
int isFull(Stack *stack) {
    return stack->top == stack->size - 1;
}

// 将元素压入堆栈
void push(Stack *stack, int item) {
    if (isFull(stack)) {
        printf("No\n");
        exit(0); // 堆栈已满，无法排序，输出"No"并退出程序
    } else {
        stack->items[++stack->top] = item;
    }
}

// 从堆栈中弹出元素
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("No\n");
        exit(0); // 堆栈为空，无法排序，输出"No"并退出程序
    } else {
        return stack->items[stack->top--];
    }
}

int main() {
    int sequence[3];
    scanf("%d %d %d", &sequence[0], &sequence[1], &sequence[2]);

    Stack stack;
    initialize(&stack, 3);

    int current = 1; // 初始要出的牌
    int i = 0;
    int jug = 1;

    while (i < 3) {
        if (sequence[i] > current) {
            push(&stack, current);
            current++; 
        }
        else if (sequence[i] == current) {
            current++; // 更新要出的牌
            i++; // 移动到下一张牌
        } 
        else {
            if (!isEmpty(&stack)){
                int popped = pop(&stack);
                if (popped!= sequence[i]){
                    jug = 0;
                    printf("No\n"); // 堆栈中的牌与剩余的牌不匹配，输出"No"
                    break;
                }
                else {
                    i++; // 移动到下一张牌
                }
            }
            else{
                jug = 0;
                printf("No\n"); // 堆栈中的牌与剩余的牌不匹配，输出"No"
                break;
            }
        }
    }

    if (jug){
        printf("Yes\n");
    }

    return 0;
}
