//三个棒的总增加长度是l还是每一个棒都可以增加l！
/*interface*/
/*interface implementation*/
/*client*/
int is_triangle(int a,int b,int c) {
	if(a+b>c && a+c>b && b+c>a) return 1;
	else return 0;
}
#include<stdio.h>
int main() {
    int a,b,c,l;
    scanf("%d%d%d%d",&a,&b,&c,&l);
    //a可以不增到增加l有3*10^5的选择！
    //b可以不增到增加l有3*10^5的选择！
    //c可以不增到增加l有3*10^5的选择！
    //这种情况下的复杂度是27*10^15!
    //满足x+y+z=l的组合应该有多少种？
    //满足x+y+z<=l的组合应该有多少种?
    int la,lb,lc;
    int counter=0;
    for(la=0; la<=l; la++) {
        for(lb=0; lb<=l; lb++) {
            if(la+lb<=l) {
                for(lc=0; lc<=l; lc++) {
                    if(la+lb+lc<=l) {
                        if(is_triangle(a+la,b+lb,c+lc)) {
                            counter++;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",counter);
    return 0;
}
