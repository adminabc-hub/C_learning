#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

typedef struct student {//定义一个学生 结构体，并且命名为stu
    char name[50];
    int age;
} stu;



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


int student_name_cmp(const void* e1,const void* e2) {//比较name 字符串
    return strcmp(((stu*)e1)->name,((stu*)e2)->name);
}

void print2(stu* p,int length) {
    for (int i = 0; i < length;i++) {
        printf("%s %d\n",p->name, p->age);//这里不能写(p++)->name,(p++)->age，因为前面p++，后面又p++ 导致越界。
        p++;
    }
}

int student_age_cmp(const void* e1,const void* e2) {//比较结构中 age 大小，还是使用做差法。
    return (*(int*)e1) - (*(int*)e2);
 }
 

int main() {

    //2、结构体数据name 排序
    stu studentArr[3] = { {"zhangshan",21} ,{"lishi",10} ,{"wangwu",14}};
    my_sqort(studentArr,3,sizeof(studentArr[0]),student_name_cmp);
    print2(studentArr,3);

    //3 结构体数据 age排序
    my_sqort(studentArr,3,sizeof(studentArr[0]),student_age_cmp);
    print2(studentArr, 3);
    return 0;
}


