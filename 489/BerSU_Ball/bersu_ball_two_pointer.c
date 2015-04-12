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
    for(i=0; i<n; i++) {
	    printf(" %d",a[i]);
    }
	    printf("\n");

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
    for(i=0; i<m; i++) {
	    printf(" %d",b[i]);
    }
	    printf("\n");
    int is_pair[MAX][MAX];
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
	    if (a[i]-b[j]>=-1 && a[i]-b[j]<=1)  {
		    is_pair[i][j]=1;
            } else {
		    is_pair[i][j]=0;
	    }

        }

    }
    /*
    well, as you've defined the sample problem, array A and B are already sorted in ascending order and we assume, n = size of A and m = size of B, i = n-1 and j=0
	    Now take into consideration that,
		if A[i]+B[j]<X then A[i-1]+B[j]<X for sure (as they're already sorted, A[i]>=A[i-1]). So in this case, there is no benefit to iterate i downward keeping j fixed. Instead, we should just increase j while j<n-1 and A[i]+B[j]<X.
			if A[i]+B[j]>=X, then there may be more A[y], 0<=y<=i-1 such that , A[y]+B[j]>=X. so we should just decrease i while i>0 and A[i]+B[j]>=X.
				So there will be in total (n+m) operations as i will be moved between n-1 to 0 and j will be moved between 0 to m-1 and i will never be increased as well as j will never be decreased.
					Hope it helps :-)
					*/

    int count=0;
    i=0;j=m-1;
    while(i<n) {
	    while(!is_pair[i][j] && j>0) j--;
	    if (is_pair[i][j])  {
		    count++;
		    printf("(%d,%d)\n",a[i],b[j]);
	    }
	    i++;
    }
    printf("%d\n",count);

    return 0;
}
