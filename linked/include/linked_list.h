#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

/** 
 * @brief 获取链表长度
 * 
 * @param L 指向链表头部的指针。
 * @return Status 返回获取到的长度,即链表中结点的个数（不包括头结点）。
 * 
 * @pre 链表 L 必须已经存在
*/
Status ListLength(LinkList L);

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
Status GetElem(LinkList L, int i, ElemType *e);

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
Status LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType));

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
Status ListInsert(LinkList L, int i, ElemType e);

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
Status ListEmpty(LinkList L);

/**
 * @brief 向链表后端插入数据（仅供测试）
 *
 * @param L 指向链表尾部的指针。
 * @param e 要插入的数据元素。
 * @return Status 返回操作结果状态:
 * - OK: 插入成功
 * - ERROR: 插入失败
 */
Status AppendList(LinkList *L, ElemType e);

/** 
 * @brief 实现两个集合的并运算
 * 
 * @param La 第一个链表
 * @param Lb 第二个链表
 * 
 * @pre La 存在
 * @pre Lb 存在
*/
void Union(LinkList La,LinkList Lb);

/** 
 * @brief 实现有序表合并算法
 * 
 * @param La 指向第一个链表的头部的指针
 * @param Lb 指向第二个链表的头部的指针
 * @param Lc 指向目标链表的头部的指针
 * 
 * @pre La 存在
 * @pre Lb 存在
 * @pre Lc 存在
*/
void MergeList(LinkList La,LinkList Lb, LinkList Lc);

#endif