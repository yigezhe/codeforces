#include<stdio.h>
int A2n(char a) {
    if(a>='A' && a<='Z') return a-'A'+1;
    else return 0;
}
char n2A(int n) {
    if(n>=1 && n<=26) return n+'A'-1;
    else return ' ';
}
char n2As(int n) {
    if(n>=0 && n<=25) return n+'A';
    else return ' ';
}

//这应该是26进制！

int AA2n(char* s) {
    int i;
    int first=A2n(s[0]);
    for(i=1; s[i]!='\0'; i++) {
        printf("first=%d\n",first);
        int num=A2n(s[i]);
        first=first*26+num;
    }
    return first;
}
//这个转换遇到阻碍！
void n2AA(int n,char* s) {
	n=n-1;
    while(n>0) {
	    printf("%d~",n);
	    int num=n%26;
        char last=n2As(num);
        n=n/26;
	    printf("%c: %d|",last,n);
    }
    printf("\n");
}


int main() {
    //A~Z,1~26
    //AA~AZ,27~52=26+1~26+26
    //BA~BZ,53~52=26+26+1~26+26+26
    int i;
    /*
    for(i=0; i<26; i++) {
        char a=i+'A';
        printf("%c: ",a);
        printf("%d\n",A2n(a));
    }
    for(i=0; i<26; i++) {
        printf("%d: ",i+1);
        printf("%c\n",n2A(i+1));
    }
    */

    /*
    char s[3];
    //s[0]='A';s[1]='A';
    //s[0]='A';s[1]='B';
    s[0]='A';
    s[1]='Z';
    s[2]='\0';
    printf("%s: %d\n",s,AA2n(s));
    */
    char s[100];
    int n;
    for(n=1;n<=52;n++) {
	n2AA(n,s);
    }

    return 0;
}
