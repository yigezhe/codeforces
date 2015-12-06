//好复杂的故事！
//穿越房子计划！
/*interface*/
/*interface implementation*/
#define N 256
/*client*/
int can_open(char a,char b) {
    if(a-'a'==b-'A')
        return 1;
    else
        return 0;
}
#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int i;
    getchar();
    int stored_key[N];
    for(i=0; i<N; i++) {
        stored_key[i]=0;
    }
    int buy=0;
    for(i=0; i<n-1; i++) {
        char key=getchar();
        char door=getchar();
        //很棒，这样的显示，让问题有了一个很清晰的解答！
        //printf("%c %c\n",key,door);
        if(!can_open(key,door)) {
		//逻辑结构要正确，不能打开门的钥匙，
		//就可以立刻保存，而不是到分支情况去保存！
		stored_key[(int)key]++;
            char needed_key=door-'A'+'a';
            if( stored_key[(int)needed_key]>0) {
                stored_key[(int)needed_key]--;
            } else if( stored_key[(int)needed_key]==0) {
                buy++;
                //printf("stored %c open %c\n",needed_key,door);
            } else {
                printf("出现了其他问题\n");
            }
        } else {
            //printf("%c open %c\n",key,door);
        }
    }
    printf("%d\n",buy);
    return 0;

}
