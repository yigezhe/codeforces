//
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 300000+1
int n,m;
int count(char *s) {
    int i;
    int res=0;
    for(i=0; i<n; i++) {
        int counter=0;
        while(i<n && s[i]!='\0' && s[i]=='.') {
            i++;
            counter++;
        }
        if(counter>0) {
            res+=(counter-1);
        }
    }
    return res;
}
int main() {
    scanf("%d%d",&n,&m);
    char s[N];
    scanf("%s",s);
    int i;
    for(i=0; i<m; i++) {
        int where;
        char which;
        scanf("%d %c",&where,&which);
        s[where-1]=which;
        printf("%d\n",count(s));
    }
    return 0;
}
