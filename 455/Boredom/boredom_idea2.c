//在N＝100时超时！
#include<stdio.h>
#define N 100000
void print(int *,int );
void recursion(int,int);
int used[N];
int a[N];
int add_one[N];
int sub_one[N];
int di=0;
int score=0;
int max_score=0;
void recursion(int remain,int n) {
//printf("recursion(%d,%d)\n", remain,n);
    if(remain<=0) {
        //printf("%d\n",score);
        if(score>max_score) max_score=score;
        return ;
    }
    int i;
    for(i=0; i<n; i++) {
        if(!used[i]) {
            used[i]=1;
            score+=a[i];
            int addi=0;
            int subi=0;
            int j;
            for(j=0; j<n; j++) {
                if(!used[j] && a[j]==(a[i]+1)) {
                    add_one[addi]=j;
                    addi++;
                    used[j]=1;
                }
            }
            for(j=0; j<n; j++) {
                if(!used[j] && a[j]==(a[i]-1)) {
                    sub_one[subi]=j;
                    subi++;
                    used[j]=1;
                }
            }
            remain-=1;
            remain-=addi;
            remain-=subi;
            //printf("i=%d\nai=%d\nai-1=%d\nai+1=%d\n",i,a[i],subi,addi);
	    //以上是改变！
            recursion(remain,n);
	    //以下是还原，不管我们改变了多少，我们都需要还原！
            remain+=1;
            remain+=addi;
            remain+=subi;

            used[i]=0;
            score-=a[i];
            int k;
            for(k=0; k<addi; k++) {
                used[add_one[k]]=0;
            }
            for(k=0; k<subi; k++) {
                used[sub_one[k]]=0;
            }
        }
    }
    return ;
}
void print(int *b,int n) {
    int i;
    for(i=0; i<n; i++) {
        printf(" %d",b[i]);
    }
    printf("\n\n");
}
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
        used[i]=0;
    }
    recursion(n,n);
    //printf("max=%d\n",max_score);
    printf("%d\n",max_score);

    return 0;
}
