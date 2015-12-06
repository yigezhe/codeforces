//compiled镶嵌进去！
//办法就是全部构建，删去重复项，然后统计一个总数就可以！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#include<string.h>
#define N 20+2
#define M 21*26
int main() {
    char s[N];
    scanf("%s",s);
    char photobook[M][N];
    int books=0;
    int n=(int)strlen(s);
    int i,j;
    for(i=0; i<=n; i++) {//20
        char add='a';
        while(add<='z') {//26
            char new_s[N];
	    strcpy(new_s,s);
            for(j=n; j>i; j--) {//20
                new_s[j]=new_s[j-1];
            }
            new_s[i]=add;
            new_s[n+1]='\0';
            //printf("%s\n",new_s);
            add++;

	    int find=0;
	    for(j=0;j<books;j++) {//21*26
		    if(strcmp(photobook[j],new_s)==0) {//21
			    find=1;
			    break;
		    }
	    }
	    if(!find) {
		    strcpy(photobook[books],new_s);
		    books++;
	    }
        }
    }
    //总的复杂度是20*26*21*26*21=5962320=10^6//可以在一秒之内完成！
    printf("%d\n",books);
    return 0;
}
