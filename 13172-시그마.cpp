#include<bits/stdc++.h>

using namespace std;

int M;
long long int mod = 1'000'000'007;
long long int N,S;
long long int ret=0;

long long int gcd(long long n,long long s){
    if(n < s)
        swap(n,s);
    if(s==0)
        return n;
    return gcd(s,n%s);
}

long long int q(long long s, long long m){
    long long int r=1;
    while(m>0){
        if(m%2==1){
            r=r*s%mod;
        }
        s=s*s%mod;
        m/=2;
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>M;
    while(M--){
        cin>>N>>S;
        long long g=gcd(N,S);
        N/=g;
        S/=g;
        ret+=(S*q(N,mod-2))%mod;
        ret%=mod;
    }   
    cout<<ret<<'\n';

    return 0;
}