//1+(1+2)+(1+2+3)+(1+2+3+4)+...级数的通项式子是i*(i+1)*(i+2)/6
//想法二，刚好学习一下，如何解三次方程！
//要不然我们需要解方程x*(x+1)*(x+2)/6=n,floor(x)就是我们需要的结果！
//解方程x*(x+1)*(x+2)/6=n
//i^3+3i^2+2i=6n
//这里我选择用华罗庚思路来解决这个问题！
//a1=3,a2=2,a3=-6n
//p=a2-a1^2/3=-1;
//q=-6n
//x^3-x-6n=0
//delta=162n+4,说明有三个实数解，我们需要那个最大的实数解！
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
