#include<stdio.h>
#include<math.h>
//codeforces上的计算机使用的是32bit操作系统
int main() {

     double n,m,a;
     //m,n,a从一开始就读为浮点数，而不是整数！
     scanf("%lf%lf%lf",&n,&m,&a);
     printf("%lli\n",(long long)(ceil(m/a)*ceil(n/a)));

     return 0;
}
