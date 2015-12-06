//这是div1的题目，初看还是很有难度！
//就是实现一个构造！
//从例子看都是从1开始的！
//
/*interface*/
#include<stdio.h>
#define N 100000+1
int abs(int a) {
    if(a>0) return a;
    else return -a;
}
/*interface implementation*/
/*client*/
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    int permutation[N];
    int i;
    for(i=0; i<n; i++) {
        permutation[i]=i+1;
    }
    //想法一，通过互换和检查来看是不是达到目的！
    //这个方法可能超时，而且呼唤的规则是？
    int visited[N+1];
    for(i=0; i<n+1; i++) {
        visited[i]=0;
    }
    int p=0;
    permutation[0]=1;
    visited[1]=1;
    p++;
    int before=1;
    while(p<n) {
        if(k==0) {
            for(i=1; i<n+1; i++) {
                if(visited[i]==0) {
                    permutation[p]=i;
                    visited[i]=1;
                    p++;
                }
            }
        } else {
            int next=before+k;
            if(next>n || visited[next]==1) {
                next=before-k;
                if(next<1) {
                    break;
                } else {
                    permutation[p]=next;
                    visited[next]=1;
                    p++;
                }
            } else {
                permutation[p]=next;
                visited[next]=1;
                p++;
            }
            k--;
            before=next;
        }
    }
    for(i=0; i<n; i++) {
        printf(" %d",permutation[i]);
    }
    printf("\n");

    return 0;
}
