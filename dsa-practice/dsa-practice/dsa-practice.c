#define _CRT_SECURE_NO_WARNINGS

//   LeetCode 150.逆波兰表达式求值

#include<stdio.h>
#include <stdlib.h>
int evalRPN(char** tokens, int tokensSize) {
    // 创建顺序栈
    int arr[10000];
    // 栈顶
    int top = 0;
    int res;

    for (int i = 0; i < tokensSize; i++) {
        // 判断是否是运算符
        // 使用strcmp来比较两个字符串的内容是否一样
        if (strcmp(tokens[i], "+") == 0 || strcmp(tokens[i], "-") == 0 ||
            strcmp(tokens[i], "*") == 0 || strcmp(tokens[i], "/") == 0) {
            int a = arr[--top];
            int b = arr[--top];
            switch (tokens[i][0]) {
            case '+':
                res = a + b;
                break;
            case '-':
                res = b - a;
                break;
            case '*':
                res = a * b;
                break;
            case '/':
                res = b / a;
                break;
            }
            // 运算完之后，将新数据进行压栈
            arr[top++] = res;
        }
        else {
            // 如果是数字字符串的话，就直接将数据存到栈中
            // atoi将字符串转换成整数
            arr[top++] = atoi(tokens[i]);
        }
    }
    return arr[0];
}


#include<stdbool.h>
//   LeetCode 946.验证栈序列

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize) {
    //创建一个栈
    int stack[1000];
    int top = 0;
    int j = 0;
    for (int i = 0; i < pushedSize; i++)
    {
        stack[top] = pushed[i];
        top++;
        while (top > 0 && stack[top - 1] == popped[j])
        {
            top--;
            j++;
        }
    }
    return top == 0;
}