#include<stdio.h>
#include<math.h>
int main() {
     int n,m,a;
     scanf("%d %d %d",&n,&m,&a);
     //所以可以定义ceil（m/a）＝（m+a-1)/a;
     //这里的除法都是去余除法。
     //这里用一个算术表达式来处理两种情况，我用的是if！
     printf("%lli\n",(long long)((m+a-1)/a)*(long long)((n+a-1)/a));
     return 0;
}
