/*interface*/
#include<stdio.h>
/*interface implementation*/
#define N 100
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    char room[N][N+1];
    int i,j,k;
    for(i=0; i<n; i++) {
        scanf("%s",room[i]);
    }
    int res=0;
    for(i=0; i<n; i++) {
        int all_one=1;
        for(j=0; j<n; j++) {
            if(room[i][j]=='0') {
                all_one=0;
                break;
            }
        }
        if(!all_one) {
            for(j=0; j<n; j++) {
                if(room[i][j]=='0') {
                    for(k=0; k<n; k++) {
                        if(room[k][j]=='0') room[k][j]='1';
                        else room[k][j]='0';
                    }
                }
            }
        }
        int counter=0;
        for(j=0; j<n; j++) {
            all_one=1;
            for(k=0; k<n; k++) {
                if(room[j][k]=='0') {
                    all_one=0;
                    break;
                }
            }
            if(all_one)counter++;
        }
        if(counter>res) res=counter;
    }
    printf("%d\n",res);
    return 0;
}
