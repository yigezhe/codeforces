//幸运数字问题已经出现好几次了！
//headphone头戴手机？
//我们需要对10^9以内的幸运数字进行排序？
//这个问题是有挑战性的！
//想法一，用内存还时间不行
//10^9的内存会占用1G
//从1一直计算到10^9，时间上处理太多！
//就是去生成所有的luckynumber！
/*interface*/
/*interface implementation*/
/*client*/

#include<stdio.h>
#include<string.h>
#define N 10+1
char lucky[N];
char digit[N];
int counter=0;
int ans;

void print(char *a,int n) {
    int i;
    for(i=0; i<n; i++) {
        printf(" %c",a[i]);
    }
    printf("\n");
}
//在一定深度下建立幸运数字！
void dfs(int pos,int deep) {
    if(pos==deep) {
        counter++;//依次统计幸运数字！
        //printf("counter=%d--",counter);
        //print(lucky,deep);
        //print(digit,deep);
        lucky[deep]='\0';
        if(strcmp(digit,lucky)==0) {
            ans=counter;
        }
        return;
    } else {
        lucky[pos]='4';
        dfs(pos+1,deep);
        lucky[pos]='0';
        lucky[pos]='7';
        dfs(pos+1,deep);
        lucky[pos]='0';
    }
}
void generate() {
    int i;
    for(i=1; i<N; i++) {
        //这是我业余学到的技术，在解决这个问题中用到了！
        //在每一个深度下找幸运数字！
        dfs(0,i);
    }
}
int main() {
    //以字母的形式读入整数，这里体现了很多创新和灵活处理！
    scanf("%s",digit);
    generate();
    //printf("digit=%s\n",digit);
    printf("%d\n",ans);
    return 0;
}
