//这个问题有点简单过了！
/*interface*/
#include<stdio.h>
int min(int a,int b) {
	if(a>b) return b;
	else return a;
}
/*interface implementation*/
/*client*/
int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d %d\n",min(a,b),(a+b-2*min(a,b))/2);
    return 0;
}
