//
// Created by Jayus on 2022/10/1.
//

#include "listExercise.h"
#include "seqList.h"
#include <stdlib.h>
#include <cstdio>


int findmin(seqList &List, int &value) {
    int pos = 0;
    int temp = 0;
    if (List.length == 0) {
        printf("空");
        return -1;
    }
    for (int i = 0; i < List.length; ++i) {
        if (List.data[i] < List.data[pos])
            pos = i;
    }
    temp = List.data[pos];
    List.data[pos] = List.data[List.length - 1];
    return temp;
}

int listReverse(seqList &L) {
    for (int i = 0; i < L.length / 2; ++i) {
        int temp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
    return 0;
}

int delListByelm(seqList &L, ElemType x) {
    int record[10] = {0};
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == x)
            record[i] = 1;
    }
    for (int i = 0; i < L.length; ++i) {
        printf("%d", record[i]);
    }
    for (int i = 0; i < L.length; ++i) {
        if (L.data[L.length - 1] == x) {
            L.length--;
        }
        if (record[i] == 1) {
            L.data[i] = L.data[L.length - 1];
            L.length--;
        }
    }
    printf("\n\n\n");
}

int delListByelem_1(seqList &L, ElemType x) {
    int count = 0;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] != x) {
            L.data[count] = L.data[i];
            count++;
        }
    }
    L.length = count;
    return 0;
}

int delListByelm_2(seqList &L, ElemType x) {
    int count = 0;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == x)
            count++;
        else
            L.data[i - count] = L.data[i - count];
    }
    L.length = L.length - count;
}

/**
 * 删除有序顺序表中介于s和t之间的
 * @param L
 * @param s
 * @param t
 * @return
 */
int delByrange(seqList &L, ElemType s, ElemType t) {
    if (s >= t || L.length == 0)
        return -1;
    int i = 0, j = 0;

    for (i = 0; i < L.length && L.data[i] < s; ++i);
    if (i >= L.length)
        return -2;

    for (j = i; j < L.length && L.data[j] <= t; ++j);
    for (; j < L.length; ++i, ++j) {
        L.data[i] = L.data[j];
    }
    L.length = i;
    return 0;
}



//int main(){
//    seqList L;
//    InitList(L);
//    for (int i = 0; i < 10; ++i) {
//        ListInsert(L,i,i%2+1);
//    }
//    for (int i = 0; i < L.length; ++i) {
//        printf("%d",L.data[i]);
//    }
//    printf("\n\n\n");
//    delListByelm(L,2);
//    for (int i = 0; i < L.length; ++i) {
//        printf("%d",L.data[i]);
//    }
//}

#include "../Tree/BiTree.h"
using namespace std;
int i = 0;


//void FindK(BiTree P, int k)
//{
//    if (P != NULL)
//    {
//        i++;
//        if (i == 6)
//            cout << P->data; //以上即为前序遍历中visit()部分，下面是造前序部分
//        FindK(P->lchild, k);
//        FindK(P->rchild, k);
//    }
//}
int j = 0;
int j1 = 0;

char getData(BiTree T) {
    return T->data;
}

int preOrder(BiTree T) {
    if (T != NULL)
        printf("%c", T->data);
    else
        return 0;
    preOrder(T->lchild);
    preOrder(T->rchild);
}

void preOrder_1(BiTree T, int k, char &ch) {
    if (T == NULL) {
        printf("NULL the times of return: %d\n", j1);
        return;
    }
    if (T) {
        j1++;
        if (j1 == k) {
            printf("NOT NULL the times of return: %d\n", j1);
            ch = T->data;
            return;
        }
        preOrder_1(T->lchild, k, ch);
        preOrder_1(T->rchild, k, ch);
    }
}

char preOrderFind(BiTree T, int k) {
    char ch = '#';
    if (T == NULL) {
        printf("NULL the times of return: %d\n", j);
        return '#';
    }
    if (T) {
        j++;
        if (j == k) {
            printf("NOT NULL the times of return: %d\n", j);
            return T->data;
        }
    }
    ch = preOrderFind(T->lchild, k);
    if (ch != '#')
        return ch;
    ch = preOrderFind(T->rchild, k);
    return ch;
}

char wrFind(BiTree T,int k) {
    if(T){
        j++;
        if(j == k){
            return T->data;
        }
    }else{
        return '#';
    }
    wrFind(T->lchild,k);
    wrFind(T->rchild,k);
}
//char FINDK(BiTree P, int k) {
//    char ch;
//    if (P == NULL) {
//        //printf("NULL the times of return: %d\n", i);
//        return '#';
//    }
//    i++;
//    if (i == k)
//        return P->data;
//    ch = FINDK(P->lchild, 4); //以上即为前序遍历中visit()部分，下面是造前序部分
//    if (ch != '#')              //当ch不再是#说明找到想要的数据了，但现在在本层的ch这，要把他传上去，现在是传递链的一环
//        return ch;
//    ch = FINDK(P->rchild, 4); //所找结点的父亲结点接受数据时要用到这条语句，如本题中的B结点
//    return ch;
//}

int main() {
    BiTree T;
    char ch;
    bool flag = true;
    char A[7] = {'A', 'B', 'D', 'E', 'C', 'F', 'G'};
    char B[7] = {'D', 'B', 'E', 'A', 'F', 'C', 'G'};
    T = PreInCreat(A, B, 0, 6, 0, 6); //到此处均为创建二叉树
    //ch = FINDK(T, 4);
    //cout << "第四个结点数据是：" << ch << endl; //以K为4
    // FindK(T,4);
//    char ch1 = preOrderFind(T, 4);
//    char ch2;
//    preOrder_1(T, 4, ch2);
//    printf("%c\n", ch2);
//    printf("%c\n", ch1);
//    printf("%c\n", ch);
    //system("pause");
    //preOrder(T);
    printf("%c",wrFind(T,4));
    return 0;
}