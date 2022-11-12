//
// Created by Jayus on 2022/11/6.
//

#ifndef DATASTRUCT_SORT_H
#define DATASTRUCT_SORT_H

#include "../base.h"
#include "../list/LinkList.h"

void InsertSort(ElemType A[], int n);

void ShellSort(ElemType A[], int n);

int Partition(ElemType A[], int low, int high);

void QuickSort(ElemType A[], int low, int high);

int Partition_Random(ElemType A[], int low, int high);

void HeapAdjust(ElemType A[], int key, int len);

void BuildMaxHeap(ElemType A[], int len);

void HeapSort(ElemType A[], int len);

void Merge(ElemType A[], int low, int mid, int high);

void MergeSort(ElemType A[], int low, int high);

void doubleBubbleSort(ElemType A[], int n);

bool sortByOdd(ElemType A[], int n);

int FindKthElem(ElemType A[], int low, int high, int k);

void DutchFlag(ElemType array[], int n);

int SumPartition(ElemType A[], int n);

LinkList LinkedSelectSort_Swap(LinkList L);

void LinkedSelectSort_Insert(LinkList &L);

bool IsMinHeap(ElemType A[], int len);

void Sort_MN(ElemType A[], int m, int n);

#endif //DATASTRUCT_SORT_H

