#include<stdio.h>
int main() {
        //这里我在测试本机上各种数据类型的数据长度！
        printf("short are %lu bytes\n",sizeof(char));
        printf("short are %lu bytes\n",sizeof(short));
        printf("int are %lu bytes\n",sizeof(int));
        printf("long are %lu bytes\n",sizeof(long));
        printf("long long are %lu bytes\n",sizeof(long long));
	return 0;
}

