/*interface*/
//整个程序写得太漂亮了，太棒了！
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#define M 100000//这个长度的数组我的计算机无法给予！
/*interface implementation*/
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    //printf("n = %d\n",n);
    int m=51;
    char **f;
    char **s;
    //这个问题让我不得不使用动态数组，不然我无法读取整个字符串数组！
    f=(char**)malloc(n*sizeof(char*));
    int i;
    for(i=0; i<n; i++) {
        f[i]=(char*)malloc(m*sizeof(char));
    }
    s=(char**)malloc(n*sizeof(char*));
    for(i=0; i<n; i++) {
        s[i]=(char*)malloc(m*sizeof(char));
    }
    getchar();
    for(i=0; i<n; i++) {
        scanf("%s%s",f[i],s[i]);
        //printf("f = %s,s = %s\n",f[i],s[i]);
    }
    //这里统一练习一下动态数组！
    int *p;
    p=(int *)malloc(n*sizeof(int));
    for(i=0; i<n; i++) {
        scanf("%d",&p[i]);
        p[i]--;
        //printf("p[%d] = %d\n",i,p[i]);
    }
    int is_ok=1;
    for(i=0; i<n-1; i++) {
        int change=0;
        if(strcmp(f[p[i]],f[p[i+1]])<0 || strcmp(s[p[i]],f[p[i+1]])<0) {
            //不做出改变，保留！
        } else {
            f[p[i+1]][0]='{';
            f[p[i+1]][1]='\0';
            change++;
        }
        if(strcmp(f[p[i]],s[p[i+1]])<0 || strcmp(s[p[i]],s[p[i+1]])<0) {
            //不做出改变，保留！
        } else {
            s[p[i+1]][0]='{';
            s[p[i+1]][1]='\0';
            change++;
        }
        if(change==2) {
            is_ok=0;
            break;
        }
    }
    if(is_ok) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    for(i=0; i<n; i++) {
        free(f[i]);
        free(s[i]);
    }
    free(f);
    free(s);

    return 0;
}
