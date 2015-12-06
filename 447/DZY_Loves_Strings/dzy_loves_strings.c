/*interface*/
#include<stdio.h>
#include<string.h>
#define N 1000
/*interface implementation*/
/*client*/
int main() {
    char s[N+1];
    scanf("%s",s);
    int k;
    scanf("%d",&k);
    int i;
    int max=0;
    int w[26];
    for(i=0; i<26; i++) {
        scanf("%d",&w[i]);
        if(w[i]>max) max=w[i];
    }
    int fs=0;
    int n_s=strlen(s);
    for(i=1; i<=n_s; i++) {
        fs+=i*w[s[i-1]-'a'];
    }
    //printf("%d\n",fs);
    fs+=max*(k*n_s+k*(k+1)/2);
    printf("%d\n",fs);
    return 0;
}
