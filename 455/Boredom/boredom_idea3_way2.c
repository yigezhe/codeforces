//已经很接近问题的解决了，但是就是差一点，由于数据太大
//我无法测试！
#include<stdio.h>
#define N 100000
#define T 0

/*interface*/
void sort(int *,int);
void print(int *,int);
int compare(const void *,const void *);
int counter[N+1];

/*interface implementation*/
#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b) {

    int *x = (int *) a;
    int *y = (int *) b;
    return counter[*y] - counter[*x];
}
void sort(int *data,int length) {
    //qsort (data, sizeof(data)/sizeof(*data), sizeof(*data), compare);
    qsort (data, length, sizeof(int), compare);
}
void print(int *data,int length) {
    int i;
    for(i=0; i<length; i++) {
        printf(" %d",data[i]);
    }
    printf("\n");
}
/*client*/
int main() {
    int n;
    int a[N];
    scanf("%d",&n);
    int i;
    for(i=0; i<=N; i++) {
        counter[i]=0;
    }
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
        counter[a[i]]+=a[i];
    }
    int which[N+1];
    int number=0;
    for(i=N; i>=0; i--) {
        if(counter[i]!=0) {
            which[number]=i;
            number++;
        }
    }
    if(T) {
        for(i=0; i<number; i++) {
            printf(" %d",which[i]);
        }
        printf("\n");
        for(i=0; i<number; i++) {
            printf(" %d",counter[which[i]]);
        }
        printf("\n");
    }
    sort(which,number);

    if(T) {
        printf("-------------\n");
        for(i=0; i<number; i++) {
            printf(" %d",which[i]);
        }
        printf("\n");
        for(i=0; i<number; i++) {
            printf(" %d",counter[which[i]]);
        }
        printf("\n");
    }

    long long score=0;
    for(i=0; i<number; i++) {
        //这里还必须保证下表不出界！
        if(counter[which[i]]==0)continue;
        else  {
            if(which[i]-1>=0 && which[i]+1<=N && (counter[which[i]-1]+counter[which[i]+1]>counter[which[i]])) {
                score+=(long long)counter[which[i]+1];
                score+=(long long)counter[which[i]-1];
                counter[which[i]]=0;
                counter[which[i]+1]=0;
                if(which[i]+2<=N)counter[which[i]+2]=0;
                counter[which[i]-1]=0;
                if(which[i]-2>=0)counter[which[i]-2]=0;
            } else if(which[i]-1>=0 && which[i]+1<=N && (counter[which[i]-1]+counter[which[i]+1]==counter[which[i]])) {
		score+=(long long)counter[which[i]];
                if(which[i]-1>=0)counter[which[i]-1]=0;
                if(which[i]+1<=N)counter[which[i]+1]=0;


            } else {
                score+=(long long)counter[which[i]];
                if(which[i]-1>=0)counter[which[i]-1]=0;
                if(which[i]+1<=N)counter[which[i]+1]=0;
            }
        }
        if(T) {
            printf("----------------\n");
            int j;
            for(j=0; j<number; j++) {
                printf(" %d",which[j]);
            }
            printf("\n");
            for(j=0; j<number; j++) {
                printf(" %d",counter[which[j]]);
            }
            printf("\n");
        }
    }
    printf("%lld\n",score);
    return 0;
}
