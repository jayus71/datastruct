#include <stdio.h>
#include <stdlib.h>
void f(int *p){
    *p = 10;
}
int main(int argc, char const *argv[])
{
    // int *p ;
    // //*p = 100;
    // printf("old: %d\n",(*p));
    
    // f(p);
    // printf("new: %d\n",(*p));
    int a[3][4];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            // 左移运算符优先级低于加
            // (i + j)<<2 等效于 i + j << 2
            a[i][j] = (i + j)<<2;
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("--------------------\n");
    // c语言按行优先存储，二维数组实质上也是按一维数组存储的
    // 所以a[1][4] 实质上就是 a[2][0]
    printf("a[1][4]:%d\n",a[1][4]);
    system("pause");
    return 0;
}
