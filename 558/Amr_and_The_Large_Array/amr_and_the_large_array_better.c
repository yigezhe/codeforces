//整个程序超时了！
/*interface*/
#include<stdio.h>
#define N 100000
#define M 1000000+1
/*interface implementation*/
/*client*/
int main() {
    int n;
    int a[N];
    int count[M];
    scanf("%d",&n);
    int i;
    for(i=0; i<M; i++) {
        count[i]=0;
    }
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
        count[a[i]]++;
    }
    int max_i[N];
    max_i[0]=1;
    int ni=1;
    int max=count[1];
    for(i=2; i<M; i++) {
        if(count[i]>max) {
            max=count[i];
            max_i[0]=i;
            ni=1;
        } else if(count[i]==max) {
            max_i[ni]=i;
            ni++;
        }
    }
    int j;
    int min_start=0;
    int min_end=n-1;
    for(j=0; j<ni; j++) {
        for(i=0; i<n; i++) {
            if(a[i]==max_i[j]) break;
        }
        int start=i;
        for(i=n-1; i>=0; i--) {
            if(a[i]==max_i[j]) break;
        }
        int end=i;
        if(end-start<min_end-min_start) {
            min_end=end;
            min_start=start;
        }
	if(end-start+1==max) break;
    }
    printf("%d %d\n",min_start+1,min_end+1);

    return 0;
}
