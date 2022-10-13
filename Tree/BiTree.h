//
// Created by Jayus on 2022/10/10.
//

#ifndef DATASTRUCT_BITREE_H
#define DATASTRUCT_BITREE_H

#include "../base.h"

typedef struct BiNode {
    ELemType data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

typedef struct {
    BiTree t;
    int tag;
}TreeStack;
BiTree PreInCreat(char A[], char B[], int l1, int h1, int l2, int h2);
ELemType FINDK(BiTree P, int k);
int DeleteTree(BiTree &T);
int SearchNodesByElem(BiTree T, ELemType x);
#endif //DATASTRUCT_BITREE_H
