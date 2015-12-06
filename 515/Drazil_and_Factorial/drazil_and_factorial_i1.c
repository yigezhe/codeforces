//我的基本思路是先求出F（a）再去找x
//找x的思路是，n!>x中最小的n
//2!^y<a,这就是x的最多数位
//由这个最多位递减式地去寻找！
#include<stdio.h>
#include<math.h>
#define N 15+5
//int 最多表示十位！
long long Fd(int x) {
	long long product=1;
	int i;
	while(x>0) {
		int digit=x%10;
		if(digit==0 || digit == 1) {
			return 0;
		}
		long long factorial=1;
		for(i=2;i<=digit;i++) {
			factorial*=i;
		}
		product*=factorial;
		x/=10;
	}
	return product;
}
long long F(char a[],int size) {
    long long product=1;
    int i,j;
    for(j=0; j<size; j++) {
        if(a[j]!='0') {
            long long factorial=1;
            int digit=a[j]-'0';
            for(i=2; i<=digit; i++) {
                factorial*=i;
            }
            product*=factorial;
        }
    }
    return product;
}

int main() {
    int n;
    scanf("%d",&n);
    char a[N];
    scanf("%s",a);
    //printf("%d\n",F(135));
    //printf("%d\n",F(a,n));
    long long same=F(a,n);
    printf("%lld\n",same);
    printf("%f\n",log(same));

    long long max=0;
    int i;
    for(i=0; i<log(same); i++) {
        max *= 10;
        max += 2;
    }
    printf("%lld\n",max);
    long long h;
    for(h=max; h>=0; h--) {
        if(Fd(h)==same) {
            printf("%lld\n",h);
            break;
        }
    }
    return 0;
}
