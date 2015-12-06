//1+(1+2)+(1+2+3)+(1+2+3+4)+...级数的通项式子是i*(i+1)*(i+2)/6
//想法一
//我计算能堆几层，我的想法是尝试所有的i，看哪个i满足，n+1>i*(i+1)*(i+2)/6>=n
//想法二，刚好学习一下，如何解三次方程！
//要不然我们需要解方程x*(x+1)*(x+2)/6=n,floor(x)就是我们需要的结果！
#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int i;
    //最大值我取n,这是每层都只取一个的高度！
    int height=0;
    for(i=0; i<=n; i++) {
        if(i*(i+1)*(i+2)/6==n) {
            height=i;
            break;
        } else if(i*(i+1)*(i+2)/6>n) {
            height=i-1;
            break;

        }
    }
    printf("%d\n",height);
    return 0;

}
