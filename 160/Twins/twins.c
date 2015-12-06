//思路，先计算一个和，然后从大到小找硬币，只要找到的硬币之和超过总值的一半就可以！
#include<stdio.h>
#define N 100+5
int main() {
    int n;
    scanf("%d",&n);
    int i,j;
    int a[N];
    int sum=0;
    for(i=0; i<n; i++) {
        scanf("%d",a+i);
        sum+=*(a+i);
    }
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(a[i]<a[j]) {
                int tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }

        }
    }


    int coins=0;
    int value=0;
    for(i=0; i<n; i++) {
                value+=a[i];
		coins++;
		if(value>sum/2.0) {
			break;
		}
    }
    printf("%d\n",coins);
    return 0;
}
