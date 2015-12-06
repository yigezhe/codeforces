//我尝试一下暴力搜索！
#include<stdio.h>
#define N 50
int is_face(char face[][2]) {
    int f=0,a=0,c=0,e=0;
    int i,j;
    for(i=0; i<2; i++) {
        for(j=0; j<2; j++) {
            if(face[i][j]=='f') {
                f++;
            } else if(face[i][j]=='a') {
                a++;
            } else if(face[i][j]=='c') {
                c++;
            } else if(face[i][j]=='e') {
                e++;
            } else {
                return 0;
            }
        }
    }
    if(f==1 && a==1 && c==1 && e==1) {
        return 1;
    } else {
        return 0;
    }
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int i,j;
    char picture[N][N];
    getchar();//把读取数字后残余的回车自动读取，不做任何处理！
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            char a=getchar();
            picture[i][j]=a;
        }
        getchar();//把每一行后的回车自动读取，不做任何处理！
    }
    /*
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            printf("%c",picture[i][j]);
        }
        printf("\n");
    }
    */

    char face[2][2];
    int count=0;
    for(i=0; i<n-1; i++) {
        for(j=0; j<m-1; j++) {
            face[0][0]=picture[i][j];
            face[0][1]=picture[i][j+1];
            face[1][0]=picture[i+1][j];
            face[1][1]=picture[i+1][j+1];

            //printf("\n%c%c\n",face[0][0],face[0][1]);
            //printf("%c%c\n",face[1][0],face[1][1]);
            if(is_face(face)) {
                count++;
            }
        }
    }
    printf("%d\n",count);
    return 0;
}
