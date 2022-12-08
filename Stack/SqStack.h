//
// Created by Jayus on 2022/10/10.
//

#ifndef DATASTRUCT_SQSTACK_H
#define DATASTRUCT_SQSTACK_H
#include "../base.h"
#include "../Tree/BiTree.h"

typedef struct {
    ElemType data[MAXSIZE];
    int top;
    int size;
} SqStack;

void InitStack(SqStack &s);


bool IsStackEmpty(SqStack s);

bool IsStackFull(SqStack s);

bool Push(SqStack &s, ElemType x);

bool Pop(SqStack &s, ElemType &x);

bool GetTop(SqStack s, ElemType &x);

//----------------------------------------------
bool Push(SqStack &s, BiTree x);

bool Pop(SqStack &s, BiTree &x);

bool GetTop(SqStack s, BiTree &x);

bool Push(TreeStack &s, BiTree x);

bool Pop(TreeStack &s, BiTree &x);

bool GetTop(TreeStack s, BiTree &x);

bool IsStackEmpty(TreeStack s);

void InitStack(TreeStack &s);

#endif //DATASTRUCT_SQSTACK_H
