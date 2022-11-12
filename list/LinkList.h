//
// Created by Jayus on 2022/11/11.
//

#ifndef DATASTRUCT_LINKLIST_H
#define DATASTRUCT_LINKLIST_H

#include "../base.h"

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList List_HeadInsert(LinkList &L);

LinkList List_TailInsert(LinkList &L);

LNode *GetElem(LinkList L, int i);

LNode *LocateElem(LinkList L, ElemType data);

bool InsertLinklist(LinkList L, ElemType data, int pos);

bool InsertNextNode(LNode *p, ElemType data);

bool InsertPriorNode(LNode *p, ElemType data);

bool DeleteLinkList(LinkList L, int pos, ElemType &data);

bool DeleteNode(LNode *p);

int GetLength(LinkList L);

#endif //DATASTRUCT_LINKLIST_H
