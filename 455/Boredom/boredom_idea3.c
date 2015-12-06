#include<stdio.h>
#define N 100000
/*interface*/
/*interface implementation*/
/*client*/
int main() {
    int n;
    int a[N];
    scanf("%d",&n);
    int i;
    int counter[N+1];
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
    /*
    for(i=0; i<number; i++) {
        printf(" %d",which[i]);
    }
    printf("\n");
    for(i=0; i<number; i++) {
        printf(" %d",counter[which[i]]);
    }
    printf("\n");
    */

    int j;
    for (i = 0; i < number; i++) {
        for (j = 0; j < number-1; j++) {
            if (counter[which[j]] < counter[which[j + 1]]) {
                int tmp = which[j];
                which[j] = which[j + 1];
                which[j + 1] = tmp;
            }
        }
    }
    /*
    printf("-------------\n");
    for(i=0; i<number; i++) {
        printf(" %d",which[i]);
    }
    printf("\n");
    for(i=0; i<number; i++) {
        printf(" %d",counter[which[i]]);
    }
    printf("\n");
    */

    long long score=0;
    for(i=0; i<number; i++) {
        if(counter[which[i]]==0)continue;
        if(counter[which[i]-1]+counter[which[i]+1]>=counter[which[i]]) {
            score+=counter[which[i]+1];
            counter[which[i]]=0;
            counter[which[i]+1]=0;
        } else {
            score+=counter[which[i]];
            counter[which[i]-1]=0;
            counter[which[i]+1]=0;
        }
	/*
        printf("----------------\n");
        for(j=0; j<number; j++) {
            printf(" %d",which[j]);
        }
        printf("\n");
        for(j=0; j<number; j++) {
        printf(" %d",counter[which[j]]);
        }
        printf("\n");
	*/
    }

    printf("%lld\n",score);


    return 0;
}
