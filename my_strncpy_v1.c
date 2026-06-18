#include<stdio.h>

void my_strncpy(char* dest,char* source,int count){
	//while(count-- && (*dest++ = *source++));//不考虑最后补‘\0’可以这样写
	while(count-- && *source != '\0'){//当source没有到'\0' 一直拷贝操作
		*dest++ = *source++;
	}
	
	if(count>0){//如果source中“ab” 但如果count=5，那剩下补3个'\0'
		*dest++='\0';
		count--;
	}
}

int main(){
	char arr[10]={"r"};
	char* p="abcdef";
	my_strncpy(arr,p,2);
	printf("%s\n",arr);//ab
	return 0;
}
