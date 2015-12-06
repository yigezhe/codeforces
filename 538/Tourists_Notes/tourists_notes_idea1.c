#include<stdio.h>
#define M 100000+5
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    int h[M];
    //10000-0000=100M
    //10000-0000int=400M
    int max_h=0;
    int before_d=1;
    int before_h=0;
    int first=1;
    for(i=0; i<m; i++) {
        int d,h;
        scanf("%d%d",&d,&h);
        if(d==1) {
            //不用处理！
            before_d=d;
            before_h=h;
            if(h>max_h) max_h=h;
        } else {
		if(first) {
			int h1=h+d-before_d;
			if(h1>max_h) max_h=h1;
		}


            before_d=d;
            before_h=h;
        }
    }
    return 0;
}
