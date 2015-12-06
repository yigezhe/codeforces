/*
 * File:   main.c
 * Author: khurshid
 *
 * Created on August 20, 2011, 9:26 AM
 */
/*
 *                  B. Spreadsheets
                    time limit per test: 10 seconds
                    memory limit per test: 64 megabytes
                    input: standard input
                    output: standard output


 * In the popular spreadsheets systems (for example, in Excel) the following numeration of columns is used.
 * The first column has number A, the second — number B, etc. till column 26 that is marked by Z.
 * Then there are two-letter numbers: column 27 has number AA, 28 — AB, column 52 is marked by AZ.
 * After ZZ there follow three-letter numbers, etc.


 * The rows are marked by integer numbers starting with 1.
 * The cell name is the concatenation of the column and the row numbers.
 * For example, BC23 is the name for the cell that is in column 55, row 23.


 * Sometimes another numeration system is used: RXCY, where X and Y are integer numbers,
 * showing the column and the row numbers respectfully. For instance, R23C55 is the cell from the previous example.


 * Your task is to write a program that reads the given sequence of cell coordinates and
 * produce each item written according to the rules of another numeration system.

 *
 * Input


 * The first line of the input contains integer number n (1 ≤ n ≤ 105),
 * the number of coordinates in the test. Then there follow n lines, each of them contains coordinates. All the coordinates are correct, there are no cells with the column and/or the row numbers larger than 106 .

 * Output


 * Write n lines, each line should contain a cell coordinates in the other numeration system.

 * Sample test(s)

 * Input                        Output
 * 2                            BC23
 * R23C55                       R23C55
 * BC23
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/*
 *
 */

#define MAX_STRING_LEN 50

//我佩服，这位作者自己建立了一个string数据类型，并且用得还很好！
typedef char String[MAX_STRING_LEN+1];
//String 实际应该是一个char* 吧！

//用预处理来写方程！
#define IsAlpha(x)   ( ( x ) >= 'A' && ( x ) <= 'Z' )
#define IsDigit(x)   ( ( x ) >= '0' && ( x ) <= '9' )
#define IsAlNum(x)   ( IsAlpha ( x ) || IsDigit ( x ) )

#define IN
#define OUT

typedef
int Bool_T;

#define true 1
#define false 0


void crash() {
	//作者自造了一个错误出现！
    int r = 0;
    printf("%d",0/r);
    exit(-1);
}

int intLength10( IN const int number ) {

    int r = 0;
    int locn = number;

    while( locn > 0 ) {
        r++;
        locn /= 10 ;
    }

    return r ;
}


int intLength26(IN const int number ) {
    int r = 0;
    int locn = number ;

    while( locn > 0) {
        r++;
        locn -- ;
        locn /=26 ;

    }

    return r ;
}

//ok，作者一定是写软件的，很规范！
void StrZero(String line) {
    int i;
    //最后一个也要被\0占领！
    for(i = 0; i <= MAX_STRING_LEN; i++) {
        line[i] ='\0';
    }
}


void readLine(String line) {
    int i = 0 ;
    //obnulit
    StrZero ( line ) ;
    //reading
    i = 0;
    //作者做出了最大程度的利用！
    while (i < MAX_STRING_LEN) {
        int c = getc(stdin);
        if (c=='\n' || c == EOF) {
            break;
        }

	//作者根据这个问题特制定了一下！
	//只读取大写字母以及数字！
        if ( IsAlNum ( c ) ) {
            line[i++] = c;
        }
    }
}//********* readLine *******************

size_t StrLength ( const String line ) {
    size_t i ;
    i = 0 ;
    while (i < MAX_STRING_LEN && line[i] > 0 ) {
        i++;
    }
    return i;
}


//ABCDXYZ
Bool_T isExcel(const String line) {
    int i;
    //first symbol must be a letter
    //对两种格式第一个字母都是字母！
    if ( ! IsAlpha(line[0]) ) {
        return false;
    }

    i = 1;
    while (i < MAX_STRING_LEN && IsAlpha(line[i])) {
        i++;
    }

    //这个都是字母！
    if (i >= MAX_STRING_LEN ) {
        return false;
    }


    //must be at least one digit
    if (!IsDigit(line[i])) {
        return false;
    }

    while (i < MAX_STRING_LEN && IsDigit(line[i])) {
        i++;
    }
    //对，把字母读完，把数字读完，就到了字母的结尾！

    return (line[i] == '\0') ? true : false;
}

int getColExcel(const String line) {
    int i =0;
    int r = 0;
    //把AA转换为整数！
    while (IsAlpha(line[i])) {
        const int d = line[i++]  - 'A' + 1;

        r = r * 26 + d;
    }


    return r;
}

int getRowExcel(const String line) {
    int i ;
    int r ;
    //skip all letters
    i = 0;
    while (IsAlpha(line[i])) {
        i++;
    }

    r = 0;
    while(IsDigit(line[i])) {
        r = r * 10 + (line[i++] - '0');
    }

    return r;
}




void buildExcel(int col, int row, String line) {
    int i;
    int j;
    int colLen      = intLength26 ( col ) ;
    int rowLen      = intLength10 ( row ) ;
    int totalLen    = colLen + rowLen ;
    int middleIndex = colLen ;

    StrZero(line);

    for(i = colLen-1; i>=0; i--) {
        col -- ;//我对这个有自己的探索！
        line[i] = (col%26) + 'A';
        col/=26;
    }

    for(i = totalLen - 1; i >= middleIndex; i--) {
        line[i] = (row % 10 + '0');
        row/=10;
    }

    line[totalLen] = '\0';

}

Bool_T isAExcel(const String line) {
    int i;
    int j;

    if (line[0] != 'R') {
        return false;
    }

    //寻找C！
    i = 1;
    while ( i < MAX_STRING_LEN && line[i]!='C') {
        i++;
    }
    //if not found
    //C不存在则i会跑到最大值！
    //|| line[i] != 'C') {这个检测没有作用！
    //在MAX上还可能是C，作者考虑太多了！这些细节没必要纠葛，而是放宽界限，来达到忽略这些问题的目的！
    if ( i>= MAX_STRING_LEN || line[i] != 'C') {
        return true;
    }

    //C和1之间应该都是数字！
    for(j = 1; j < i; j++) {
        if ( ! IsDigit( line[ j ] ) ) {
            return false ;
        }
    }
//line[j] > 0,不选用＝＝'\0'的原因？
    for(j = i + 1; j< MAX_STRING_LEN && line[j] > 0 ; j++) {
        if ( ! IsDigit(line[j]) ) {
            return false;
        }
    }
    return true;
}

int getColAExcel(const String line) {
    int i;
    int r;
    i = 0;
    while (i < MAX_STRING_LEN && line[i]!='C') {
        i++;
    }


    if (i >= MAX_STRING_LEN - 1 || line[i]!= 'C' )
        return -1;

    //skip 'C' letter
    i++;

    //calculate
    r = 0;
    while (i<MAX_STRING_LEN && IsDigit(line[i]) ) {
        r = r * 10 + (line[i++] - '0');
    }

    //return
    return r;
}


int getRowAExcel(const String line) {
    int i;
    int r;

    if (line[0] != 'R') {
        return -1;
    }
    //calculate
    i = 1;
    r = 0;
    while(i< MAX_STRING_LEN && IsDigit(line[i])) {
        r = r * 10 + (line[i++] - '0');
    }

    return r;
}


void buildAExcel(int col , int row, String line) {
    int i;
    const int colLen = intLength10(col);
    const int rowLen = intLength10(row);
    const int totalLen = colLen + rowLen + 2; //for 'R' and 'C'
    const int middleIndex = rowLen + 2;
    //我的天呀，作者写的太细致了！
    //R11C22
    //012345,
    //2+2+2
    //2+2=4,4是列的起点坐标！

    StrZero(line);

    line[0] = 'R';

    for(i = rowLen; i >= 1; i--) {
        line[i] = (row % 10 + '0');
        row/=10;
    }

    line[rowLen+1] = 'C';
    for (i = totalLen - 1; i >= middleIndex; i--) {
        line[i] = (col % 10 + '0');
        col /= 10;
    }

    line[totalLen] = 0;

}
//第一感觉就是写得太大了！

int main(int argc, char** argv) {
    int n;
    int i;
    scanf("%d\n",&n);
    for (i = 0; i<n; i++) {
        String line;
        readLine(line);

	//写得很有格式！
        if (isExcel(line)) {
            int col = getColExcel(line);
            int row = getRowExcel(line);

            buildAExcel(col, row, line);
            printf("%s\n", line);
        } else if (isAExcel(line)) {
            int col = getColAExcel(line);
            int row = getRowAExcel(line);
            buildExcel(col, row, line);
            printf("%s\n", line);
        } else {
            crash();
        }
    }
    return (EXIT_SUCCESS);
}
