//俄罗斯人对柏林情有独钟！
//题目越难，这个问题的实用价值越大！
//数据按名字大小分配和插入？
//拉丁字母就是英文字母？
//第一感觉就是这个问题是在考察数据结构，
//用数组结构解决，可能时间上花费会很大！但是不管花多少时间
//先实现吧！
//办法一，去掉数字，再比较，
//办法二，另建一个数组来保存数字！
/*interface*/
/*interface implementation*/
#include<stdio.h>
#include<string.h>
#define C 33+5
#define N 100001
char database[N][C];
int database_size;
void search(char * name, char *result) {
    int i;
    int same=0;
    for(i=0; i<database_size; i++) {
        if(strcmp(name,database[i])==0) {
            same++;
        }
    }
    strcpy(database[database_size],name);
    database_size++;
    if(same==0)strcpy(result,"OK");
    else {
        strcpy(result,name);
        char digit[C];
        sprintf(digit,"%d",same);
        strcat(result,digit);
    }
}
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    int i;
    database_size=0;
    for(i=0; i<n; i++) {
        char name[C];
        scanf("%s",name);
        char result[C];
        search(name,result);
        printf("%s\n",result);
    }

    return 0;
}
