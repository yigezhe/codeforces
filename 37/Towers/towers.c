//disposal类似包之类的东西！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 1000+1
int main() {
	int n;
	scanf("%d",&n);
	int i;
	int counter[N];
	for(i=0;i<N;i++) {
		counter[i]=0;
	}
	for(i=0;i<n;i++) {
		int l;
		scanf("%d",&l);
		counter[l]++;
	}
	int height=0;
	int total=0;
	for(i=0;i<N;i++) {
		if(counter[i]!=0) {
			total++;
			if(counter[i]>height) height=counter[i];
		}
	}
	printf("%d %d\n",height,total);

	return 0;
}
