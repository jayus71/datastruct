#include <stdio.h>
#include <stdlib.h>
#include "seqList.h"



bool InitList(seqList &L)
{
    if (L.data = (int *)malloc(InitSize * sizeof(seqList)))
    {
        L.length = 0;
        return true;
    }
    return false;
}

/**
 * @brief 增加动态数组的长度
 *
 * @param L 动态数组引用
 * @param increaseSize 要增加的大小
 */
void increaseListSize(seqList &L, int increaseSize)
{
    int *p = L.data;
    L.data = (int *)malloc((L.length + increaseSize) * sizeof(seqList));
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i];
    }
    L.Maxsize = L.Maxsize + increaseSize;
    free(p);
}

/**
 * @brief 在顺序表第i个位置上插入元素e
 *
 * @param L 顺序表引用
 * @param i 插入位置
 * @param e 待插入元素
 * @return true 插入成功
 * @return false 因空间已满或位置非法插入失败
 */
bool ListInsert(seqList &L, int i, int e)
{
    if (i > L.length + 1 || i < 1)
    {
        return false;
    }
    else if (L.length >= L.Maxsize)
    {
        return false;
    }
    else
    {
        for (int j = L.length; j >= i; j--)
        {
            L.data[j] = L.data[j - 1];
        }
        L.data[i - 1] = e;
        L.length += 1;
        return true;
    }
}


/**
 * @brief 删除第i个位置的元素，并用e返回被删除元素
 * 
 * @param L 顺序表引用
 * @param i 待删除位置
 * @param e 返回值
 * @return true 
 * @return false 
 */
bool ListDelete(seqList &L, int i, int &e)
{
    if(i > L.length || i < 1)
    {
        return false;
    }
    e = L.data[i-1];
    for (int j = i; j < L.length; j++)
    {
        L.data[j-1] = L.data[j];
    }
    L.length --;
    return true;
}

/**
 * @brief 按值查找对应位置
 * 
 * @param L 顺序表引用
 * @param e 待查找值
 * @return int 值对应位置或0（未找到）
 */
int LocateElem(seqList &L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}

//
//int findmin(seqList &List,int &value){
//    int pos = 0;
//    int temp = 0;
//    if(List.length == 0){
//        printf("空");
//        return -1;
//    }
//    for (int i = 0; i < List.length; ++i) {
//        if(List.data[i] < List.data[pos])
//            pos = i;
//    }
//    temp = List.data[pos];
//    List.data[pos] = List.data[List.length-1];
//    return temp;
//}