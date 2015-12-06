#include<stdio.h>
int main() {
	int n;
	scanf("%d",&n);
	int i;
	double cocktail=0.0;
	for(i=0;i<n;i++) {
		int p;
		scanf("%d",&p);
		cocktail+=(p/100.0);
	}
	printf("%f\n",cocktail/n*100);
	return 0;
}
