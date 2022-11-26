//
// Created by Jayus on 2022/10/1.
//

#ifndef DATASTRUCT_SEQLIST_H
#define DATASTRUCT_SEQLIST_H

#endif //DATASTRUCT_SEQLIST_H

#define InitSize 100 //初始长度

#include "../base.h"

/**
 * @brief 动态分配存储数组的定义
 * data：动态分配数组的指针
 * Maxsize：最大容量
 * length：当前长度
 */
typedef struct {
    int *data;
    int Maxsize, length;
} seqList;

bool InitList(seqList &L);
void increaseListSize(seqList &L, int increaseSize);
bool ListInsert(seqList &L, int i, int e);
bool ListDelete(seqList &L, int i, int &e);
int LocateElem(seqList &L, int e);
