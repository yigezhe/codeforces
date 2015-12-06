//non-decreasing 不减！增加或维持！
//感觉是寻找两个数组的不同项！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int main() {
	int na,nb;
	scanf("%d%d",&na,&nb);
	int k,m;
	scanf("%d%d",&k,&m);
	int i;
	int ak=0;
	for(i=0;i<na;i++) {
		int a;
		scanf("%d",&a);
		if(i==k-1) {
			ak=a;
		}
	}
	int bm=0;
	for(i=0;i<nb;i++) {
		int b;
		scanf("%d",&b);
		if(i==nb-m) {
			bm=b;
		}
	}
	if(ak<bm) printf("YES\n");
	else printf("NO\n");

	return 0;
}
