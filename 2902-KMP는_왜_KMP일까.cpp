#include<cstdio>
#include<cstring>

using namespace std;

int main(){
    char input[1004];
    scanf("%[^\n]s",input);
    printf("%c",input[0]);
    for(int i=1;i<strlen(input);i++){
        if(input[i]=='-') printf("%c",input[i+1]);
    }
    printf("\n");


    return 0;
}
