//
// Created by Jayus on 2022/10/10.
//

#ifndef DATASTRUCT_SQQUEUE_H
#define DATASTRUCT_SQQUEUE_H

#include "../base.h"
#include "../Tree/BiTree.h"

typedef struct {
    ELemType data[MAXSIZE];
    int rear, front;
} SeqQueue;

void InitQueue(SeqQueue Q);

bool IsQueueEmpty(SeqQueue Q);

bool IsQueueFull(SeqQueue Q);

bool EnQueue(SeqQueue &Q, ELemType x);

bool DeQueue(SeqQueue &Q, ELemType &x);

bool EnQueue(SeqQueue &Q, BiTree x);

bool DeQueue(SeqQueue &Q, BiTree &x);

#endif //DATASTRUCT_SQQUEUE_H
