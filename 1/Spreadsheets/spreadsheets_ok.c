//不可思议，我没有测试中间会不会出问题，直接按想法把代码写出来了！
#include<stdio.h>
#define N 10000
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
        //printf("first=%d\n",first);
        int num=A2n(s[i]);
        first=first*26+num;
    }
    return first;
}
void n2AA(int n,char* AA,int* size) {
    while(1) {
        int a=n%26;
        if(a>0) {
            int i;
            //其它字符后移！
            for(i=(*size); i>0; i--) {
                *(AA+i)=*(AA+i-1);
            }
            //添加这个字符！
            AA[0]=a-1+'A';
            (*size)++;
            AA[*size]='\0';
        } else {
            int i;
            //其它字符后移！
            for(i=(*size); i>0; i--) {
                *(AA+i)=*(AA+i-1);
            }
            //添加这个字符！
            AA[0]='Z';
            (*size)++;
            AA[*size]='\0';

            n=n-26;
        }
        n=n/26;
        if(n==0) break;
    }
}
int which_way(char* coor) {
    int i;
    int first=0;
    int second=0;
    int third=0;
    for(i=0; coor[i]!='\0'; i++) {
        if(coor[i]>='A'&&coor[i]<='Z') {
            first=1;
        }
        if(first) {
            if(coor[i]>='0'&&coor[i]<='9') {
                second=1;
            }
        }
        if(second) {
            if(coor[i]>='A'&&coor[i]<='Z') {
                third=1;
            }
        }
    }
    //1 for R23C55
    if(third==1) {
        return 1;
    }
    //2 for BC3
    else {
        return 2;
    }
}
int main() {
    int n;
    scanf("%d",&n);
    int i,j,k;
    char coor[N];
    for(i=0; i<n; i++) {
        scanf("%s",coor);
        if(which_way(coor)==2) {
            //分离出字幕部分与数字部分！
            char col_str[N];
            int row=0;
            int ci=0;
            for(j=0; coor[j]!='\0'; j++) {
                if(coor[j]>='A'&&coor[j]<='Z') {
                    col_str[ci]=coor[j];
                    ci++;
                } else {
                    break;
                }
            }
            //j之前是字符，之后都是数字！
            for(k=j; coor[k]!='\0'; k++) {
                row=row*10+coor[k]-'0';
            }


            col_str[ci]='\0';
            int col=AA2n(col_str);
            printf("R%dC%d\n",row,col);

        } else {
            int row=0;
            int col=0;
            //跳过第一个R
            for(j=1; coor[j]!='\0'; j++) {
                //一遇到字母就停止！
                if(coor[j]>='A'&&coor[j]<='Z') {
                    break;
                } else {
                    row=row*10+coor[j]-'0';
                }
            }
            for(k=j+1; coor[k]!='\0'; k++) {
                col=col*10+coor[k]-'0';
            }
            char col_str[N];
            int size=0;
            col_str[size]='\0';
            n2AA(col,col_str,&size);
            printf("%s",col_str);
            printf("%d\n",row);
        }
    }
    return 0;
}
