#include<bits/stdc++.h>

using namespace std;

typedef vector<vector<long long>> vll;
long long int n;
long long mod = 1000000007;

vll operator * (vll &a, vll &b){
    vll c(2,vector<long long>(2));

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= mod;
        }
    }
    return c;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    vll ans = {{1,0},{0,1}};
    vll a = {{1,1},{1,0}};
    
    while(n>0){
        if(n%2==1)
            ans=ans*a;
        a=a*a;
        n/=2;
    }
    cout<<ans[0][1]<<'\n';

    return 0;
}