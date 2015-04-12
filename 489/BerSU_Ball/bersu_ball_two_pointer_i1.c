//运用刚学到的技术来试试看！
#include<stdio.h>
#define MAX 100
int main() {
    int n;
    scanf("%d",&n);
    int i,j;
    int a[MAX];
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    //从小到大排列！
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if (a[i]>a[j]) {
                int tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }

        }

    }

    int m;
    scanf("%d",&m);
    int b[MAX];
    for(i=0; i<m; i++) {
        scanf("%d",&b[i]);
    }
    for(i=0; i<m; i++) {
        for(j=i+1; j<m; j++) {
            if (b[i]>b[j]) {
                int tmp=b[i];
                b[i]=b[j];
                b[j]=tmp;
            }

        }

    }
    int count=0;
    i=0;j=m-1;
    while(i<n) {
	    while((a[i]-b[j]>1 || a[i]-b[j]<-1) && j>0) j--;
	    if (a[i]-b[j]>=-1 && a[i]-b[j]<=1)  {
		    count++;
		    printf("(%d,%d)\n",a[i],b[j]);
	    }
	    i++;
    }
    printf("%d\n",count);

    return 0;
}
