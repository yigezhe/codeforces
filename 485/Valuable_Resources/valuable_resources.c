#include<stdio.h>
long long max(long long a,long long b) {
    if(a>b) return a;
    else return b;
}
int main() {
    int n;//地图上矿山的个数
    scanf("%d",&n);
    long long max_x,min_x,max_y,min_y;
    int x,y;
    scanf("%d%d",&x,&y);
    max_x=min_x=x;
    max_y=min_y=y;
    int i;
    for(i=0; i<n-1; i++) {
        scanf("%d%d",&x,&y);
        if(x>max_x) max_x=x;
        if(x<min_x) min_x=x;
        if(y>max_y) max_y=y;
        if(y<min_y) min_y=y;
    }
    long long length=max(max_x-min_x,max_y-min_y);
    long long area=length*length;
    printf("%lld\n",area);
    return 0;
}
