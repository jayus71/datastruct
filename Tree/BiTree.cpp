//
// Created by Jayus on 2022/10/10.
//

#include "BiTree.h"
#include "../Queue/SqQueue.h"
#include "../Stack/SqStack.h"
BiTree PreInCreat(char A[], char B[], int l1, int h1, int l2, int h2) { //创建二叉树
    int i, llen, rlen;
    BiTree root;
    root = (BiNode *) malloc(sizeof(BiNode));
    root->data = A[l1];
    for (i = l2; B[i] != root->data; i++);
    llen = i - l2;
    rlen = h2 - i;
    if (llen)
        root->lchild = PreInCreat(A, B, l1 + 1, l1 + llen, l2, l2 + llen - 1);
    else
        root->lchild = nullptr;
    if (rlen)
        root->rchild = PreInCreat(A, B, h1 - rlen + 1, h1, h2 - rlen + 1, h2);
    else
        root->rchild = nullptr;
    return root;
}
int i = 0;
ELemType FINDK(BiTree P, int k) {
    ELemType ch;
    if (P == NULL) {
        //printf("NULL the times of return: %d\n", i);
        return '#';
    }
    i++;
    if (i == k)
        return P->data;
    ch = FINDK(P->lchild, 4); //以上即为前序遍历中visit()部分，下面是造前序部分
    if (ch != '#')              //当ch不再是#说明找到想要的数据了，但现在在本层的ch这，要把他传上去，现在是传递链的一环
        return ch;
    ch = FINDK(P->rchild, 4); //所找结点的父亲结点接受数据时要用到这条语句，如本题中的B结点
    return ch;
}

int DeleteTree(BiTree &T){
    if(T){
        DeleteTree(T->lchild);
        DeleteTree(T->rchild);
        free(T);
        return 1;
    }
    return 0;
}

int SearchNodesByElem(BiTree T, ELemType x){
    if (T){
        if(T->data == x){
            DeleteTree(T);
            return 1;
        }
        BiTree Q[MAXSIZE];
        BiTree p;
        int front,rear;
        front = rear = 0;
        Q[rear] = T;
        rear = (rear + 1)%MAXSIZE;
        while (front != rear){
            p = Q[front];
            front = (front+1)%MAXSIZE;
            if (p->lchild){
                if(p->lchild->data == x){
                    DeleteTree(p->lchild);
                    p->lchild = NULL;
                }else{
                    Q[rear] = p->lchild;
                    rear = rear+1%MAXSIZE;
                }
            }
            if (p->rchild){
                if(p->rchild->data == x){
                    DeleteTree(p->rchild);
                    p->rchild = NULL;
                }else{
                    Q[rear] = p->rchild;
                    rear = rear + 1%MAXSIZE;
                }
            }
        }
        return 1;
    } else{
        return 0;
    }
}

int PostOrderFindAncestors(BiTree T,ELemType x){
    if(T == NULL)
        return 0;
    TreeStack s[MAXSIZE];
    int top = 0;
    BiTree p = T;
    while (p || top != 0){
        while (p && p->data != x){
            s[top].t = p;
            s[top].tag = 0;
            top ++;
            p = p->lchild;
        }
        if(p && p->data == x){
            printf("该结点的所有祖先为：");
            for (int j = top; j < 0; --j) {
                printf("%c",s[j].t->data);
            }
            return 1;
        }
        while(top != 0 && s[top].tag == 1)
            top--;
        if (top!= 0){
            p = s[top].t->rchild;
            s[top].tag = 1;
        }
    }
    return 0;
}

/**
 * 找到p，q最近的共同祖先
 * @param T 树
 * @param p
 * @param q
 * @return 最近的公共祖先
 */
BiNode *ANCESTOR(BiTree T, BiNode *p, BiNode *q){
    TreeStack sp[MAXSIZE],sq[MAXSIZE];
    int topP = 0,topQ = 0;
    BiNode *temp = p;
    while (temp || topP != 0){
        if(temp){
            sp[topP].t = temp;
            sp[topP].tag = 0;
            temp = temp->lchild;
            topP++;
        }else{
            temp = sp[topP].t;
            if(temp->rchild && sp[topP].tag != 1){
                temp = temp->rchild;
            } else{
                temp = sp[--topP].t;
                if(p == temp)
                    break;
                temp = NULL;
            }
        }
    }

    temp = q;
    while (temp || topQ != 0){
        if(temp){
            sq[topQ].t = temp;
            sq[topQ].tag = 0;
            temp = temp->lchild;
            topQ++;
        }else{
            temp = sq[topQ].t;
            if(temp->rchild && sq[topQ].tag != 1){
                temp = temp->rchild;
            } else{
                temp = sq[--topQ].t;
                if(q == temp)
                    break;
                temp = NULL;
            }
        }
    }
    int top = topP>topQ?topQ:topP;
    if(top!= 0){
        for (int j = top; j > 0; --j) {
            if(sp[top].t == sq[top].t)
                return sp[top].t;
        }
    }
    return NULL;
}

