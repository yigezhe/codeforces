//生活在笛卡尔平面上！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int main() {
    //至少用a＋b步！
    //中间不可以停？
    int a,b,s;
    scanf("%d%d%d",&a,&b,&s);
    if(a<0)a=-a;
    if(b<0)b=-b;
    //把a，b都变为正数，符合我的计算！
    if(s>=(a+b)) {
        //就是先用a＋b步走到a，b点
        //之后围绕a，b点随便走n步，又n步回来！
        //就是说多出来的步子是偶数步，
        //不然在不许停顿要求下，无法回到a＋b点！
        if((s-(a+b))%2==0) printf("YES\n");
        else printf("NO\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
