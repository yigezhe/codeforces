#include<stdio.h>
#define N 50+5
int a[N];
int main() {
     int n,k;
     scanf("%d%d",&n,&k);
     int i;
     int participants=0;
     //可以不从头加起，而是从第k位加起，这里k就不用减一，因为k正好表示k－1的下一位！
     //因为k前面的都是大于等于第k位的！
     for (i=0;i<n;i++) {
          scanf("%d",&a[i]);
     }
     //我知道错在哪里了，a［k－1］项在没有读完数组时，时不能确立的，整个数组至少要读k项，但是我在没有得到a[k-1]的值时，就直接进行比较，这是一个错误，mac gcc竟然没有指出这个错误！
     //改正办法在记录下整个数组后在比较！
     //因为数组是从零开始，而k从一开始，要使两者对应，所以我才减一 a[k-1]就是第k位的值！
     for (i=0;i<n;i++) {
          if(a[i]>0 && a[i]>=a[k-1]) {
               participants++;
          }
     }

     //printf("\nparticipants = %d\n",participants);
     printf("%d\n",participants);
     return 0;
}
