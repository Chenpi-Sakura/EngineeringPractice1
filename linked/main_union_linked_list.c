#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    LinkList Ahead = (LNode *)malloc(sizeof(LNode));
    LinkList Bhead = (LNode *)malloc(sizeof(LNode));
    LinkList Chead = (LNode *)malloc(sizeof(LNode));
    // 此处建立的链表是带头链表 即头节点的 data 不存储任何有效值
    Ahead->next = NULL; Bhead->next = NULL; 
    LinkList Atail = Ahead, Btail = Bhead;
    printf("这是基于链表实现。\n");

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
        AppendList(&Atail, e);
        // 此处调用的 AppendList 原文档中未作要求，其实现原理与 ListInsert 一致， 此处是为了方便测试
    }
    printf("请输入 B 集合内的元素: ");
    while (m--)
    {
        ElemType e; scanf("%d", &e);
        AppendList(&Btail, e);
    }
    LinkList current;
    if (choice == 1) 
    {
        Union(Ahead, Bhead);
        current = Ahead->next;
    }
    else
    {
        MergeList(Ahead, Bhead, Chead);
        current = Chead->next;
    } 

    printf("合并后的集合为： ");
    while(current != NULL) 
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    
    return 0;
}
