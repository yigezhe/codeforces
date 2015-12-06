//思路是看一下杯子最多占用多少个椅子，牌子最多占用多少个椅子
//两者相加后的和小于等于n就打印yes，否则打印no！
#include<stdio.h>
int main() {
    int cups=0;
    int i;
    for(i=0; i<3; i++) {
        int a;
        scanf("%d",&a);
        cups+=a;
    }
    int medals=0;
    for(i=0; i<3; i++) {
        int b;
        scanf("%d",&b);
        medals+=b;
    }
    int n;
    scanf("%d",&n);
    int cup_shelf=cups/5;
    if(cups%5!=0) cup_shelf++;
    int medal_shelf=medals/10;
    if(medals%10!=0) medal_shelf++;
    if(cup_shelf+medal_shelf<=n) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
