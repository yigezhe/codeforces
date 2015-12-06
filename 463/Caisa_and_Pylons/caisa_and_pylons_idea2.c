//前一个比后一个高，他将获取能量
//前一个比后一个低，他需要花费能量
//前一个和后一个相等，他不用花费，也无法获取！
//-2+1+1-2
//我的思考时，例子一只需花3个美元就可以？
//这里还有一个隐含高度0
//0 3 4 3 2 4
//-3 -1 1 1 -2
//想法一，模拟，想法二，相加就可以！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 100001
int main() {
    int n;
    scanf("%d",&n);
    int i;
    int h[N];
    for(i=0; i<n; i++) {
        scanf("%d",&h[i]);
    }
    //这里实现想法二！
    int energy=0;
    int money=0;
    if(h[0]>0) {
        money+=h[0];
    }
    for(i=0; i<n-1; i++) {
	    //printf("energy=%d money=%d\n",energy,money);
        if(h[i]-h[i+1]>=0) {
            energy+=(h[i]-h[i+1]);
        } else {
            if(energy>=(h[i+1]-h[i])) {
                energy-=(h[i+1]-h[i]);
            } else {
                money+=((h[i+1]-h[i])-energy);
                energy=0;
            }
        }
    }
    printf("%d",money);

    return 0;
}
