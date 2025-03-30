#include "array_list.h"

/**
 * @brief 获取数组线性表的长度
 *
 * @param L 数组线性表结构体变量。
 * @return Status 返回获取到的长度，即线性表中有效元素的个数。
 *
 * @pre 数组线性表 L 必须已经存在
 */
Status ListLength(SqList L) 
{
    return L.length;
}

/**
 * @brief 获取数组线性表中第 i 个位置的元素
 *
 * @param L 数组线性表结构体变量。
 * @param i 需要获取的元素位置，从 1 开始计数
 * @param e 指向储存到的元素指针
 * @return Status 返回操作结果状态:
 * - OK: 获取成功，元素的值已储存到 e 中
 * - ERROR: 获取失败 (位置 i 不合法)
 *
 * @pre 数组线性表 L 必须已经存在
 * @pre 1 <= i <= ListLength(L)
 */
Status GetElem(SqList L, int i, ElemType *e) 
{
    if (i < 1 || i > L.length) return ERROR;
    *e = L.data[i - 1];
    return OK;
}

/**
 * @brief 在数组线性表 L 中查找第一个与给定元素 e 相等的元素的位序。
 *
 * @param L 数组线性表结构体变量。
 * @param e 需要查找的目标元素
 * @param compare 指向判定函数的指针
 * 该函数接受两个 ElemType 类型的参数
 * 如果相等返回 TRUE, 不相等返回 FALSE
 * @return Status 返回找到的元素位置:
 * - 如果存在，返回L中第1个与e满足关系compare()的数据元素的位序。
 * - 如果不存在，则返回 0
 *
 * @pre 数组线性表 L 已存在
 */
Status LocateElem(SqList L, ElemType e, Status (*compare)(ElemType, ElemType)) {
    for (int i = 0; i < L.length; i++) {
        if (compare(L.data[i], e)) {
            return i + 1; // 返回位序，从1开始
        }
    }
    return 0; // 不存在返回0
}

/**
 * @brief 在数组线性表 L 中第 i 个位置之前插入新的数据元素 e，L 的长度加 1。
 *
 * @param L 指向数组线性表结构体变量的指针。
 * @param i 插入元素的位置，从 1 开始计数
 * @param e 被插入的元素
 * @return Status 返回操作结果状态:
 * - OK: 存在第 i 个位置，插入成功
 * - ERROR: 不存在第 i 个位置 (i 超出范围或表已满)
 *
 * @pre 数组线性表 L 必须已经存在，且分配了足够的存储空间
 * @pre 1 <= i <= ListLength(L) + 1
 */
Status ListInsert(SqList *L, int i, ElemType e) 
{
    if (L->length >= MAXSIZE || i < 1 || i > L->length + 1) return ERROR;

    for (int j = L->length; j >= i; j--)
    { // 从 i 位到 末 位的 数据，向后移动了一位
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e;
    L->length++;
    return OK;
}

/**
 * @brief 判断数组线性表是否为空
 *
 * @param L 数组线性表结构体变量。
 * @return Status 返回查询结果:
 * - TRUE: L 是空线性表
 * - FALSE: L 不是空线性表
 *
 * @pre 数组线性表 L 必须已经存在
 */
Status ListEmpty(SqList L) 
{
    if (L.length == 0) return TRUE;
    return FALSE;
}