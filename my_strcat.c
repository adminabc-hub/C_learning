#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void my_strcat(char* dest,char* source) {
    for (int i = 0; *dest != '\0';i++) {
        dest += 1;//最后一次 *dest ='\0' ,退出for循环，这时dest指针正好指向最后,后面while循环正好从dest最后开始
    }
    
    while (*dest++ = *source++);
    *dest = *source;//把source中最后'\0' 赋给*dest
}

int main() {
    char arr[10] = "abcxx";
    char* chp = "def";
    my_strcat(arr,chp);
    printf("%s\n",arr);
    return 0;
}

