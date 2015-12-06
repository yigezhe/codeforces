//佩佩的表情给予的是，你想追求我，见到我就有反应！
//引入数学的坐标，很多问题都要做出数学的抽象！
//sender发出者
//recipient接收者
//佩佩是站在不理解我的角度和我说话，这是不好的！
//lineland，像一条线的岛！
//送到最近的就花费最少，
//送到最远的就花费最多！
/*interface*/
/*interface implementation*/
/*client*/
int max2(int a,int b) {
    if (a>b) return a;
    else return b;
}
int min2(int a,int b) {
    if(a>b) return b;
    else return a;
}
#include<stdio.h>
#define N 100000+1
int main() {
    int n;
    scanf("%d",&n);
    int i;
    int x[N];
    for(i=0; i<n; i++) {
        scanf("%d",&x[i]);
    }
    int min,max;
    for(i=0; i<n; i++) {
        //这个逻辑划分比较清晰合理！
        if(i>0 && i<n-1) {
            min=min2(x[i]-x[i-1],x[i+1]-x[i]);
            max=max2(x[n-1]-x[i],x[i]-x[0]);
        } else if(i==n-1) {
            min=x[n-1]-x[n-2];
            max=x[n-1]-x[0];
        } else if(i==0) {
            min=x[1]-x[0];
            max=x[n-1]-x[0];
        }
        printf("%d %d\n",min,max);
    }
    return 0;
}
