//白方是大写，黑方是小写
//queen Q 9
//rook R 5
//bishop B 3
//knight N 3
//pawn P 1
//king K 0
//每一个子任意多，王可能被攻击！
//读题时，记录一些重要信息！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 256
int main() {
    int w[N];
    int i;
    for(i=0; i<N; i++) {
        w[i]=0;
    }
    w['Q']=9,w['q']=9;
    w['R']=5,w['r']=5;
    w['B']=3,w['b']=3;
    w['N']=3,w['n']=3;
    w['P']=1,w['p']=1;
    w['K']=0,w['k']=0;
    int white_weight=0;
    int black_weight=0;
    while(1) {
        char ch=getchar();
        if(ch==EOF) break;
        else if(ch != '\n') {
            if(ch>='A' && ch<='Z') white_weight+=w[(int)ch];
            if(ch>='a' && ch<='z') black_weight+=w[(int)ch];
        }
    }
    //printf("white weight is %d\n",white_weight);
    //printf("black weight is %d\n",black_weight);
    if(black_weight>white_weight) {
        printf("Black\n");
    } else if(black_weight<white_weight) {
        printf("White\n");
    } else {
        printf("Draw\n");
    }
    return 0;
}
