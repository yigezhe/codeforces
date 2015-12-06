//每一个队至少有一名？
//五个人放在一个队，则五个里取两个choose(5,2)=10
//三个人分成两个队，一个队有两个人，另一个队友1个人
//只有两个人可以成为朋友！
//六个人分成三个队
//平均分，产生最少的朋友2,2,2
//侧重分，1，1，6-2, choose(4,2)=4*3/2=6
/*interface*/
/*interface implementation*/
#include<stdio.h>
#include<stdlib.h>
long long choose(long long n,long long k) {
    if(n==k) {
        return 1;
    } else if(n<k) {
        return 0;
    } else {
        long long res=1;
        long long i;
        for(i=0; i<k; i++) {
            res*=(n-i);
        }
        for(i=1; i<=k; i++) {
            res/=i;
        }
        return res;
    }
}

/*client*/
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    //printf("n=%d,m=%d\n",n,m);
    //n=10^9不允许我用数组！
    //3/2=1;
    //3%2=1;
    long long each=n/m;
    long long add_each=n%m;
    long long min_friends=0;
    min_friends+=(choose(each+1,2)*add_each);
    //1=choose(2,2)
    //printf("min_friends=%d\n",min_friends);
    min_friends+=(choose(each,2)*(m-add_each));
    //printf("min_friends=%d\n",min_friends);

    long long max_friends=choose(n-(m-1),2);
    printf("%lld %lld\n",min_friends,max_friends);

    return 0;
}
