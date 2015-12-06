//ribbon是一个棍子？
//先按最短的裁截，再次之，再次次之
//但这样处理有一个问题，就是如果剩下的长度不是a，b，c之一，那么这种处理是不行的！
//这个问题应该是找abc的最大公约数！
//10 4 6 gcd(4,6)=2,10/(2+3)
//10 2 4 gcd(2,4)=2,10/2
//10 1 4 gcd(1,4)=2,10/2
//coincide,相同！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int n,a,b,c;
int cuts;
//这个递归结构太复杂了！
int cut(int ribbon,int step) {
//printf("cut(%d,%d)\n",ribbon,step);
    if(ribbon==0) {
        return step;
    }
    if(ribbon<a) {
        return 0;
    } else {
        if(cut(ribbon-a,step+1)) return step+1;
        else {
            if(ribbon<b) {
                return 0;
            } else {
                if(cut(ribbon-b,step+1)) return step+1;
                else {
                    if(ribbon<c) {
                        return 0;
                    } else {
                        if(cut(ribbon-c,step+1)) return step+1;
			else return 0;
                    }

                }
            }

        }

    }
}
int main() {
    scanf("%d%d%d%d",&n,&a,&b,&c);
    //printf("%d %d %d\n",a,b,c);

    //让abc从小到大排列！
    if(a>b) {
        int tmp=a;
        a=b;
        b=tmp;
    }
    if(b>c) {
        int tmp=b;
        b=c;
        c=tmp;
    }
    if(a>b) {
        int tmp=a;
        a=b;
        b=tmp;
    }
    //printf("%d %d %d\n",a,b,c);
    printf("%d\n",cut(n,0)+1);

    return 0;
}
