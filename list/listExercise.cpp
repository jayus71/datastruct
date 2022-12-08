//
// Created by Jayus on 2022/10/1.
//

#include "LinkList.h"
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

/**
 * 找到链表中倒数第k个结点，有头结点
 * @param L 链表头指针
 * @param k 要寻找的倒数第k个
 * @return 找到则返回对应结点指针，否则为nullptr
 */
LNode *Find_k(LinkList L, int k) {
    if (L == nullptr)
        return nullptr;
    LNode *p, *q;
    int count = 0;
    p = q = L->next;
    while (p != nullptr) {
        if (count == k)
            q = q->next;
        else
            count++;
        p = p->next;
    }
    if (count == k)
        return q;
    else
        return nullptr;
}

/**
 * 递归删除链表中值为x的结点
 * @param L 待删除链表头指针，没有头结点
 * @param x 待删除数据
 */
void DeleByElem_recur(LinkList &L, ElemType x) {
    if (L == nullptr)
        return;
    else if (L->data == x) {
        LNode *p = L;
        L = L->next;
        free(p);
        DeleByElem_recur(L->next, x);
    } else
        DeleByElem_recur(L->next, x);
}

/**
 * 在无序单链表中删除值为x的结点
 * @param L 待处理单链表，有头结点
 * @param x 删除的值
 */
void DeleteLinkListByElem(LinkList L, ElemType x) {
    if (L == nullptr)
        return;
    LNode *pre, *p;  //前驱指针和工作指针
    LNode *q; //用于删除结点

    pre = L;
    p = L->next;
    while (p) {
        if (p->data == x) {
            pre->next = p->next;
            q = p;
            p = p->next;
            free(q);
            q = nullptr;
        } else {
            pre = p;
            p = p->next;
        }
    }
}

/**
 * 头插法建立新链表的方法删除，当值为x时删除该结点，否则加入“新链表”
 * @param L 待处理链表头指针，有头结点
 * @param x 待删除值
 */
void DeleteLinkListByElem_2(LinkList L, ElemType x) {
    if (L == nullptr)
        return;
    LNode *pre, *p;
    LNode *q;
    pre = L;
    p = L->next;
    pre->next = nullptr;

    while (p) {
        if (p->data == x) {
            q = p;
            p = p->next;
            free(q);
            q = nullptr;
        } else {
            pre->next = p;
            pre = p;
            p = p->next;
        }
    }
    pre->next = nullptr;
}

/**
 * a中连续的相等元素构成的子序列称为平台。
 * 找出 a 中最长平台的长度。
 * @param a 待处理数组
 * @param n 数组长度
 * @return 最长平台长度
 */
int getMaxLength(int a[], int n) {
    if (n == 0)
        return 0;
    int maxlen = 1, len = 1;
    int start = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[start])
            len++;
        else {
            if (maxlen < len)
                maxlen = len;
            start = i;
            len = 1;
        }
    }
    return maxlen;
}

/**
 * 删除线性表中值为x的元素
 * @param L 待处理线性表
 * @param x 待删除值
 */
void delByElem_seqLi(seqList &L, ElemType x) {
    int k = 0;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == x)
            k++;
        else {
            L.data[i - k] = L.data[i];
        }
    }
    L.length = L.length - k;
}

/**
 * 利用头插法对链表进行排序，先找到整个链表中最大的元素，以头插法插入新链表，
 * 直到原来的链表为空，由于最大的元素最先被插入，所以保证了正确性，时间复杂度O(n^2)
 * @param L 链表头指针（带头结点）
 */
void sortLinkedList_Head(LinkList &L) {
    LNode *p = L->next;
    LNode *q, *pre = L->next;
    LNode *max = q;
    L = nullptr;
    while (p) {
        q = p;
        // 寻找链表中最大结点
        while (q) {
            if (q->data > max->data)
                max = q;
            pre = q;
            q = q->next;
        }
        // 如果最开始的结点就是最大的结点，也即无需更新前驱结点的后继
        // 直接插入即可
        if (pre == p) {
            p = p->next;
            pre->next = L->next;
            L->next = pre;
            // 最大结点在原链表的内部，需要更新前驱
        } else {
            pre->next = max->next;
            max->next = L->next;
            L->next = max;
            p = p->next;
        }
    }
}

/**
 * 链表归并排序中的合并函数，将两个有序链表合并为一个有序链表
 * @param left 左半部分有序链表(已经切断)
 * @param right 右半部分有序链表
 * @return 合并后的有序链并
 */
LNode *mergeLinkedList(LinkList left, LinkList right) {
    auto head = (LNode *) malloc(sizeof(LNode));
    auto h = head;
    head->next = nullptr;
    // 归并过程
    while (left && right) {
        if (left->data < right->data) {
            h->next = left;
            left = left->next;
        } else {
            h->next = right;
            right = right->next;
        }
        h = h->next;
    }
    // 将剩余结点连接到尾部
    h->next = left == nullptr ? right : left;
    h = head->next;
    free(head);
    return h;
}

/**
 * 对链表进行归并排序
 * @param L 待排序链表
 * @return 排序后的链表头指针
 */
LNode *sortLinkedList(LinkList L) {
    if (L == nullptr || L->next == nullptr)
        return L;
    LNode *slow = L, *fast = L->next;
    LNode *rhead = nullptr;
    // 利用快慢指针找到链表的中间结点
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    rhead = slow->next;
    slow->next = nullptr;
    // slow到达中间结点，以slow划分链表，并断链
    auto left = sortLinkedList(L);
    auto right = sortLinkedList(rhead);
    // 合并链表
    return mergeLinkedList(left, right);
}








//-------------------------------------------------------------------//
//测试代码


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

//错误！
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