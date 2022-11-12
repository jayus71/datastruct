//
// Created by Jayus on 2022/11/9.
//

#include "sort.h"


/**
 * 双向冒泡排序
 * @param A 待排序数组
 * @param n 数组长度
 */
void doubleBubbleSort(ElemType A[], int n) {
    bool flag = true;
    int low = 0, high = n - 1;
    while (low < high && flag) {
        flag = false;
        for (int j = low; j < high; ++j) {
            if (A[j + 1] < A[j]) {
                swap(A[j], A[j + 1]);
                flag = true;
            }
        }
        high--;
        for (int j = high; j > low; --j) {
            if (A[j - 1] > A[j]) {
                swap(A[j - 1], A[j]);
                flag = true;
            }
        }
        low++;
    }
}

/**
 * 根据元素奇偶排序，把所有奇数都移动到偶数前面
 * @param A 待处理数组
 * @param n 数组长度
 * @return 处理成功返回true,否则返回false
 */
bool sortByOdd(ElemType A[], int n) {
    if (n <= 0)
        return false;
    int low = 0, high = n - 1;
    while (low < high) {
        while (A[high] % 2 == 0 && low < high)
            high--;
        while (A[low] % 2 == 1 && low < high)
            low++;
        if (low < high)
            swap(A[low], A[high]);
        low++;
        high--;
    }
    return true;
}

/**
 * 随机挑选枢纽值
 * @param A 待排序数组
 * @param low 下限
 * @param high 上限
 * @return 成功则返回枢纽的最终位置
 */
int Partition_Random(ElemType A[], int low, int high) {
    if (low > high)
        return -1;
    int randIndex = low + rand() % (high - low + 1);
    swap(A[randIndex], A[low]);
    ElemType pivot = A[low];
    int i = low;
    for (int j = low + 1; j <= high; ++j) {
        if (A[j] < pivot)
            swap(A[i++], A[j]);
    }
    swap(A[i], A[low]);
    return i;
}

/**
 * 在表中查找从小到大第k个元素，基于快速排序的划分操作
 * 也可以直接先排序再找，或者利用小根堆
 * @param A 待排序数组
 * @param low 下界
 * @param high 上界
 * @param k 第k小的元素
 * @return 返回元素的值
 */
int FindKthElem(ElemType A[], int low, int high, int k) {
    //----------------------
    //划分开始
    ElemType pivot = A[low];
    int low_temp = low, high_temp = high;
    while (low < high) {
        while (low < high && A[high] >= pivot)
            high--;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    //划分结束
    //----------------------
    //上述代码即进行一次划分，把一个元素放到最终位置，并判断是否是所求位置
    if (low == k)
        return pivot;
    else if (low < k)    //在后一部分表中查找
        return FindKthElem(A, low + 1, high_temp, k);
    else                 //在前半部分表中查找
        return FindKthElem(A, low_temp, low - 1, k);

}

/**
 * 荷兰国旗问题，0 1 2代表红白蓝，通过一趟遍历把整个数组按红白蓝顺序排好
 * @param array 颜色数组
 * @param n 数组长度
 */
void DutchFlag(ElemType array[], int n) {
    int current = 0;
    //begin前的数据都是有序的
    int begin = 0, end = n - 1;
    while (current < end) {
        if (array[current] == 0) {
            swap(array[current], array[begin]);
            //current和begin要么同时增加，要么在情况二中current增加
            //也就是说begin前的都是current处理过的，begin不会指向红色（除了最开始）
            current++;
            begin++;
        } else if (array[current] == 1) {
            current++;
        } else {
            swap(array[current], array[end]);
            //在把蓝色和末尾交换后，current指针不移动，因为交换到current位置
            //的元素值未知，需要再处理一次
            end--;
        }
    }
}

/**
 * 找到一个划分，使得划分得到的两个子数组元素个数之差绝对值最小，子数组之和差的绝对值最大
 * @param A 待划分数组
 * @param n 数组元素个数
 * @return 两个子数组和之差
 */
int SumPartition(ElemType A[], int n) {
    int finalPos = (n / 2) - 1;
    int low = 0, high = n - 1;
    int low_temp = 0, high_temp = n - 1;
    int s1 = 0, s2 = 0;
    bool flag = true;
    ElemType pivot;
    while (flag) {
        //-----------------
        //进行一次划分
        pivot = A[low];
        while (low < high) {
            while (low < high && pivot <= A[high])
                high--;
            A[low] = A[high];
            while (low < high && pivot >= A[low])
                low++;
            A[high] = A[low];
        }
        A[low] = pivot;
        //-----------------
        //划分结束，确定是否满足条件需要结束
        if (low == finalPos) {
            flag = false;
            //更新high和low的值，以保证下次划分是在需要的子表中
        } else if (low < finalPos) {
            low_temp = ++low;
            high = high_temp;
        } else {
            high_temp = --high;
            low = low_temp;
        }
    }
    for (int i = 0; i < finalPos; ++i) {
        s1 += A[i];
    }
    for (int i = finalPos; i < n; ++i) {
        s2 += A[i];
    }
    return abs(s1 - s2);
}

/**
 * 对链表进行简单选择排序，有头结点
 * 交换表中数据，没有断链操作
 * @param L 链表头指针
 */
LinkList LinkedSelectSort_Swap(LinkList L) {
    LNode *p = L->next;
    for (; p != nullptr; p = p->next) {
        LNode *min = p, *p1 = p->next;
        while (p1 != nullptr) {
            if (min->data > p1->data) {
                min = p1;
            }
            p1 = p1->next;
        }
        if (min != p) {
            swap(min->data, p->data);
        }
    }
    return L;
}

/**
 * 将单链表L按照简单选择排序排成由小到大的有序序列
 * 有断链操作，不改变结点点数据
 * @param L 待排序链表（引用型）
 */
void LinkedSelectSort_Insert(LinkList &L) {
    //剩余链表头指针
    LNode *p = L->next;
    //max指向剩余链表的最大值，pre_max指向其前驱（若存在）
    LNode *max, *pre_max;
    LNode *p1; //工作指针
    LNode *pre; //工作指针前驱

    //断开结果链表的头结点指针和后续结点的链接
    L = nullptr;
    //p是原链表的头指针（此时原链表已经没有头结点）
    while (p != nullptr) {
        p1 = max = p;
        pre = pre_max = nullptr;
        //寻找剩余链表中最大值
        while (p1 != nullptr) {
            if (max->data < p1->data) {
                //更新最大值结点及其前驱
                pre_max = pre;
                max = p1;
            }
            pre = p1, p1 = p1->next;
        }
        //如果最大值在剩余链表头部（无前驱）
        if (max == p)
            p = p->next;
        else {
            //最大值在剩余链表内部，有前驱，故需要更新前驱的后继指针
            pre_max->next = max->next;
        }
        //更新结果链表
        max->next = L->next;
        L->next = max;
    }
}

/**
 * 判断顺序表是否是小根堆
 * @param A 待判断顺序表
 * @param len 待判断表长
 * @return true：是小根堆；false：不是小根堆
 */
bool IsMinHeap(ElemType A[], int len) {
    //有奇数个结点，均是双分支结点
    if (len % 2) {
        for (int i = len / 2; i > 0; i--) {
            if (A[2 * i] < A[i] || A[2 * i + 1] < A[i])
                return false;
        }
        //有偶数个结点，也即有一个单分支结点
    } else {
        if (A[len / 2] > A[len])
            return false;
        for (int i = len / 2 - 1; i > 0; i--) {
            if (A[2 * i] < A[i] || A[2 * i + 1] < A[i])
                return false;
        }
    }
    return true;
}

/**
 * 归并排序思想排序
 * @param A 待排序数组
 * @param m 第一个有序子序列上界
 * @param n 第二个有序子序列上界
 */
void Sort_MN(ElemType A[], int m, int n) {
    int i = 1, j = m + 1, k = 1;
    //Merge(A,1,m,m+n);
    auto *B = (ElemType *) malloc(sizeof(ElemType) * (m + n));
    for (int l = 1; l <= m + n; ++l) {
        B[l] = A[l];
    }
    while (i <= m && j <= m + n) {
        if (B[i] < B[j]) {
            A[k] = B[i++];
        } else {
            A[k] = B[j++];
        }
        k++;
    }
    while (i <= m)
        A[k++] = A[i++];
    while (j <= m + n)
        A[k++] = A[j++];
}

/**
 * 计数排序
 * @param A 原数组
 * @param len 长度
 * @return 排序后的数组
 */
ElemType *CountSort(ElemType A[], int len) {
    auto list = (ElemType *) malloc(len * sizeof(ElemType));
    int count = 0;
    for (int i = 0; i < len; ++i) {
        count = 0;
        //注意j应该从0开始，是在整个序列中的位置，前i个和之后的先后顺序未知
        for (int j = 0; j < len; ++j) {
            if (A[j] < A[i])
                count++;
        }
        list[count] = A[i];
    }
    return list;
}


/**
 * 在上述计数排序中，如果要求两两之间只能比较一次，
 * 则需要修改成如下代码
 * @param A
 * @param len
 * @return
 */
typedef struct countSort {
    ElemType data;
    int count;
} countSort;

countSort *CountSort(countSort A[], int len) {
    auto list = (countSort *) malloc(len * sizeof(countSort));
    for (int i = 0; i < len; ++i) {
        A[i].count = 0;
    }
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (A[i].count > A[j].count)
                A[i].count++;
            else {
                A[j].count++;
            }
        }
    }
    for (int i = 0; i < len; ++i) {
        list[A[i].count] = A[i];
    }
    return list;
}

//数据结构P360 04
/**
 * 题目中只需要将最后一个元素放到最终位置
 * 且要求比较次数，则只需以Kn为枢纽，进行一次快速排序
 * @param A 待排序数组
 * @param n 数组长度
 * @return 枢纽（Kn）最后所在位置
 */
int SetK_nByOrder(ElemType A[], int n) {
    int low = 0, high = n - 1;
    ElemType pivot;
    swap(A[low], A[high]);
    pivot = A[low];
    while (low < high) {
        while (low < high && A[high] >= pivot)
            high--;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}