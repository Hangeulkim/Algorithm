#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<deque>

using namespace std;
deque<char> input;
char tmp[30];
int main(){
    while(1){
        scanf("%s",tmp);
        if(tmp[0]=='#') break;
        int leng=strlen(tmp);
        int cnt=0;
        for(int i=0;i<leng;i++){
            if(tmp[i]=='a'||tmp[i]=='e'||tmp[i]=='i'||tmp[i]=='o'||tmp[i]=='u'){
                cnt=i;
                break;
            }
        }
        for(int i=cnt;i<leng;i++) printf("%c",tmp[i]);
        for(int i=0;i<cnt;i++) printf("%c",tmp[i]);
        printf("ay\n");
    }


    return 0;
}
