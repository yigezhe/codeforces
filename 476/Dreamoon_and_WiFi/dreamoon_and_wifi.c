/*interface*/
#include<stdio.h>
#include<string.h>
#define N 10
/*interface implementation*/
int counter,total;
int c12,question;
void rec(int deep,int value) {
    //printf("rec(%d,%d)\n",deep,value);
    if(deep==question) {
        //printf("value=%d\n",value);
        if(c12==value) counter++;
        total++;
        return;
    }
    rec(deep+1,value+1);
    rec(deep+1,value-1);
}
/*client*/
int main() {
    char s1[N+1];
    char s2[N+1];
    scanf("%s",s1);
    scanf("%s",s2);
    int n1=strlen(s1);
    int n2=strlen(s2);
    int c1=0,c2=0;
    int i;
    for(i=0; i<n1; i++) {
        if(s1[i]=='+') c1++;
        else if(s1[i]=='-')c1--;
    }
    question=0;
    for(i=0; i<n2; i++) {
        if(s2[i]=='+') c2++;
        else if(s2[i]=='-')c2--;
        else question++;
    }
    //printf("question=%d\n",question);
    c12=c1-c2;
    //printf("c12=%d\n",c12);
    counter=0;
    total=0;
    rec(0,0);
    double res;
    if(question==0) {
        if(c1==c2) res=1.0;
        else res=0.0;
    } else res=(1.0*counter)/(1.0*total);
    printf("%.12f\n",res);
    return 0;
}
