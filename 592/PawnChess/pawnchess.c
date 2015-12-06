#include<stdio.h>
int main() {
    char board[8][8];
    int i,j;
    for(i=0; i<8; i++) {
        for(j=0; j<8; j++) {
            board[i][j]=getchar();
        }
        getchar();//read newline
    }
    /*
    for(i=0; i<8; i++) {
        for(j=0; j<8; j++) {
            printf("%c",board[i][j]);
        }
        printf("\n");
    }
    */

    int white_step=8;
    int find=0;
    int row=0;
    int move[8];
    for(i=0; i<8; i++) {
        move[i]=1;
    }
    while(!find && row<8) {
        //printf("row = %d\n",row);
        int col;
        for(col=0; col<8; col++) {
            if(board[row][col]=='B') move[col]=0;
            else if(board[row][col]=='W' && move[col]==1) {
                find=1;
                white_step=row;
                break;
            }
        }
	/*
        for(col=0; col<8; col++) {
            printf(" %d",move[col]);
	}
	printf("\n");
	*/

        row++;
    }
    int black_step=8;
    find=0;
    row=7;
    for(i=0; i<8; i++) {
        move[i]=1;
    }
    while(!find && row>=0) {
        int col;
        for(col=0; col<8; col++) {
            if(board[row][col]=='W') move[col]=0;
            else if(board[row][col]=='B' && move[col]==1) {
                find=1;
                black_step=8-row;
                break;
            }
        }
        row--;
    }
    /*
    printf("white step = %d\n",white_step);
    printf("black step = %d\n",black_step);
    */
    if(white_step<black_step) {
        printf("A\n");
    } else {
        printf("B\n");
    }
    return 0;
}
