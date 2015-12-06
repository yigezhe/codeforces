//最近的英语自学帮助了我的编程阅读，这个方向是好的，加油！
//两种语言中你选择字母最少的那个单词纪录，如果字母相同，选第一种语言使用的！
//这里可以用hash处理！
//两种语言个建立一个hash！
//hash的缺点还是占用内存太多，这里直接用两个字符串数组处理也可以！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#include<string.h>
#define C 10+1
#define M 3000+1
int n,m;
char a[M][C];
int find(char *word) {
    int i;
    for(i=0; i<m; i++) {
        if(strcmp(a[i],word)==0) {
            return i;
        }
    }
    return -1;
}
int main() {
    scanf("%d%d",&n,&m);
    int i;
    char b[M][C];
    for(i=0; i<m; i++) {
        scanf("%s%s",a[i],b[i]);
    }
    char c[M][C];
    //这个程序的运行时间复杂度时n^2，由于n＝3000，所以程序可以在一秒之内完成！
    //这个程序考察了一种综合的实现能力！
    for(i=0; i<n; i++) {
        scanf("%s",c[i]);
        int which=find(c[i]);
        int c_length=strlen(c[i]);
        int b_length=strlen(b[which]);
        if(c_length>b_length)
            printf(" %s",b[which]);
        else
            printf(" %s",c[i]);
    }
            printf("\n");
    return 0;
}
