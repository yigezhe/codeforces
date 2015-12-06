
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	int counter=0;
	//分析看，a^2=n,b=n,a=m,b^2=m是a，b所能取到的最大值！
	int a,b;
	for(a=0;a*a<=n && a<=m;a++) {
		for(b=0;b*b<=m && b<=n;b++) {
			if(a*a+b==n && a+b*b==m) {
				counter++;
			}
		}
	}
	printf("%d\n",counter);
	return 0;
}
