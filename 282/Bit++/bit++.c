#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int final_x=0;
    int i;
    for(i=0;i<n;i++) {
        char operation[4];
        scanf("%s",operation);
	//我选取中间值做为判别标准！
	//c语言更关注细节处！
        if(operation[1]=='+') {
            final_x++;
        } else {
            final_x--;
        }
    }
    printf("%d\n",final_x);
    return 0;
}
