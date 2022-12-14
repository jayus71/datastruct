//
// Created by Jayus on 2022/10/10.
//
//#include <string> //假如我把#include <string>放到#include <vector>之后，就会报错，错误原因未知

#include "BiTree.h"
#include "../Queue/SqQueue.h"
#include "../Stack/SqStack.h"
#include <string>

#include <vector>

//#include <vector>


using namespace std;

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
ElemType FINDK(BiTree P, int k) {
    ElemType ch;
    if (P == NULL) {
        //printf("NULL the times of return: %d\n", i);
        return '#';
    }
    i++;
    if (i == k)
        return P->data;
    ch = FINDK(P->lchild, k);
    if (ch != '#')
        return ch;
    ch = FINDK(P->rchild, k);
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

int SearchNodesByElem(BiTree T, ElemType x) {
    if (T) {
        if (T->data == x) {
            DeleteTree(T);
            return 1;
        }
        BiTree Q[MAXSIZE];
        BiTree p;
        int front, rear;
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

/**
 * 非递归后序遍历的应用，当遍历到某个结点p时，
 * 栈中的所有结点即为p的祖先
 * @param T 二叉树
 * @param x 待寻找结点数据
 * @return 是否成功
 */
int PostOrderFindAncestors(BiTree T, ElemType x) {
    if (T == NULL)
        return 0;
    TreeStack s[MAXSIZE];
    int top = 0;
    BiTree p = T;
    while (p || top != 0) {
        while (p && p->data != x) {
            s[top].t = p;
            s[top].tag = 0; // 访问了左子树
            top++;
            p = p->lchild;
        }
        if(p && p->data == x){
            printf("该结点的所有祖先为：");
            for (int j = 0; j < top; ++j) {
                printf("%c", s[j].t->data);
            }
            return 1;
        }
        while (top != 0 && s[top].tag == 1) //本题只需找到值为x的结点，所以右子树访问过的结点也即后序遍历完成，可以直接退栈
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
    int top = topP > topQ ? topQ : topP;
    if (top != 0) {
        for (int j = top; j > 0; --j) {
            if (sp[top].t == sq[top].t)
                return sp[top].t;
        }
    }
    return NULL;
}

/**
 * 利用层次遍历求高度
 * @param T 二叉树
 * @return 高度
 */
int levelOrder_Depth(BiTree T) {
    if (T == NULL)
        return 0;
    SeqQueue q;
    BiTree p = T;
    BiNode *last = T;
    int depth = 0;
    InitQueue(q);
    EnQueue(q, T);

    while (!IsQueueEmpty(q)) {
        DeQueue(q, p);
        //visit(p);
        if (!p->lchild) {
            EnQueue(q, p->lchild);
        }
        if (!p->rchild) {
            EnQueue(q, p->rchild);
        }
        if (p == last) {
            depth++;
            last = p->rchild;
        }
    }

    return depth;
}

int getStackSize(SqStack s) {
    return s.size;
}

/**
 * 利用非递归后序遍历求二叉树高度
 * @param T 二叉树
 * @return 二叉树高度
 */
int postOrderLeve(BiTree T) {
    if (T == NULL)
        return 0;
    SqStack s;
    BiNode *pre = NULL;
    BiTree p = T;
    int max = 1, depth;

    while (p || !IsStackEmpty(s)) {
        if (p) {
            Push(s, p);
            p = p->lchild;
        } else {
            GetTop(s, p);
            if (p->rchild && p->rchild != pre) {
                Push(s, p);
                p = p->rchild;
            } else {
                Pop(s, p);
                depth = getStackSize(s);
                if (depth > max)
                    max = depth;
                pre = p;
                p = NULL;
            }
        }
    }
    return max;
}

/**
 * 层次遍历求非空二叉树的宽度
 * @param T 二叉树的根结点
 * @return 二叉树宽度
 */
int WidthOfBiTree(BiTree T) {
    BiTree Q[MAXSIZE];
    int front = 0, rear = 0;
    BiNode *p = T;
    BiNode *last = p;  // 记录每一层遍历的最后一个结点
    int MaxWidth = 1, tempWidth = 0;

    if (!T) {
        printf("空树");
        return 0;
    }
    Q[rear] = T;
    rear = (rear + 1) % MAXSIZE;

    while (front != rear) {
        p = Q[front];
        front = (front + 1) % MAXSIZE;
        tempWidth++;

        // 当前结点就是本层最后一个结点，说明该层结点已经全部处理完毕
        if (p == last) {
            last = p->rchild;
            if (tempWidth > MaxWidth)
                MaxWidth = tempWidth;
            tempWidth = 0;
        }
        //左右子树入队
        if (p->lchild) {
            Q[rear] = p->lchild;
            rear = (rear + 1) % MAXSIZE;
        }
        if (p->rchild) {
            Q[rear] = p->rchild;
            rear = (rear + 1) % MAXSIZE;
        }
    }
    return MaxWidth;
}

/**
 * 层次遍历求宽度
 * 用len记录上层结点遍历完成时，即下一层结点全部进入队列
 * 此时的队列的长度即为下一层的宽度，比较得出最大宽度
 * @param T
 * @return
 */
int WidthOfBiTree_1(BiTree T) {
    BiTree Q[MAXSIZE];
    int front = 0, rear = 0;
    int width = 1; //最大宽度
    int level = 1;
    int max_Level = 1;//最大宽度层次
    BiNode *p = T;
    int len = 1; //上层队列长度

    Q[rear] = T;
    rear = (rear + 1) % MAXSIZE;
    while (rear != front) {
        p = Q[front];
        front = (front + 1) % MAXSIZE;
        len--;
        //左右子树入队
        if (p->lchild) {
            Q[rear] = p->lchild;
            rear = (rear + 1) % MAXSIZE;
        }
        if (p->rchild) {
            Q[rear] = p->rchild;
            rear = (rear + 1) % MAXSIZE;
        }

        //长度为0说明此时本层结点遍历完毕，
        //需要进入下层，而此时队列中元素个数即为下层元素个数
        if (len == 0) {
            len = (rear - front + MAXSIZE) % MAXSIZE;
            level++;
            if (len > width) {
                width = len;
                max_Level = level;
            }
        }
    }
    printf("最大宽度所在层次：%d", max_Level);
    return width;
}

/**
 * 判断给定二叉排序树是否为平衡二叉树
 * @param T 待判断二叉树
 * @param BstTag 引用型变量，是否为平衡二叉树，1：是，0：否
 * @param h 引用型变量，待判断树高度
 */
void IsBalanceBst(BiTree T, int &BstTag, int &h) {
    if (T == NULL) {
        BstTag = 1;
        h = 0;
        return;
    } else if (T->lchild == NULL && T->rchild == NULL) {
        BstTag = 1;
        h = 1;
        return;
    } else {
        int btl = 0, btr = 0, lh = 0, rh = 0;
        IsBalanceBst(T->lchild, btl, lh);
        IsBalanceBst(T->lchild, btr, rh);
        h = lh > rh ? lh : rh;
        if (abs(lh - rh) <= 2) {
            BstTag = btl && btr;
        } else
            BstTag = 0;
        return;
    }
}

/**
 * 返回二叉排序树中从小到大第k个结点
 * 在BiNode中增加了count，记录子树上的结点总个数
 * @param T 给定二叉排序树
 * @param k
 * @return
 */
BiNode *FindByOrder(BiTree T, int k) {
    //空树或顺序不合法
    if (T == nullptr || k < 1)
        return nullptr;
    //左子树为空
    if (T->lchild == nullptr) {
        if (k == 1)
            return T;
        else
            return FindByOrder(T->rchild, k - 1);
    } else {
        if (T->lchild->count == k - 1)
            return T;
            //左子树结点个数大于k-1，一定在左子树中
        else if (T->lchild->count > k - 1)
            return FindByOrder(T->lchild, k);
        else
            return FindByOrder(T->rchild, k - 1 - T->lchild->count);
    }
}

/**
 * 求根结点的两棵子树叶结点的最大距离
 * @param T 根结点
 * @param maxDistance 最大距离
 * @return 返回结点高度（空结点高度为-1），保证算出来是距离
 */
int distance(BiTree T, int &maxDistance) {
    if (!T) {
        return -1; // 如果是单纯求高度，空结点的高度应该设置为 1
    }
    int lDistance = 0, rDistance = 0;
    int lrDistance = 0;

    lDistance = distance(T->lchild, maxDistance) + 1; // 左子树高度加一
    rDistance = distance(T->rchild, maxDistance) + 1; // 右子树高度加一

    lrDistance = lDistance + rDistance; //叶结点的距离等于两个子树的高度和
    maxDistance = maxDistance > lrDistance ? maxDistance : lrDistance; // 更新最大距离
    return lDistance > rDistance ? lDistance : rDistance; // 返回本结点子树的高度
}
//-------------
//只有把queue移动到这里才不报错
//-------------
#include <queue>

/**
 * 使用c++自带的stl寻找二叉树的所有路径
 * @param root 二叉树根结点
 * @return 返回包含所有路径的向量
 */
vector<string> BiTreePath(BiTree root) {
    vector<string> paths;
    if (root == nullptr) {
        return paths;
    }
    queue<BiNode *> node_queue;
    queue<string> path_queue;

    node_queue.push(root);
    path_queue.push(to_string(root->data));

    //基于层次遍历
    while (!node_queue.empty()) {
        BiNode *node = node_queue.front();
        string path = path_queue.front();
        node_queue.pop();
        path_queue.pop();
        //到达叶结点，路径也到达终点，可以直接加入结果向量
        if (node->lchild == nullptr && node->rchild == nullptr) {
            paths.push_back(path);
        } else {
            //处理分支结点
            if (node->lchild) {
                node_queue.push(node->lchild);
                path_queue.push(path + "->" + to_string(node->lchild->data));
            }
            if (node->rchild) {
                node_queue.push((node->rchild));
                path_queue.push(path + "->" + to_string(node->rchild->data));
            }
        }
    }
    return paths;
}

/**
 * 非递归交换左右子树
 * @param root 二叉树根结点
 */
void swapTree(BiTree root) {
    if (root == nullptr)
        return;
    TreeStack s;
    BiNode *p, *temp;
    InitStack(s);
    Push(s, root);
    while (IsStackEmpty(s)) {
        Pop(s, p);
        if (p->lchild || p->rchild) {
            temp = p->lchild;
            p->lchild = p->rchild;
            p->rchild = p->lchild;
        }
        if (p->lchild)
            Push(s, p->lchild);
        if (p->rchild)
            Push(s, p->rchild);
    }
}

void BSTInsert(BiTree &T, ElemType x){
    if(T){
        if(T->data == x)
            return;
        else if (T->data > x)
        {
            return BSTInsert(T->lchild,x);
        }else if (T->data < x)
        {
            return BSTInsert(T->rchild,x);
        }
    }else{
        T = (BiNode*)malloc(sizeof(BiNode));
        T->lchild = T->rchild = nullptr;
        T->data = x;
        return;
    }
}