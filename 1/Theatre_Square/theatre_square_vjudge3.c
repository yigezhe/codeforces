//submit ok!
#include <stdio.h>
int main() {
	//1 ≤  n, m, a ≤ 10^9)
    int m,n,a;
    //row 行，col 列！
    long long row,col;
    //这里仅需读取一行，作者多做了一些工作！
    while(scanf("%d %d %d",&m,&n,&a) != EOF) {
        if(a >= 1 ) {
            if(m%a==0)
                row=m/a;
            else
                row=m/a+1;

            if(n%a==0)
                col=n/a;
            else
                col=n/a+1;

            printf("%lld\n",row*col);

        }
    }
    return 0;
}
