//submit ok!
#include<stdio.h>
int main() {
     int w;
     scanf("%d",&w);
     //test3说4也是成立的？就是说允许分成相等的两个偶数！
     if(w>=4&&w%2==0){
          printf("YES\n");
     } else {
          printf("NO\n");
     }
     return 0;
}
