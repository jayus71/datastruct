cmake_minimum_required(VERSION 3.22)
project(datastruct)

set(CMAKE_CXX_STANDARD 14)

add_executable(datastruct
        list/linklist.cpp list/test.cpp
        list/seqlList.cpp list/DlinkList.cpp list/listExercise.cpp list/seqList.h Tree/BiTree.cpp Tree/BiTree.h Queue/SqQueue.cpp Queue/SqQueue.h base.h Stack/SqStack.cpp Stack/SqStack.h Sort/sort.cpp Sort/sort.h base.cpp Sort/sortTest.cpp Sort/sortExercise.cpp list/LinkList.h)
