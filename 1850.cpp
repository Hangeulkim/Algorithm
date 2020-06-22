#include<iostream>

using namespace std;

long long int lcm(long long int a, long long int b){
    if(a<b){
        long long int tmp=0;
        tmp=a;
        a=b;
        b=tmp;
    }
    long long int mod=a%b;
    while(mod!=0){
        a=b;
        b=mod;
        mod=a%b;
    }
    return b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long int tmp1,tmp2;
    cin>>tmp1>>tmp2;
    long long int tmp=lcm(tmp1,tmp2);
    for(int i=1;i<=tmp;i++){
        cout<<1;
    }
    cout<<'\n';

    return 0;
}
