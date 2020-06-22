#include<iostream>

using namespace std;

long long int lcm(long long int a, long long int b){
    long long int mod=a%b;
    while(mod!=0){
        a=b;
        b=mod;
        mod=a%b;
    }
    return b;
}

long long int gcd(long long int a, long long int b){
    long long int tmp=0;
    if(a<b) tmp=lcm(b,a);
    else tmp=lcm(a,b);
    return a*b/tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long int tmp1,tmp2;
    cin>>tmp1>>tmp2;
    cout<<gcd(tmp1,tmp2)<<'\n';

    return 0;
}
