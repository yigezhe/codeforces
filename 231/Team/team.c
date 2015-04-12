#include<stdio.h>
#define MAX_N 1050
int main() {
    int n;
    scanf("%d",&n);
    int solution=0;
    int i,j;
    for(i=0; i<n; i++) {
	    int count=0;
        for(j=0; j<3; j++) {
		int view;
		scanf("%d",&view);
		if (view==1) { count++; }
        }
	if (count>=2) { solution++; }
    }
    printf("%d\n",solution);
    return 0;
}
