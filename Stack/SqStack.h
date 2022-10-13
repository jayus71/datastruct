//
// Created by Jayus on 2022/10/10.
//

#ifndef DATASTRUCT_SQSTACK_H
#define DATASTRUCT_SQSTACK_H
#include "../base.h"
#include "../Tree/BiTree.h"
typedef struct {
    ELemType data[MAXSIZE];
    int top;
    int size;
}SqStack;
void InitStack(SqStack &s);
bool IsStackEmpty(SqStack s);
bool IsStackFull(SqStack s);
bool Push(SqStack &s,ELemType x);
bool Pop(SqStack &s, ELemType &x);
bool GetTop(SqStack s, ELemType &x);
//----------------------------------------------
bool Push(SqStack &s,BiTree x);
bool Pop(SqStack &s, BiTree &x);
bool GetTop(SqStack s, BiTree &x);
#endif //DATASTRUCT_SQSTACK_H
