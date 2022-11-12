//
// Created by Jayus on 2022/11/6.
//

#include "sort.h"

/**
 * 直接插入排序（递增）
 * 由第二个元素开始，依次插入前面的有序序列中\n
 * A[0]不用，作为哨兵
 * @param A 待排序数组
 * @param n 数组长度
 */
void InsertSort(ElemType A[], int n) {
    int i, j;
    for (i = 2; i <= n; ++i) {
        if (A[i] < A[i - 1]) {
            A[0] = A[i];
            for (j = i - 1; A[0] < A[j]; --j) {
                A[j + 1] = A[j];
            }
            A[j + 1] = A[0];
        }
    }
}

/**
 * 折半查找的改进版，先通过折半查找找到待插入位置
 * A[0]不用，作为哨兵
 * @param A 待排序数组
 * @param n 数组长度
 */
void BiInsertSort(ElemType A[], int n) {
    int i, j, low, high, mid;
    for (i = 2; i <= n; i++) {
        A[0] = A[i];
        low = 1;
        high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (A[mid] > A[0])
                high = mid - 1;
            else //待插入关键字等于mid时，仍把low右移，以便保证稳定性
                low = mid + 1;
        }
        for (j = i - 1; j > high; j--) {
            A[j + 1] = A[j];
        }
        A[high + 1] = A[0];
    }
}

/**
 * 希尔排序
 * @param A 待排序数组
 * @param n 数组长度
 */
void ShellSort(ElemType A[], int n) {
    int j;
    for (int dk = n / 2; dk >= 1; dk /= 2) {
        for (int i = dk + 1; i <= n; ++i) {
            if (A[i] < A[i - dk]) {
                A[0] = A[i];
                for (j = i - dk; j > 0 && A[0] < A[j]; j -= dk) {
                    A[j + dk] = A[j];
                }
                A[j + dk] = A[0];
            }
        }
    }
}

/**
 * 快速排序的一次划分，从low到high
 * @param A 待排序数组
 * @param low 下限
 * @param high 上限
 * @return 枢纽的最终位置
 */
int Partition(ElemType A[], int low, int high) {
    ElemType pivot = A[low];
    while (low < high) {
        while (low < high && pivot > A[high])
            high--;
        A[low] = A[high];
        while (low < high && pivot < A[low])
            low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

/**
 * 快速排序主算法
 * @param A 待排序数组
 * @param low 下限
 * @param high 上限
 */
void QuickSort(ElemType A[], int low, int high) {
    if (low < high) {
        int pivotPos = Partition(A, low, high);
        QuickSort(A, low, pivotPos - 1);
        QuickSort(A, pivotPos + 1, high);
    }
}

/**
 * 简单选择排序
 * @param A 待排序数组
 * @param n 数组长度
 */
void SelectSort(ElemType A[], int n) {
    int min = 0;
    for (int i = 0; i < n - 1; ++i) {
        min = i;
        for (int j = i + 1; j < n - 1; ++j) {
            if (A[j] < min)
                min = j;
        }
        if (min != i)
            swap(A[i], A[min]);
    }
}

/*
 * ---------------------
 * 在堆排序的程序中，默认A[0]位置闲置，以满足二叉树特性
 * 堆是一棵完全二叉树
 */

/**
 * 调整以key为根结点的树
 * @param A 待调整数组
 * @param key 被调整子树根结点
 * @param len 数组总长度
 */
void HeapAdjust(ElemType A[], int key, int len) {
    A[0] = A[key];
    int i;
    for (i = 2 * key; i <= len; i *= 2) {
        if (i < len && A[i] < A[i + 1]) //找到左右孩子中较大的一个结点
            i++;
        if (A[0] >= A[i])
            break;
        else {
            A[key] = A[i]; //如果较大的结点比父结点大，上移
            key = i;       //上移以后，有可能导致下方子树失去大根堆特征，继续调整下方子树
        }
    }
    A[i] = A[0];   //将被筛选结点放入最终位置
}

/**
 * 建堆主函数
 * @param A 待建堆数组
 * @param len 数组长度
 */
void BuildMaxHeap(ElemType A[], int len) {
    for (int i = len / 2; i < len; --i) { //从下至上，依次调整每一个非终端结点
        HeapAdjust(A, i, len);
    }
}

/**
 * 堆排序算法，通过该函数将原数组改造为从小到大的有序数组
 * @param A
 * @param len
 */
void HeapSort(ElemType A[], int len) {
    BuildMaxHeap(A, len);  //初始建堆
    for (int i = len; i > 1; --i) {
        swap(A[i], A[1]); //输出堆顶元素（交换堆顶和堆底元素，依次把最大值放到最后
        HeapAdjust(A, 1, i - 1);  //调整除已经输出结点之外的整棵子树
    }
}

/**
 * 将表A的前后两段相邻的有序表归并成一个有序表
 * @param A 待归并表
 * @param low 第一个有序表下界
 * @param mid 两个有序表分界点
 * @param high 第二个有序表上界
 */
void Merge(ElemType *A, int low, int mid, int high) {
    auto *B = (ElemType *) malloc((high - low + 1) * sizeof(ElemType));
    for (int i = low; i <= high; ++i) {
        B[i] = A[i];  // 复制到B表
    }
    int i = low, j = mid + 1;
    int k = low;
    while (i <= mid && j <= high) {
        if (B[i] <= B[j])  // 比较左右两段元素
            A[k] = B[i++];  // 将其较小的元素复制到A中
        else
            A[k] = B[j++];
        k++;
    }
    //  复制未处理完的某个子表，只有一个会执行
    while (i <= mid)
        A[k++] = B[i++];
    while (j <= high)
        A[k++] = B[j++];
}

/**
 * 归并排序主算法
 * @param A 待排序顺序表
 * @param low 下界
 * @param high 上界
 */
void MergeSort(ElemType A[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;  //划分为两个子表
        MergeSort(A, low, mid);  //对左侧序列进行归并排序
        MergeSort(A, mid + 1, high); // 对右侧序列进行归并排序
        Merge(A, low, mid, high);  // 将两个有序序列合并为一个有序序列
    }
}