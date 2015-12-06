#include<stdio.h>
int main() {
    while(1) {
        char a,b,c;
        a=getchar();
        if(a==EOF) break;
        else {
            if(a=='W') {
                b=getchar();
                if(b==EOF) break;
                else {
                    if(b=='U') {
                        c=getchar();
                        if(c==EOF) break;
                        else {
                            if(c=='B') {
                            } else {
                                printf("%c%c%c",a,b,c);
                            }
                        }
                    } else {
                        printf("%c%c",a,b);
                    }
                }
            } else {
                printf("%c",a);
            }
        }
    }
    //printf("\n");//不需要
    return 0;
}
