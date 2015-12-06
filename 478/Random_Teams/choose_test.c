#include<stdio.h>
int C(int n,int k) {
    //if(n==k) { return 1;
    //} else if(n<k) {
    if(n<k) {
        return 0;
    } else {
	    //这段代码在n＝＝k时会返回零！
        int res=1;
        int i;
        for(i=0; i<k; i++) {
            res*=(n-i);
        }
        for(i=1; i<=k; i++) {
            res/=i;
        }
        return res;
    }
}
int main() {
	printf("C(%d,%d)=%d\n",2,2,C(2,2));
	printf("C(%d,%d)=%d\n",5,5,C(5,5));
	printf("C(%d,%d)=%d\n",1,2,C(1,2));
	return 0;
}
