//
// Created by Jayus on 2022/11/8.
//
#include "sort.h"
#include <stdlib.h>
void swap(ElemType &a,ElemType &b){
   ElemType temp = a;
   a = b;
   b = temp;
}
int Partition_Random(ElemType A[], int low, int high){
   if(low > high)
       return -1;
   int randIndex = low + rand() % (high - low + 1);
   swap(A[randIndex], A[low]);
   ElemType pivot = A[low];
   int i = low;
   for (int j = low+1; j < high; ++j) {
       if(A[j] < pivot)
           swap(A[++i],A[j]);
   }
   swap(A[i],A[low]);
   return i;
}

int main(int argc, char const *argv[]) {
    ElemType A[5] = {'a', 'b', 'c', 'd', 'e'};
    int i = Partition_Random(A, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        printf("%c",A[i]);
    }
    
    system("pause");
    return 0;
}