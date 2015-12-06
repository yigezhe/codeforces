//让我们来处理时间格式，就是考察你的分情况处理的能力！
/*interface*/
#include<stdio.h>
#define N 6
/*interface implementation*/
/*client*/
int main() {
    char current[N];
    char duration[N];
    //思路一，统一转化为秒，经过加减计算再由秒转化为时间！
    scanf("%s",current);
    scanf("%s",duration);
    int current_time=((current[0]-'0')*10+(current[1]-'0'))*60+
                     ((current[3]-'0')*10+(current[4]-'0'));
    //printf("%s = %d\n",current,current_time);
    int duration_time=((duration[0]-'0')*10+(duration[1]-'0'))*60+
                      ((duration[3]-'0')*10+(duration[4]-'0'));
    //printf("%s = %d\n",duration,duration_time);
    int sleep_time=current_time-duration_time;
    if(sleep_time<0) {
	    sleep_time=24*60+sleep_time;
    }
    char sleep[N];
    sleep[0]=(sleep_time/60)/10+'0';
    sleep[1]=(sleep_time/60)%10+'0';
    sleep[2]=':';
    sleep[3]=(sleep_time%60)/10+'0';
    sleep[4]=(sleep_time%60)%10+'0';
    sleep[5]='\0';
    //printf("%s = %d\n",sleep,sleep_time);
    printf("%s\n",sleep);

    return 0;
}
