/*interface*/
#include<stdio.h>
#include<string.h>
#define N 50+1
/*interface implementation*/
/*client*/
int main() {
    char s[N];
    scanf("%s",s);
    char t[N];
    scanf("%s",t);
    int ns=strlen(s);
    int nt=strlen(t);
    int i=0,j=0;
    while(i<ns && j<nt) {
        if(s[i]==t[j]) {
            i++;
            j++;
        } else {
            j++;
        }
    }
    printf("%d\n",i+1);

    return 0;
}
