//bowls碗
//plates盘
//dish一餐
//optimally优化！做出了最好的选择！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int i;
    int wash=0;
    for(i=0; i<n; i++) {
        int a;
        scanf("%d",&a);
        if(a==1) {
            if(m==0) wash++;
            else m--;
        } else if(a==2) {
            if(k>0) {
                k--;
            } else {
                if(m==0) {
                    wash++;
                } else m--;
            }
        }
    }
    printf("%d",wash);
    return 0;
}
