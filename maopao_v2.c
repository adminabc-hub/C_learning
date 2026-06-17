#include<stdio.h>

int my_int_arr(const void* e1,const void* e2) {//自定义的比较器
    return (*(int*)e1) - (*(int*)e2);//把e1、e2 强制转为int* 再解引用 后 做差 比较大小
}

void Swap(char* buff1,char* buff2,int width) {//功能：交换buff1 和 buff2 比如buff1、buff2都4byte,他们之间两两交换，1byte 1byte交换
    char temp = '\0';
    for (int i = 0; i < width;i++) {
        temp = *buff1;
        *buff1 = *buff2;
        *buff2 = temp;
        buff1++;//一对 交换完，buff1、fuff2都加1 跳到下一个字节 再 交换
        buff2++;
    }
}

void my_sqort(
    void* base,//要排序的数组 首元素地址
    int length,//数组的总长度
    int width,//每个元素的宽度，多少字节
    int (*cmp)(const void* e1,const void*e2) //我们自己定义比较函数
) {
    for (int i = 0; i < length-1;i++) {
        for (int j = 0; j < length - 1 - i;j++) {
            if (cmp((char*)base+j*width,(char*)base+(j+1)*width) > 0 ) {//把void* base转为char* base 原因char* 是1个字节的，方便计算步长
                Swap((char*)base + j * width, (char*)base + (j + 1) * width,width);//交换
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
    my_sqort(arr,4,sizeof(arr[0]),my_int_arr);
    print1(arr,4);
    return 0;
}

