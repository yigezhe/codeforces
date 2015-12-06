/*interface*/
#include<stdio.h>
#include<string.h>
#define S 1000
#define N 256
/*interface implementation*/
/*client*/
int main() {
    int k;
    scanf("%d",&k);
    char s[S+1];
    scanf("%s",s);
    int count[N+1];
    int i;
    int n_s=strlen(s);
    for(i=0; i<=N; i++) {
        count[i]=0;
    }
    for(i=0; i<n_s; i++) {
        count[(int)s[i]]++;
    }
    for(i=0; i<N; i++) {
        if(count[i]%k!=0) {
            printf("-1\n");
            return 0;
        }
    }
    for(i=0; i<N; i++) {
        count[i]=count[i]/k;
    }
    int j,h;
    for(h=0; h<k; h++) {
        for(i=0; i<N; i++) {
            for(j=0; j<count[i]; j++) {
                printf("%c",(char)i);
            }
        }
    }
    printf("\n");
    return 0;
}
