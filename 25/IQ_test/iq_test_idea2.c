//判断奇偶数之间的差别？
//evenness是奇偶性的意思？
//平整度是什么？数组的平整度是什么？
//计算物种均一度！
//J=H'/H'max
//H'max=logS
//S是总的物种数！
//pi是第i个物种占总数的比例！
//H'=-sum(1,S)pilog(pi);
/*interface*/
int abs(int  ) ;
double ln(double  ) ;
/*interface implementation*/
#include<math.h>
double ln(double a ) {
    return log(a);
}

int abs(int a) {
    if(a<0) return -a;
    else return a;
}
/*client*/
#include<stdio.h>
#define N 100+1
//这个程序让我去求解平整度这一个我没有见过的概念？
int main() {
    //统计有多少个奇数，有多少个偶数，相减就可以！
    int n;
    scanf("%d",&n);
    int i;
    int a[N];
    int b[N];
    for(i=0; i<N; i++) {
        b[N]=0;
    }
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
        b[a[i]]++;
    }
    int S=0;
    int p[N];
    for(i=0; i<N; i++) {
        if(b[i]>0) {
            p[S]=b[i];
            S++;
        }
    }

    double Hmax=ln(S);
    double H=-sum(1,S)p[i]*ln(p[i]);
    double J=H/Hmax;

    return 0;
}
