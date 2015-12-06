//ingredients糖果之类的东西！
//粘在一起的东西！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int main() {
    int n,s;
    scanf("%d%d",&n,&s);
    int i;
    int max=-1;
    for(i=0; i<n; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        int sweets;
        if(x>s) {
            //买不起！
	    //用-1代表买不起！
                sweets=-1;
        } else if(x==s) {
            if(y>0) {
                sweets=-1;
            } else {
                sweets=0;
            }
        } else if(x<s) {
            if(y==0) {
                sweets=0;
            } else {
                sweets=100-y;
            }
        }
        if(sweets>max) max=sweets;
    }
    printf("%d\n",max);
    return 0;
}
