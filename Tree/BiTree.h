//
// Created by Jayus on 2022/10/10.
//

#ifndef DATASTRUCT_BITREE_H
#define DATASTRUCT_BITREE_H

#include "../base.h"

typedef struct BiNode {
    ElemType data;
    int count; // 该子树结点总数
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

typedef struct {
    BiTree t;
    int tag;
} TreeStack;

BiTree PreInCreat(char A[], char B[], int l1, int h1, int l2, int h2);

ElemType FINDK(BiTree P, int k);

int DeleteTree(BiTree &T);

int SearchNodesByElem(BiTree T, ElemType x);

int WidthOfBiTree(BiTree T);

int levelOrder_Depth(BiTree T);

void IsBalanceBst(BiTree T, int &BstTag, int &h);
#endif //DATASTRUCT_BITREE_H
