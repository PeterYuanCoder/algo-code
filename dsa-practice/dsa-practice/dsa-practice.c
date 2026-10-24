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



//   LeetCode 622.设计循环队列



//使用牺牲一个位置的方法（重点）
typedef struct {
    int front;//对头
    int rear;//队尾
    int* arr;  //执行空间的数组
    int capacity;//空间大小 
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    //申请空间来存放结构体
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->arr = (int*)malloc(sizeof(int) * (k + 1));
    //只开辟了空间但是没有入队，所以都是指向0
    obj->front = 0;
    obj->rear = 0;
    obj->capacity = k + 1;
    return obj;
}

//判断当前队列是否是空
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == obj->rear;
}

//判断当前队列是否满了
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->rear + 1) % obj->capacity == obj->front;
}

//入队
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }
    obj->arr[obj->rear] = value;
    //取模操作    3%4=3
    obj->rear = (obj->rear + 1) % obj->capacity;  //判断是否走到队尾
    return true;
}

//出队
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }
    obj->front = (obj->front + 1) % obj->capacity;
    return true;
}

//获取队首元素
int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->arr[obj->front];
}

//获取队尾元素
int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->arr[(obj->rear - 1 + obj->capacity) % obj->capacity];
}


//销毁队列
void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
}





//   LeetCode 98.验证二叉搜索树



 //Definition for a binary tree node.
 struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };

 //这种二叉数中序遍历是严格递增的

 //prev保存前一个结点
struct TreeNode* prev = NULL;

bool _isValidBST(struct TreeNode* root) {
    if (root == NULL)
    {
        return true;
    }
    //左子树
    if (_isValidBST(root->left) == false)
    {
        return false;
    }
    //验证根
    if (prev != NULL && prev->val >= root->val)
    {
        return false;
    }
    prev = root;
    //右子树
    if (_isValidBST(root->right) == false)
    {
        return false;
    }
    return true;

}

bool isValidBST(struct TreeNode* root) {
    prev = NULL;//确保全局变量
    return _isValidBST(root);
}




//   LeetCode 104.二叉树的最大深度



 //Definition for a binary tree node.
 struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
 };


int maxDepth(struct TreeNode* root) {
    if (root == NULL)
    {
        return 0;
    }
    return fmax(maxDepth(root->left), maxDepth(root->right)) + 1;
}



//   LeetCode 606.根据二叉树创建字符串




 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

int i = 0;
char arr[100000];

void _tree2str(struct TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    //将数字转换成对应的数字字符并放到数组中
    char buff[20];
    sprintf(buff, "%d", root->val);
    strcpy(arr + i, buff);   //将这个临时数组放到总数组中
    i += strlen(buff);    //将下标移到后面
    if (root->left || root->right)
    {
        arr[i] = '(';
        i++;
        _tree2str(root->left);
        arr[i] = ')';
        i++;
    }
    if (root->right)
    {
        arr[i] = '(';
        i++;
        _tree2str(root->right);
        arr[i] = ')';
        i++;
    }

}
char* tree2str(struct TreeNode* root) {
    i = 0;
    _tree2str(root);
    arr[i] = '\0';
    return arr;
}



//   LeetCode 100.相同的树

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    //两个都为空
    if (p == NULL && q == NULL)
    {
        return true;
    }
    //其中一个为空
    if (p == NULL || q == NULL)
    {
        return false;
    }
    //两个都不为空
    if (p->val != q->val)
    {
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
