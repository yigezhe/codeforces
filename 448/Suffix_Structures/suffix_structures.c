//太棒了，很出色地解决了问题！
#include<stdio.h>
#include<string.h>
int main() {
    char s[100+1];
    char t[100+1];
    scanf("%s",s);
    scanf("%s",t);
    int s_count[256];
    int t_count[256];
    int i,j;
    for(i=0; i<256; i++) {
        s_count[i]=0;
        t_count[i]=0;
    }
    int ns=strlen(s);
    int nt=strlen(t);
    for(i=0; i<ns; i++) {
        s_count[(int)s[i]]++;
    }
    for(i=0; i<nt; i++) {
        t_count[(int)t[i]]++;
    }
    int more=0;
    int less=0;
    for(i='a'; i<='z'; i++) {
        if(s_count[i]<t_count[i]) less=1;
        else if(s_count[i]>t_count[i]) more=1;
    }
    int within=0;
    i=0,j=0;
    while(i<ns && j<nt) {
        if(s[i]==t[j]) {
            i++;
            j++;
        } else {
            i++;
        }
    }
    //printf("j = %d\n",j);
    if(j==nt)within=1;
    if(!more && !less) {
        if(within==1)
            printf("need tree\n");
        //s,t is same and can't swap and delete.
        else
            printf("array\n");//s,t have same length, and s don't contain t,so we can only swap them to change s to t;
    } else if(less) {
        printf("need tree\n");//s don't have enough chars to delete to t or swap to t;
    } else if(more) {
        if(within==0)
            printf("both\n");//more and not within,so we should delete more words and swap wrong order chars;
        else
            //we can only use delete to get t,because s contains t;
            printf("automaton\n");
    }
    return 0;
}
