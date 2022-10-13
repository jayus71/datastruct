#include <stdlib.h>
#include <stdio.h>

typedef int ElemType;

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode, *LinkList;


/**
 * @brief 头插法建立链表
 * 重要作用：链表逆置
 * 
 * @param L 链表指针L的引用
 * @return LinkList 链表头指针
 */
LinkList List_HeadInsert(LinkList &L)
{
    LNode *s;
    int x = 0;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    scanf("%d",&x);
    while (x!=9999)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d",&x);
    }
    return L;
}

/**
 * @brief 尾插法建立单链表
 * 
 * @param L 链表头指针
 * @return LinkList 返回链表的头指针
 */
LinkList List_TailInsert(LinkList &L)
{
    LNode *s = NULL;
    LNode *r = NULL; //r为表尾指针

    int x = 0;
    L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    r = L;
    scanf("%d",&x);
    while (x!=9999)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d",&x);
    }
    r->next = NULL;
    return L;
}

/**
 * 按序号查找结点
 * @param L 头指针
 * @param i 待查找序号
 * @return 查找结点指针
 */
LNode* GetElem(LinkList L, int i)
{
    int j = 1;
    LNode *p = L->next;
    if (i == 0)
        return L;
    if (i <= 1)
        return NULL;
    while (p&&j<i)
    {
        p = p->next;
        j++;
    }
    return p;
}
/**
 * 根据数据查找结点
 * @param L 头指针
 * @param data 待查找数据值
 * @return 符合要求的结点指针
 */
LNode *LocateElem(LinkList L, ElemType data)
{
    LNode * p = L->next;
    while (p&&p->data != data)
    {
        p = p->next;
    }
    return p;
}

/**
 * 按位序插入，向pos位置插入值为data的结点
 * @param L 链表头指针
 * @param data 待插入数据
 * @param pos 待插入位置
 * @return 是否插入成功
 */
bool InsertLinklist(LinkList L, ElemType data, int pos)
{
//   //不带头结点的插入
//    if(pos == 1)
//    {
//        LNode *temp = (LNode*)malloc(sizeof(LNode));
//        temp->next = L->next;
//        temp->data = data;
//        L = temp; //头指针指向新结点
//        return  true;
//    }
    LNode *p = GetElem(L,pos-1);
    //可以使用InsertNextNode代替下列代码
    if (p == NULL)
    {
        printf("位置不合法");
        return false;
    }
    LNode *s = (LNode*)malloc(sizeof(LNode));
    s->data = data;
    s->next = p->next;
    p->next = s;
    printf("插入成功");
    return true;
}

/**
 * 向指定结点之后插入数据
 * @param p 指定的结点指针
 * @param data 待插入数据
 * @return 插入是否成功
 */
bool InsertNextNode(LNode *p, ElemType data)
{
    if (p == NULL)
    {
        printf("所给结点为空");
        return false;
    }
    LNode *temp = (LNode*)malloc(sizeof(LNode));
    temp->data = data;
    temp->next = p->next;
    p->next = temp;
    printf("插入成功");
    return true;
}

/**
 * 在指定结点前插入结点
 * @param p 指定结点
 * @param data 待插入数据
 * @return 是否插入成功
 * 先后插数据，然后再交换两个结点的数据达到逻辑前插的效果
 */
bool InsertPriorNode(LNode *p, ElemType data)
{
    if (p == NULL)
    {
        printf("结点指针非法");
        return false;
    }
    LNode *temp = (LNode*)malloc(sizeof(LNode));
    temp->next = p->next;
    p->next = temp;
    temp->data = p->data;
    p->data = data;
    printf("插入成功");
    return true;
}

/**
 * 按位序删除结点并返回数据值
 * @param L 链表头结点
 * @param pos 待删除位置
 * @param data 删除结点的数据
 * @return 是否删除成功
 */
bool DeleteLinkList(LinkList L, int pos, ElemType &data)
{
    LNode *p = GetElem(L,pos-1); //找到删除位置的前驱节点
    if (p == NULL || p->next == NULL)
    {
        printf("位置不合法\n");
        return false;
    }

    LNode *q = p->next;
    p->next = q->next;
    data = q->data;
    free(q);
    return true;
}

/**
 * 删除指定结点，时间复杂度O(1)
 * 注：当该结点为最后一个结点是不能使用该方法，
 * 要从表头遍历找到该结点的前驱结点，并删除，时间复杂度：O(n)
 * @param p 待删除结点
 * @return 是否删除成功
 */
bool DeleteNode(LNode *p)
{
    if(p == NULL || p->next == NULL)
    {
        printf("待删除结点为空");
        return false;
    }
    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}

/**
 * 计算表长
 * @param L 链表头指针
 * @return 返回链表长度
 */
int  GetLength(LinkList L)
{
    int len = 0;
    LNode *p = L;
    while (p = p->next)
    {
        len++;
    }
    return len;
}
