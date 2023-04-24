#include <stdio.h>
#include <stdlib.h>

// 定义多项式的结构体
typedef struct PolyNode *Polynomial;
struct PolyNode
{
    int coef;        // 系数
    int expon;       // 指数
    Polynomial link; // 指向下一个节点的指针
};

// 创建一个新节点
Polynomial CreateNode(int coef, int expon)
{
    Polynomial p = (Polynomial)malloc(sizeof(struct PolyNode));
    p->coef = coef;
    p->expon = expon;
    p->link = NULL;
    return p;
}

// 插入一个节点
void InsertNode(Polynomial *p, int coef, int expon)
{
    Polynomial temp = *p;
    if (*p == NULL)
    {
        *p = CreateNode(coef, expon);
        return;
    }
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = CreateNode(coef, expon);
}

// 输出多项式
// 输出多项式
void PrintPoly(Polynomial p)
{
    if (p == NULL)
    {
        printf("0 0\n");
        return;
    }
    // 创建一个数组用于存储每个节点的指针
    Polynomial arr[1000];
    int i = 0;
    while (p != NULL)
    {
        arr[i++] = p;
        p = p->link;
    }
    // 对节点指针数组进行降序排序
    for (int j = 0; j < i - 1; j++)
    {
        for (int k = j + 1; k < i; k++)
        {
            if (arr[j]->expon < arr[k]->expon)
            {
                Polynomial temp = arr[j];
                arr[j] = arr[k];
                arr[k] = temp;
            }
        }
    }
    // 输出多项式
    for (int j = 0; j < i; j++)
    {
        printf("%dx^%d", arr[j]->coef, arr[j]->expon);
        if (j != i - 1)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

// 在程序结束前，需要释放所有动态分配的内存
int main()
{
    Polynomial p = NULL;
    InsertNode(&p, 3, 4);
    InsertNode(&p, 5, 5);
    InsertNode(&p, 2, 1);
    InsertNode(&p, 1, 0);
    PrintPoly(p);
    // 释放动态分配的内存
    while (p != NULL)
    {
        Polynomial temp = p;
        p = p->link;
        free(temp);
    }
    return 0;
}
