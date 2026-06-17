#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int my_strcmp(char* str1,char* str2) {
    while (*str1 == *str2) {
        if (*str1 == '\0') {
            return 0;//相等
        }

        str1++;
        str2++;
    }

    return *str1 - *str2;//str1中字符 与 str2 中字符不相等时，则 直接作差，>0 则 str1 > str2 ，<0 则str1 < str2
}

int main() {
    char arr[10] = {"abbbbb"};
    char* chp = "abcd";
    int result=my_strcmp(arr,chp);
    if (result > 0) {
        printf("%s > %s \n",arr,chp);
    }
    else if (result == 0) {
        printf("%s == %s \n",arr,chp);
    }
    else {
        printf("%s < %s\n",arr,chp);
    }
    
    return 0;
}


