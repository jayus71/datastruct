//
// Created by Jayus on 2022/10/10.
//

#include "SqQueue.h"
void InitQueue(SeqQueue Q){
    Q.rear = Q.front = 0;
}
bool IsQueueEmpty(SeqQueue Q){
    return Q.front == Q.rear;
}
bool IsQueueFull(SeqQueue Q){
    return (Q.rear+1)%MAXSIZE == Q.front;
}

bool EnQueue(SeqQueue &Q, ElemType x) {
    if (IsQueueFull(Q))
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return true;
}

bool Dequeue(SeqQueue &Q, ElemType &x) {
    if (IsQueueEmpty(Q))
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return true;
}