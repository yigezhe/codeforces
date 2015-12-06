//竞赛中的问题，还可以处理操作系统问题，
//不局限于数学问题，很好，这样一来我解决的问题越多，
//我的知识面就越广！
//现在看来我只在合适的时间参加比赛，其他时间就积极训练。
//我不追求参加比赛的次数，
//我如果训练扎实，我一次可以解决整个比赛的所有问题！
//这是我扎实训练的目标！
//我的一个想法是用一个字符串数组来处理目录！
/*interface*/
#include<stdio.h>
#include<string.h>
#define N 200*50+1//这是目录的最长名字！
#define D 200+1
char path[N];
int path_n=0;
int position[N];
int position_n=0;
void print_path() {
    int i;
    for(i=0; i<position_n; i++) {
        printf(" %d",position[i]);
    }
    printf("\n");
    //printf("here\n");
    printf("%s\n",path);
}
//会不会有/home/../sis形式的命令，有，我就需要改变！
void change_path(char *directory) {
    printf("change path directory=%s\n",directory);
    //先分离目录!
    //我的目录可以保存／,也可以不保存／
    char each[N][N];
    int each_n=0;
    int each_m=0;
    int i=0;
    int is_absolute=0;
    if(directory[0]=='/') {
        is_absolute=1;
    }
    while(1) {
        if(directory[i]=='\0') {
            each[each_n][each_m]='\0';
            each_n++;
            //each_m=0;
            //i++;
            break;

        } else if(directory[i]=='/') {
            each[each_n][each_m]='\0';
            each_n++;
            each_m=0;
            i++;
        } else {
            each[each_n][each_m]=directory[i];
            each_m++;
            i++;
        }
    }
    for(i=0; i<each_n; i++) {
        printf("%s\n",each[i]);
    }
    for(i=0; i<each_n; i++) {
        if(is_absolute) {
            position_n=0;
            is_absolute=0;
        }
        if(each[i][0]=='.') {
            position_n--;
        } else {
            if(each[i][0]!='\0') {
                int j;
                for(j=position[position_n]; j<position[position_n]+(int)strlen(each[i]); j++) {
                    path[path_n]=each[i][j];
                    path_n++;
                }
                position[position_n]=j;
                position_n++;
            }
        }
    }
    path[path_n]='\0';
    path_n++;

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
    printf("n=%d\n",n);
    getchar();
    char command[D];
    char directory[D];
    int i;
    position[0]=0;
    path[0]='\0';
    for(i=0; i<n; i++) {
        get_line(command);
        printf("%d: %s\n",i,command);
        if(strcmp(command,"pwd")==0) {
            printf("path = ");
            print_path();
        } else {
            int k=0;
            int j;
            for(j=3; command[j]!='\0'; j++) {
                directory[k]=command[j];
                k++;
            }
            directory[k]='\0';
            printf("directory=%s\n",directory);
            change_path(directory);
        }
    }
    return 0;
}
