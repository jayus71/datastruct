#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void func(int *a){
    for (int i = 0; i < 4; i++)
    {
        a[i] = 22;
    }
    
}
int main() {
    // char str[100];
    // printf("请输入字符串：");
    // fgets(str, 100, stdin); // 读入字符串
    // int len = strlen(str);
    // if (len <= 1) { // 字符串长度小于等于1，无需操作
    //     printf("处理后的字符串为：%s", str);
    //     return 0;
    // }
    // int i, j;
    // for (i = 1, j = 1; i < len; i++) {
    //     if (str[i] != str[i-1]) { // 当前字符与前一个字符不同
    //         str[j++] = str[i]; // 将当前字符保留
    //     }
    // }
    // str[j] = '\0'; // 在字符串末尾添加空字符，表示字符串结束
    // printf("处理后的字符串为：%s", str);
    //--------------------------------
    // int arr[3] = {5,3,1};
    // int *p = &arr[1];
    // p[1] = *p-1+(p[-1]=3);
    // for (int i = 0; i < 3; i++)
    // {
    //     printf("%d",arr[i]);
    // }
    //--------------------------------
    // int a[4] = {1,2,3,4};
    // func(a);
    // for (int i = 0; i < 4; i++)
    // {
    //     printf("%d\n",a[i]);
    // }
    int a = 54385;
    int num = a, i =0;
    while (num)
    {
        int temp = num % 10;
        printf("%d",temp);
        num = num / 10;
        i++;
    }
    printf("\n%d",i);

    system("pause");
    return 0;
}

