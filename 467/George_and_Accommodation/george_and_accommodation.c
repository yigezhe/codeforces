#include<stdio.h>
#define N 100+5
int main() {
	int n;
	scanf("%d",&n);
	int i;
	int p[N],q[N];
	int count=0;
	for(i=0;i<n;i++) {
		scanf("%d%d",&p[i],&q[i]);
		if(q[i]-p[i]>1) {
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
}

