#include<stdio.h>
//codeforces上的计算机使用的是32bit操作系统
int main() {

     int n,m,a;
     scanf("%d %d %d",&n,&m,&a);
     //这里计算在长度上需要几块瓷砖
     int l=0;
     if (n%a==0) { l=n/a; }
     else { l=n/a+1; }

     //这里计算在宽度上需要几块瓷砖
     int w=0;
     if (m%a==0) { w=m/a; }
     else { w=m/a+1; }

     //codeforces上禁止使用%lld
     //只要禁止提醒，lld也是可以通过的！
     //%I64d在gcc上不能用！
     //n,m,a都可以用int表达，l，w也可以用int表达，只是结果会超出int，所以我只在结果上使用long long!
     long long s=l*w;//测试结果是错的，1000000000 1000000000 192 -270385980

     //错误的解释是，两个int相乘不会得到longlong，结果仍是int！

     printf("%lli\n",s);

     return 0;
}
