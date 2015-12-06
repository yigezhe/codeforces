//llya是一个狮子！
//IT信息技术考试！
//queries请求访问！
//以帮助为借口，让程序员解决这个问题，这只是建立解决这个问题的必要性！
//问题越重要越需要解决！
//想法一，就是实现，但是复杂度将是10^10级别。
//想法二，建立一个数组，从后往前计算相同项，
//然后从前往后，只要统计数大于二，就说明后面有相同项！
//我的程序越来越有创造性了，加油！
//query片段！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 100000+1
int main() {
    char s[N];
    scanf("%s",s);
    int m;
    scanf("%d",&m);
    int i;
    for(i=0; i<m; i++) {//10^5
        int l,r;
        scanf("%d%d",&l,&r);
	l--;
	r--;
	//保证l，r是从零开始的！
        int j;
        int counter=0;
        for(j=l; j<r; j++) {//10^5
            if(s[j]==s[j+1]) {
                counter++;
            }
        }
        printf("%d\n",counter);
    }

    return 0;
}
