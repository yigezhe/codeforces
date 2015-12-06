//hamming distance就是对两个相同长度的string的距离定义！
//定义两个string距离的价值时什么？
//这里的距离是不相同位数的个数！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 100000+1

int distance(char *a,char *b) {
    int counter=0;
    while(*a != '\0' && *b != '\0') {
        if(*a!=*b) counter++;
        a++;
        b++;
    }
    return counter;
}
void print_string(char *a,char *b) {
    int swap=0;
    while(*a != '\0' && *b != '\0') {
        if(*a!=*b) {
            if(swap==0)
                printf("%c",*a);
            else
                printf("%c",*b);
	    swap=!swap;
        } else printf("%c",*a);
        a++;
        b++;
    }
    printf("\n");
}
int main() {
    char s[N];
    char t[N];
    scanf("%s",s);
    scanf("%s",t);
    int d=distance(s,t);
    if(d%2==0) {
        //printf("possible\n");
        print_string(s,t);
    } else {
        printf("impossible\n");
    }
    return 0;
}
