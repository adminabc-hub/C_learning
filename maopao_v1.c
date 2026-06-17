#include<stdio.h>
void my_sqort(int* p,int length) {
    int temp = 0;
    for (int i = 0; i < length-1;i++) {
        for (int j = 0; j < length - 1 - i;j++) {
            if (*(p+j)>*(p+j+1)) {//*(p+j) 可以写为 (*p)[j]
                temp = *(p+j);
                *(p + j) = *(p+j+1);
                *(p + j + 1) = temp;
            }
        }
    }
}

void print1(int* p,int length) {
    for (int i = 0; i < length;i++) {
        printf("%d ",*(p+i));
    }
    printf("\n");
}
int main() {
    int arr[4] = { 5, 2, 7, 1 };
    my_sqort(arr,4);//函数调用
    print1(arr,4);//打印结果
    return 0;
}

