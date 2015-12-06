/*interface*/
#include<stdio.h>
/*interface implementation*/
/*client*/
int main() {
    char number[3];
    scanf("%s",number);
    int good[10];
    int digit[10][7];
    //只能用宏伟壮观来形容这个代码！
    digit[9][0]=1, digit[9][1]=1, digit[9][2]=1, digit[9][3]=1, digit[9][4]=0, digit[9][5]=1, digit[9][6]=1;
    digit[8][0]=1, digit[8][1]=1, digit[8][2]=1, digit[8][3]=1, digit[8][4]=1, digit[8][5]=1, digit[8][6]=1;
    digit[7][0]=1, digit[7][1]=1, digit[7][2]=1, digit[7][3]=0, digit[7][4]=0, digit[7][5]=0, digit[7][6]=0;
    digit[6][0]=1, digit[6][1]=0, digit[6][2]=1, digit[6][3]=1, digit[6][4]=1, digit[6][5]=1, digit[6][6]=1;
    digit[5][0]=1, digit[5][1]=0, digit[5][2]=1, digit[5][3]=1, digit[5][4]=0, digit[5][5]=1, digit[5][6]=1;
    digit[4][0]=0, digit[4][1]=1, digit[4][2]=1, digit[4][3]=0, digit[4][4]=0, digit[4][5]=1, digit[4][6]=1;
    digit[3][0]=1, digit[3][1]=1, digit[3][2]=1, digit[3][3]=1, digit[3][4]=0, digit[3][5]=0, digit[3][6]=1;
    digit[2][0]=1, digit[2][1]=1, digit[2][2]=0, digit[2][3]=1, digit[2][4]=1, digit[2][5]=0, digit[2][6]=1;
    digit[1][0]=0, digit[1][1]=1, digit[1][2]=1, digit[1][3]=0, digit[1][4]=0, digit[1][5]=0, digit[1][6]=0;
    digit[0][0]=1, digit[0][1]=1, digit[0][2]=1, digit[0][3]=1, digit[0][4]=1, digit[0][5]=1, digit[0][6]=0;
    int i,j,k;
    for(i=0; i<10; i++) {
        //printf("%d: ",i);
        int counter=0;
        for(j=0; j<10; j++) {
            int is_good=1;
            for(k=0; k<7; k++) {
                if(digit[i][k]==1 && digit[j][k]==0) {
                    is_good=0;
                    break;
                }
            }
            if(is_good) {
                //printf(" %d",j);
                counter++;
            }
        }
        //printf("\n");
        good[i]=counter;
    }
    //这是我总结出来的！
    //good[0]=2; good[1]=7; good[2]=2; good[3]=3; good[4]=3; good[5]=4; good[6]=2; good[7]=5; good[8]=1; good[9]=2;
    /*
    for(i=0; i<10; i++) {
        printf("good[%d]=%d\n",i,good[i]);
    }
    */
    printf("%d\n",good[number[0]-'0']*good[number[1]-'0']);
    return 0;
}
