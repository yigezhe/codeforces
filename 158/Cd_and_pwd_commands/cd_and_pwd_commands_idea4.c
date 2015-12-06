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
    int counter=0;
    int parent=0;
    int i=0;
    while(i<path_n) {
	    //printf("i=%d\n",i);
        if(path[i]=='/') {
            parent=counter;//纪录前一个目录的长度！
            counter=0;
            i++;
        } else if(path[i]=='.') {
            counter=0;
	    printf("parent = %d\n",parent);
            int j;
            for(j=i-1-parent;; j++) {
                if(path[j+counter+5]=='\0') {
                    path[j]=path[j+counter+5];
		    path_n=path_n-counter-5+1;
                    break;
                } else {
                    path[j]=path[j+counter+5];
                }
            }
            i+=3;
        } else {
            counter++;
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
    path[0]='/';
    path[1]='\0';
    path_n=1;
    for(i=0; i<n; i++) {
        get_line(command);
        //printf("%d: %s\n",i,command);
        if(strcmp(command,"pwd")==0) {
            //printf("path = ");
            printf("%s\n",path);
        } else {
            int j;
                //printf("3=%c",command[3]);
            if(command[3]=='/') {
                path_n=0;
            }
            for(j=3; command[j]!='\0'; j++) {
                path[path_n]=command[j];
                //printf("%c",command[j]);
                path_n++;
            }
            path[path_n]='/';
            path_n++;
            path[path_n]='\0';
            path_n++;
            //printf("before path=%s\n",path);
            adjust();
            //printf("after path=%s\n",path);
        }
    }
    return 0;
}
