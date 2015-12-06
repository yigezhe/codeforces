/*interface*/
#include<stdio.h>
#define N 1000
/*interface implementation*/
/*client*/
int main() {
    int n,a[N];
    scanf("%d",&n);
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    int min_changes=0;
    int information=0;
    int visit[N];
    for(i=0; i<n; i++) {
        visit[i]=0;
    }
    while(1) {
        for(i=0; i<n; i++) {
            if(a[i]<=information && !visit[i]) {
                information++;
                visit[i]=1;
            }
        }
        if(information==n) break;
        else min_changes++;
        for(i=n-1; i>=0; i--) {
            if(a[i]<=information && !visit[i]) {
                information++;
                visit[i]=1;
            }
        }
        if(information==n) break;
        else min_changes++;
    }
    printf("%d\n",min_changes);
    return 0;
}
