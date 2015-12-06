#include <stdio.h>
int main() {
    int m,n,a;
    //这个表示，我的计算机上没有
    __int64 row,col;
    while(scanf("%d %d %d",&m,&n,&a) != EOF) {
	    //这是按题目要求提前做了一个约束！
        if(a >= 1 ) {
            if(m%a==0)
                row=m/a;
            else
                row=m/a+1;

            if(n%a==0)
                col=n/a;
            else
                col=n/a+1;

            printf("%I64d\n",row*col);

        }
    }
    return 0;
}
