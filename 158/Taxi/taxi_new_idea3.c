#include<stdio.h>
int main() {
    int n=0;
    int i;
    int people[5];
    for(i=0; i<5; i++) {
        people[i]=0;
    }
    scanf("%d",&n);
    //printf("res=%d\n",re);
    for(i=0; i<n; i++) {
        int m=0;//必须为m赋予初值，否则，编译器会处理错误？
        scanf("%d",&m);
        //printf("%2d",m);
        people[m]++;
    }
    /*
    printf("\n");
    for(i=0; i<5; i++) {
        printf("%d:%d\n",i,people[i]);
    }
    */

    int count=0;
    count=count+people[4];

    count=count+people[3];
    people[1]=people[1]-people[3];
    //这可能使people［1］变为负值但没关系！
    count=count+people[2]/2;
    people[2]=people[2]-(people[2]/2)*2;

    //这里people［2］可能是零也可能是一，下面的代码都可以处理！
    count=count+people[2];
    people[1]= people[1]-2*people[2];

    if(people[1]>0) {
        count=count+people[1]/4;
        people[1]= people[1]-4*(people[1]/4);
    }
    //printf("%d\n",count);
    if(people[1]>0) count++;
    //我觉得这个算是简洁漂亮的！
    //看来b类问题已经在发挥我的创造力了！
    printf("%d\n",count);
    return 0;
}
