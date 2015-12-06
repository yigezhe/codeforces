//正在理解中！
#include <stdio.h>
#include <string.h>

int ipow(int base, int exp) {
    int result = 1;
    while (exp) {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

char word[16], tmp[8];
char c;


int main() {
    int n;
    scanf("%d\n", &n);
    //这样做可以节省多余的变量！
    while (n--) {
        short len = 0;
        short mid = 0;
        short dt = 0;

	//读取一行后处理！
        while ((c = getchar()) != '\n') {
            word[len++] = c;
	    //出现数字！
	    //dt纪录的就是出现数字的下一个位置！
            if (c >= '0' && c <= '9') {
                if (mid == 0 && dt == 0) dt = len;
            } else {
		    //第一次统计到了数字！
		    //第二次再统计到数字,纪录下数字出现的位置的下一位！
                if (dt > 0 && mid == 0) {
                    mid = len;
                }
            }
        }
	//这样一来，有mid就是第二种格式，无mid就是第一种格式！
        word[len] = '\0';

	printf("dt=%d,mid=%d\n",dt,mid);

	//我必须看一下对于mid和dt的统计！
        if (mid) {
            //RXCY
            short index = mid;

            int a = 0;

            while (len != index) {
                a = a * 10 + (word[index] - '0');
                index++;
            }

            a -= 1;

            index = 0;

            while (a >= 0) {
                tmp[index] = 'A' + a % 26;
                a = (a / 26) - 1;
                index++;
            }

            while (index > 0) {
                index--;
                putchar(tmp[index]);
            }
            index = 1;


            while (index != mid - 1) {
                putchar(word[index]);
                index++;
            }
            putchar('\n');
        } else {
            //CD
            putchar('R');
            dt -= 1;
            int dmp = dt;

            while (dt != len) {
                putchar(word[dt]);
                dt++;
            }

            short index = 0;
            int r = 0;

            while (index != dmp) {
                r += (word[index] - 'A' + 1) * (ipow(26, dmp - (++index))); // + 1e-9
            }

            printf("C%d\n", r);
        }
    }

    return 0;
}
