//submit ok!
#include <stdio.h>
int main() {
	// (1 ≤ w ≤ 100)
	// 分割成两个偶数，两个偶数相等也可以！
	// 除过2的所有偶数都是满足条件的！
    int weight;
    scanf("%d",&weight);
    if(weight%2==0&&weight!=2)
        printf("YES");
    else
        printf("NO");

    return 0;
}
