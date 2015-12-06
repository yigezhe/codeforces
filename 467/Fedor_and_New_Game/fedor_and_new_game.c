#include<stdio.h>
#define M 1000+1
int is_friend(int a,int b,int n,int k) {
    int count=0;
    int i;
    for(i=0; i<n; i++) {
	    //比较最末尾的bit
        if(a%2!=b%2) count++;
        a=a>>1;
        b=b>>1;
    }
    //最多有k个不相同的bit！
    if(count<=k) return 1;
    else return 0;
}
int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int army[M];
    int i;
    for(i=0; i<=m; i++) {
        scanf("%d",&army[i]);
    }
    int count=0;
    for(i=0; i<m; i++) {
        if(is_friend(army[m],army[i],n,k)) {
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
