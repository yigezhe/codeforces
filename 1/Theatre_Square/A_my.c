/*这是我自己的思路
  我想知道如何把测试代码分离，因为我想保留测试代码，但时又不想在上传时删除测试代码，这里的一个办法是用注释！但是我觉得注释还是不好，有没有更好的办法?
  */

#include<stdio.h>

//我个人喜欢下划线命名法！
//看来codeforces上的计算机使用的是32bit操作系统，我的mac是64bit操作系统！
//mac的编译器还是不错的，起码提醒的错误比较多！

int main() {

     //这里不分为input，solve了，直接读取输入，直接处理然后得到答案！
     int n,m,a;
     scanf("%d %d %d",&n,&m,&a);

     //printf("n=%d\nm=%d\na=%d\n",n,m,a);

     //这里计算在长度上需要几块瓷砖
     long long length_need=0;
     if (n%a==0) { length_need=n/a; }
     else { length_need=n/a+1; }

     //printf("length need is %ld\n",length_need);
     //这里计算在宽度上需要几块瓷砖
     long long width_need=0;
     if (m%a==0) { width_need=m/a; }
     else { width_need=m/a+1; }

     //printf("width need is %ld\n",length_need);

     //codeforces上禁止使用%lld?
     //只要禁止提醒，lld也是可以通过的！

     //%I64d在gcc上不能用！
     printf("%lli\n",length_need*width_need);//这个算是通过了！
     //printf("用ld打印lld\n");//可以打印，但是还是无法通过codeforces！

     /*
        这里我在测试本机上各种数据类型的数据长度！
        printf("short are %lu bytes\n",sizeof(short));
        printf("int are %lu bytes\n",sizeof(int));
        printf("long are %lu bytes\n",sizeof(long));
        printf("long long are %lu bytes\n",sizeof(long long));
      */

     return 0;
}
