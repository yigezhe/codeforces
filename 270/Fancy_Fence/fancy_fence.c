//我推导出的角度与边数之间的关系是
//边数=360/(180-角度)
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int main() {
	int t;
	scanf("%d",&t);
	int i;
	for(i=0;i<t;i++) {
		int a;
		scanf("%d",&a);
		if(360%(180-a)==0) {
			printf("YES\n");
		}else {
			printf("NO\n");
		}
	}
	return 0;
}
