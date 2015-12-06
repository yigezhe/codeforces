//想法，合力为零，那就是检查每一个方向上的合力都为零！
#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int x=0,y=0,z=0;
    int i;
    for(i=0; i<n; i++) {
        int a;
        scanf("%d",&a);
        x+=a;
        int b;
        scanf("%d",&b);
        y+=b;
        int c;
        scanf("%d",&c);
        z+=c;
    }
    if(x==0 && y==0 && z==0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
