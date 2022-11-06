//
// Created by Jayus on 2022/11/6.
//

#include "sort.h"
#include "../base.h"

/**
 * 直接插入排序（递增）
 * 由第二个元素开始，依次插入前面的有序序列中\n
 * A[0]不用，作为哨兵
 * @param A 待排序数组
 * @param n 数组长度
 */
void InsertSort(ELemType A[], int n) {
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
void BiInsertSort(ELemType A[], int n) {
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
void ShellSort(ELemType A[], int n) {
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