//
// Created by Jayus on 2022/7/20.
//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXSIZE 100
typedef int ElemType;
typedef struct DNode
{
    ElemType data;
    struct DNode *prior,*next;
}DNode, *DLinkList ;
/**
 * 在双链表中的指定结点后插入结点
 * @param p 将在p结点之后插入
 * @param s 待插入结点
 * @return 是否插入成功
 */
bool InsertNextDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL)
        return false;
    s->next = p->next;
    if (p->next != NULL)
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

/**
 * 删除p的后继结点
 * @param p 将删除p的后继结点（如果存在）
 * @return 是否删除成功
 */
bool DeleteDNode(DNode *p)
{
    if (p == NULL || p->next == NULL)
        return false;
    DNode *q = p->next;
    p->next = q->next;
    if (q->next != NULL)
        q->next->prior = p;
    free(q);
    return true;
}

//---------------------------
typedef struct
{
    ElemType data;
    int next;
}SNode,SLinkList[MAXSIZE];

/**
 * 找到在链表中逻辑位置为pos的结点的实际数组下标
 * @param L 静态链表--即数组指针
 * @param pos 逻辑位置
 * @return 实际数组下标
 */
int GetElem(SLinkList L, int pos)
{
    SNode temp = L[0];
    for (int i = 0; i < pos-1; ++i) {
        temp = L[L[i].next];
    }
    return temp.next;
}
/**
 * 向链表逻辑位置为pos的结点插入数据
 * @param L 静态链表--数组指针
 * @param data 待插入数据
 * @param pos 插入位置
 * @return
 */
bool InsertSLinkList(SLinkList L, ElemType data, int pos)
{
    int i = 0;
    for (i = 0; i < MAXSIZE; ++i) {
        if (L[i].next == -2)
            break;
    }
    if (i >= MAXSIZE)
        printf("内存不足\n");
    L[i].data = data;
    int prior = GetElem(L,pos-1);
    L[i].next = L[prior].next;
    L[prior].next = i;

}
