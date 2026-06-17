#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void my_strcpy(char* dest,char* source) {
    while (*dest++ = *source++);
    *dest = *source;//'\0' 赋值给*dest
}

int main() {
    char arr[10] = {'\0'};
    char* chp = "deftttt";
    my_strcpy(arr,chp);
    printf("%s\n",arr);
    return 0;
}

