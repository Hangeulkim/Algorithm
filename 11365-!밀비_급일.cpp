#include<cstdio>
#include<cstring>

using namespace std;

int main(){
    char input[1004];

    while(1){
        scanf(" %[^\n]s",input);
        if(strcmp(input,"END")==0) break;
        for(int i=strlen(input)-1;i>=0;i--) printf("%c",input[i]);
        printf("\n");
    }

    return 0;
}
