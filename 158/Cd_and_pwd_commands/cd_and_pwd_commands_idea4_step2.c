//竞赛中的问题，还可以处理操作系统问题，
//不局限于数学问题，很好，这样一来我解决的问题越多，
//我的知识面就越广！
//现在看来我只在合适的时间参加比赛，其他时间就积极训练。
//我不追求参加比赛的次数，
//我如果训练扎实，我一次可以解决整个比赛的所有问题！
//这是我扎实训练的目标！
//我的一个想法是用一个字符串数组来处理目录！
//遇到／就整个取代
//遇到其他就直接添加到后面，
//之后再去调整！
/*interface*/
#include<stdio.h>
#include<string.h>
#define N 200*50+1//这是目录的最长名字！
#define D 200+1
char path[N];
int path_n=0;
//会不会有/home/../sis形式的命令，有，我就需要改变！
void adjust() {
    //用counter记录是不足够应付/a/b/../../c
    //我的办法是回头找！
    int i=0;
    while(i<path_n) {
        //printf("i=%d\n",i);
	//问题统一化处理就是遇到..时调整一次！
	//直至把所有的..都处理掉，我们就可以得到我们想要的结果！
        if(path[i]=='.') {
            //printf("before path n = %d\n",path_n);
            //回头找/
            //printf("i=%d\n",i);
            int back=i-2;
            //这里退了两步！
            //我让i直接后退了两步，这两步也应该算在path_n里！
            int counter=0;
            while(back>=0) {
                if(path[back]=='/') {
                    break;
                }
                back--;
                counter++;
                //这里多退一步！
            }
            back++;
            int postion_i=back;
            int front=i+1+1+1;//../b
            //printf("back=%d,front=%d,path n = %d\n",back,front,path_n);
            if(front>=path_n) {
                path[back-1]='\0';
            } else {
                while(1) {
                    //printf("back=%d,front=%d\n",back,front);
                    //if(path[front]=='\0' || front>=path_n) break;
		    //这里还要用到未改变的path_n!//我的提前改变影响了我想要的结果！
                    if(path[front]=='\0') break;
                    path[back]=path[front];
                    back++;
                    front++;
                }
                path[back]='\0';
                back++;
            }
            //printf("path = %s\n",path);
            i=postion_i;
            path_n-=3;//让path_n也适当减少！
            path_n-=counter;
            path_n--;//退两步与多退一步抵消就是再退一步！
            //printf("after path n = %d\n",path_n);
        } else {
            i++;
        }
    }
}
/*interface implementation*/
/*client*/
//没有从根目录返回父目录的情况出现！
//cd后面的目录都是存在的！
//两个／不能相邻出现！
//cd 后面的文件名不以／结尾！除非它是根目录！
//可以有相同的名字！
//我要建立一个树的结构，然后用查找树的方法来处理这个问题？
//但是我还没有掌握树，所以无法运用！
//
void get_line(char *line) {
    int i=0;
    while(1) {
        char ch=getchar();
        if(ch=='\n' || ch==EOF) {
            line[i]='\0';
            break;
        } else {
            line[i]=ch;
            i++;
        }
    }
}
int main() {
    int n;
    scanf("%d",&n);
    //printf("n=%d\n",n);
    getchar();
    char command[D];
    int i;
    for(i=0; i<n; i++) {
        get_line(command);
        //printf("%d: %s\n",i,command);
        if(strcmp(command,"pwd")==0) {


            //printf("path = ");
            printf("%s",path);
            //我觉得调整之后再添加这个，调整之前都没有最后的／
            //也不是调整之后，而是打印之前添加！//不要调整path_n,而是直接多打印一个/就可以！
            printf("/\n");
        } else {
            int j;
            //printf("command 3 = %c\n",command[3]);
            if(command[3]=='/') {
                path_n=0;
                for(j=3; command[j]!='\0'; j++) {
                    path[path_n]=command[j];
                    //printf("%c",command[j]);
                    path_n++;
                }
                path[path_n]='\0';
                //path_n++;//这个加加是多余的！
                //printf("those path n = %d\n",path_n);
            } else {
                //printf("before path n = %d\n",path_n);
                path[path_n]='/';
                path_n++;
                for(j=3; command[j]!='\0'; j++) {
                    path[path_n]=command[j];
                    //printf("%c",command[j]);
                    path_n++;
                }
                path[path_n]='\0';
                //printf("before path=%s\n",path);
                //printf("after path=%s\n",path);
                //printf("after path n = %d\n",path_n);
            }
	    //太棒了，这是我探索和创造出来的方法，编程给予了我成就感！
            adjust();
        }
    }
    return 0;
}
