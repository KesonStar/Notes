#include <stdio.h>
#include <stdlib.h>

// �������ʽ�Ľṹ��
typedef struct PolyNode *Polynomial;
struct PolyNode
{
    int coef;        // ϵ��
    int expon;       // ָ��
    Polynomial link; // ָ����һ���ڵ��ָ��
};

// ����һ���½ڵ�
Polynomial CreateNode(int coef, int expon)
{
    Polynomial p = (Polynomial)malloc(sizeof(struct PolyNode));
    p->coef = coef;
    p->expon = expon;
    p->link = NULL;
    return p;
}

// ����һ���ڵ�
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

// �������ʽ
// �������ʽ
void PrintPoly(Polynomial p)
{
    if (p == NULL)
    {
        printf("0 0\n");
        return;
    }
    // ����һ���������ڴ洢ÿ���ڵ��ָ��
    Polynomial arr[1000];
    int i = 0;
    while (p != NULL)
    {
        arr[i++] = p;
        p = p->link;
    }
    // �Խڵ�ָ��������н�������
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
    // �������ʽ
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

// �ڳ������ǰ����Ҫ�ͷ����ж�̬������ڴ�
int main()
{
    Polynomial p = NULL;
    InsertNode(&p, 3, 4);
    InsertNode(&p, 5, 5);
    InsertNode(&p, 2, 1);
    InsertNode(&p, 1, 0);
    PrintPoly(p);
    // �ͷŶ�̬������ڴ�
    while (p != NULL)
    {
        Polynomial temp = p;
        p = p->link;
        free(temp);
    }
    return 0;
}
