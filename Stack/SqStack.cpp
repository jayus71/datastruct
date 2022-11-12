//
// Created by Jayus on 2022/10/10.
//

#include "SqStack.h"

void InitStack(SqStack &s) {
    s.top = 0;
    s.size = 0;
}

bool IsStackEmpty(SqStack s) {
    return s.top == 0;
}

bool IsStackFull(SqStack s) {
    return s.size == MAXSIZE;
}

bool Push(SqStack &sqStack, ElemType x) {
    if (IsStackFull(sqStack))
        return false;
    sqStack.data[sqStack.top] = x;
    sqStack.top++;
    return true;
}

bool Pop(SqStack &sqStack, ElemType &x) {
    if (IsStackEmpty(sqStack))
        return false;
    sqStack.top--;
    x = sqStack.data[sqStack.top];
    return true;
}