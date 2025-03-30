#include "linked_list.h"

/** 
 * @brief 比较两个元素是否相等
 * 
 * @param e1 第一个元素
 * @param e2 第二个元素
 * @return Status 返回比较结果
 * - TRUE: 相等
 * - FALSE: 不相等
*/
Status compare(ElemType e1, ElemType e2)
{
    if (e1 == e2) return TRUE;
    return FALSE;
}

/** 
 * @brief 实现两个集合的并运算
 * 
 * @param La 指向第一个链表的头部的指针
 * @param Lb 指向第二个链表的头部的指针
 * 
 * @pre La 存在
 * @pre Lb 存在
*/
void Union(LinkList La,LinkList Lb) 
{   // 将所有在表Lb（代表B集合）中但不在La（代表A集合）中的数据元素插入到La中
    int La_len = ListLength(La); // 求表La的长度
    int Lb_len = ListLength(Lb);
    for(int i = 1; i <= Lb_len; i++)
    {
        int e; GetElem(Lb, i, &e); // 取表Lb中第i个数据元素赋给变量e
        if(!LocateElem(La, e, compare)) ListInsert(La, ++La_len, e);
    }
}

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
void MergeList(LinkList La,LinkList Lb, LinkList Lc) 
{ /* 已知表La和Lb中的数据元素按值非递减排列。 */
/* 归并La和Lb得到新的表Lc,Lc的数据元素也按值非递减排列 */
    int i = 1, j = 1, k = 0;
    int La_len = ListLength(La);
    int Lb_len = ListLength(Lb);
    int ai, bj;
    while (i <= La_len && j <= Lb_len)          
    { /* 表La和表Lb均非空 */
        GetElem(La, i, &ai);
        GetElem(Lb, j, &bj);
        if(ai <= bj)
        {
            ListInsert(Lc, ++k, ai);
            ++i;
        }
        else
        {
            ListInsert(Lc, ++k, bj);
            ++j;
        }
    }
    while(i <= La_len)                
    {/* 表La非空且表Lb空 */
        GetElem(La, i++, &ai);
        ListInsert(Lc, ++k, ai);
    }
    while(j <= Lb_len)                
    {/* 表Lb非空且表La空 */
        GetElem(Lb, j++, &bj);
        ListInsert(Lc, ++k, bj);
    }
}
