#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
string input;
long long int level=0,x=0,y=0;
int tmp=0,leng=0;

void calc(int a){
    if(a<0) return;
    level++;
    x*=2;
    y*=2;
    if(input[leng-a]=='1'){
        x+=1;
    }
    else if(input[leng-a]=='2'){
        y+=1;
    }
    else if(input[leng-a]=='3'){
        x+=1;
        y+=1;
    }
    calc(a-1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>input;
    leng=input.length()-1;
    calc(leng);
    printf("%lld %lld %lld\n",level,x,y);

    return 0;
}
