/*我几次上传不成功的原因竟然是在main函数后面没有写return 0；导致在线系统判断我产生运行时错误！
 
  接下来的工作就是把我的第二个想法用代码实现！
  现在我觉得很重要的一点就是先产生想法，再把想法变成代码，这是我需要具备的两个相互联系的重要能力。
  我的第二个想法虽然简单，但是依然是我所陌生的代码，所以我必须亲自写出来，如果代码已经非常熟悉，那么我就可以不写！
 */
#include<stdio.h>
//我对空间的利用非常吝啬，所以我只加一！
#define MAX_N 50+1
int a[MAX_N];
int main() {
     int n,k;
     scanf("%d%d",&n,&k);
     //printf("n=%d k=%d\n",n,k);
     int i;
     int participants=0;
     //可以不从头加起，而是从第k位加起，这里k就不用减一，因为k正好表示k－1的下一位！
     for (i=0;i<n;i++) {
          scanf("%d",&a[i]);
     }
     //我知道错在哪里了，a［k－1］项在没有读完数组时，时不能确立的，整个数组至少要读k项，但是我在没有得到a[k-1]的值时，就直接进行比较，这是一个错误，mac gcc竟然没有指出这个错误！
     //改正办法在记录下整个数组后在比较！
     //因为数组是从零开始，而k从一开始，要使两者对应，所以我才减一
     for (i=0;i<n;i++) {
          if(a[i]>0 && a[i]>=a[k-1]) {
               participants++;
          }
         //printf("%d--%d\n",i,a[i]);
     }

     //printf("\nparticipants = %d\n",participants);
     printf("%d\n",participants);
     return 0;
}
