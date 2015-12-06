#include<stdio.h>
#define N 200001
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    //printf("n=%d,m=%d\n",n,m);
    char name[N];
    scanf("%s",name);
    getchar();//remove newline
    char change[256];
    int i;
    for(i='a'; i<='z'; i++) {
        change[(int)i]=i;
    }
    for(i=0; i<m; i++) {
        char x,y;
        scanf("%c %c",&x,&y);
        //printf("x=%c,y=%c\n",x,y);
        getchar();//remove newline
        int j;
        int xx='a';
        for(j='a'; j<='z'; j++) {
            if(change[(int)j]==x) {
                xx=j;
                break;
            }
        }
        int yy='a';
        for(j='a'; j<='z'; j++) {
            if(change[(int)j]==y) {
                yy=j;
                break;
            }
        }
	//这里不能提前操作，而是要事后操作！
        change[xx]=y;
        change[yy]=x;
	/*
        for(j='a'; j<='z'; j++) {
            if(change[j]!=j) printf("%c->%c, ",j,change[(int)j]);
        }
        printf("\n");
	*/
    }
    /*
    for(i='a'; i<='z'; i++) {
        if(change[i]!=i) printf("%c->%c, ",i,change[(int)i]);
    }
    printf("\n");
    */

    for(i=0; i<n; i++) {
        name[i]=change[(int)name[i]];
    }
    printf("%s\n",name);
    return 0;
}
