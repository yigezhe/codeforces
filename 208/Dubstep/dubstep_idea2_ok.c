#include<stdio.h>
#include<string.h>
#define N 200+1

//读入数组后擦除！
int main() {
    char song[N];
    scanf("%s",song);
    int n=strlen(song);
    int i=0;
    int j=0;
    char origin[N];
    while(song[i]!='\0') {
        if(i+2<=n-1 && song[i]=='W' && song[i+1]=='U' && song[i+2]=='B') {
            if(j!=0) {
                if(origin[j-1]!=' ') {
                    origin[j]=' ';
                    j++;
                }
            }
            i+=3;
        } else {
            origin[j]=song[i];
            j++;
            i++;
        }
    }
    origin[j]='\0';
    //printf("%s\n",origin);
    i=0;
    while(origin[i]!='\0') {
        //if(origin[i]==' ') printf("*");
        //else printf("%c",origin[i]);
        i++;
    }
    //printf("\n");
    //去掉尾部的空格！
    j=i-1;
    while(j>=0) {
        if(origin[j]==' ') origin[j]='\0';
        else break;
        j--;
    }

    printf("%s\n",origin);
    /*
    i=0;
    while(origin[i]!='\0') {
        if(origin[i]==' ') printf("*");
        else printf("%c",origin[i]);
        i++;
    }
    printf("\n");
    */


    return 0;
}
