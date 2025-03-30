#include "linked_list.h"
#include <stdlib.h>

/** 
 * @brief 获取链表长度
 * 
 * @param L 指向链表头部的指针。
 * @return Status 返回获取到的长度,即链表中结点的个数（不包括头结点）。
 * 
 * @pre 链表 L 必须已经存在
*/
Status ListLength(LinkList L)
{
    /*
    // 头节点储存链表长度
    if (L == NULL) return 0;
    else return L->data;
    */

    int length = 0;
    LinkList current = L;
    if (current == NULL) return 0;
    current = current->next;
    while (current != NULL)
    {
        length++;
        current = current->next;
    }
    return length;
}

/**
 * @brief 获取链表中第 i 个位置的元素
 * 
 * @param L 指向链表头部的指针。
 * @param i 需要获取的元素位置，从 1 开始计数
 * @param e 指向储存到的元素指针
 * @return Status 返回操作结果状态:
 * - OK: 获取成功，元素的值已储存到 e 中
 * - ERROR: 获取失败
 * 
 * @pre 链表 L 必须已经存在
 * @pre 1 <= i <= ListLength(L)
 */
Status GetElem(LinkList L, int i, ElemType *e)
{
    if (i < 1) return ERROR;
    
    LinkList current = L;
    int j = 0;

    while (current != NULL && j < i)
    {
        current = current->next;
        j++;
    }
    if (current == NULL || j < i) return ERROR;

    *e = current->data;
    return OK;
}

/**
 * @brief 在链表 L 中查找第一个与给定元素 e 相等的元素的位序。
 * 
 * @param L 指向链表头部的指针。
 * @param e 需要查找的目标元素
 * @param compare 指向判定函数的指针
 * 该函数接受两个 ElemType 类型的参数
 * 如果相等返回 TRUE, 不相等返回 FALSE
 * @return Status 返回找到的元素位置:
 * - 如果存在，返回L中第1个与e满足关系compare()的数据元素的位序。
 * - 如果不存在，则返回 0
 * 
 * @pre 链表 L 已存在
 */
Status LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType))
{
    LinkList current = L->next;
    int i = 1;
    while (current != NULL && !compare(e, current->data))
    {
        current = current->next;
        i++;
    }
    if (current == NULL) return 0;
    return i;
}

/**
 * @brief 在L中第i个位置之前插入新的数据元素e，L的长度加1。
 * 
 * @param L 指向链表头部的指针。
 * @param i 插入元素的位置
 * @param e 被插入的元素
 * @return Status 返回操作结果状态:
 * - OK: 存在第 i 个位置，插入成功
 * - ERROR: 不存在第 i 个位置，插入失败
 *
 * @pre 链表 L 已存在，1 <= i <= ListLength(L) + 1
 */
Status ListInsert(LinkList L, int i, ElemType e)
{
    LinkList current = L, last = L;
    int j = 0;
    while (last != NULL && j < i)
    {
        last = current;
        current = current->next;
        j++;
    }
    if (last == NULL) return ERROR;
    LNode *NewNode = (LNode *)malloc(sizeof(LNode));
    NewNode->data = e; NewNode->next = current;
    last->next = NewNode;
    return OK;
}

/**
 * @brief 判断链表是否为空
 * 
 * @param L 指向链表头部的指针。
 * @return Status 返回查询结果:
 * - TRUE: L 是空链表
 * - FALSE: L 不是空链表
 * 
 * @pre 链表 L 已存在
 */
Status ListEmpty(LinkList L)
{
    if (L == NULL || L->next == NULL) return TRUE;
    return FALSE;
}

/**
 * @brief 向链表后端插入数据（仅供测试）
 *
 * @param L 指向链表尾部的指针。
 * @param e 要插入的数据元素。
 * @return Status 返回操作结果状态:
 * - OK: 插入成功
 * - ERROR: 插入失败
 */
Status AppendList(LinkList *L, ElemType e)
{
    // 传入尾指针
    LNode *NewNode = (LNode *)malloc(sizeof(LNode));
    NewNode->data = e; NewNode->next = NULL;
    (*L)->next = NewNode;
    *L = NewNode;
    // 传入头指针
    // LinkList current = L;
    // LNode *NewNode = (LNode *)malloc(sizeof(LNode));
    // NewNode->data = e; NewNode->next = NULL;
    // while (current->next != NULL) current = current->next;
    // current->next = NewNode;
    // return OK;
}