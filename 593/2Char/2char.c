//一篇文章最多使用两个不同的字母！
//把出现次数最多的两个字母留下就可以！
/*interface*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
/*interface implementation*/
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    char article[100][1000+1];
    int i;
    int count[256];
    for(i=0; i<256; i++) {
        count[i]=0;
    }
    for(i=0; i<n; i++) {
        scanf("%s",article[i]);
        int length=strlen(article[i]);
	int j;
        for(j=0; j<length; j++) {
            count[(int)article[i][j]]++;
        }
    }
    int max=0;
    int max_i=0;
    for(i='a';i<='z';i++) {
	    if(count[i]>0)printf("%c count %d\n",i,count[i]);
    }
    for(i='a';i<='z';i++) {
	    if(count[i]>max) {
		    max=count[i];
		    max_i=i;
	    }
    }
    int second_max=0;
    for(i='a'; i<='z';i++) {
	    if(i==max_i)continue;
	    if(count[i]>second_max) {
		    second_max=count[i];
	    }
    }
    printf("%d\n",max+second_max);

    return 0;
}
