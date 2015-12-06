#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int max,min;
    scanf("%d",&max);
    min=max;
    int amazing=0;
    //第一个元素作为max和min！
    int i;
    for(i=1; i<n; i++) {
        int a;
        scanf("%d",&a);
        if(a>max) {
            amazing++;
	    max=a;
        } else if(a<min) {
            amazing++;
	    min=a;
        }
    }
    printf("%d\n",amazing);
    return 0;
}
