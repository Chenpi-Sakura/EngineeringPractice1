#include "array_list.h"
#include <stdio.h>

int main() {

    SqList La, Lb, Lc;
    La.length = 0;
    Lb.length = 0;
    Lc.length = 0;

    printf("这是基于数组实现。\n");

    printf("请输入 1 或 2 选择合并方式: 1.集合并运算 2.有序合并\n");
    int choice; scanf("%d", &choice);
    while (choice != 1 && choice != 2)
    {
        printf("非法输入！\n请输入 1 或 2 选择合并方式: 1.集合并运算 2.有序合并\n");
        scanf("%d", &choice);
    }
    if (choice == 2) printf("请确保输入数据本身非递减\n");

    printf("请输入 A 集合和 B 集合的大小: ");
    int n, m; scanf("%d %d", &n, &m);
    printf("请输入 A 集合内的元素: ");
    while (n--) 
    {
        ElemType e; scanf("%d", &e);
        ListInsert(&La, La.length + 1, e);
    }
    printf("请输入 B 集合内的元素: ");    while (m--) 
    {
        ElemType e; scanf("%d", &e);
        ListInsert(&Lb, Lb.length + 1, e);
    }
    SqList *current;
    if (choice == 1) 
    {
        Union(&La, Lb);
        current = &La;
    }
    else
    {
        MergeList(La, Lb, &Lc);
        current = &Lc;
    } 

    printf("合并后的集合为： ");
    for (int i = 1; i <= current->length; i++) 
    {
        ElemType e;
        GetElem(*current, i, &e);
        printf("%d ", e);
    }
    printf("\n");

    return 0;
}