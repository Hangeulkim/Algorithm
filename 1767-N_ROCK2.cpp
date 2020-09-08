#include<bits/stdc++.h>

using namespace std;

int N,M,K;
long long int dp[101][101][101];
long long int mod=1000001;

long long find(int n, int m, int k){
    if(n<0||m<0||k<0)
        return 0;

    if(k==0)
        return 1;

    if(dp[n][m][k]!=-1)
        return dp[n][m][k];

    long long &ans=dp[n][m][k];

    ans=0;
    ans+=find(n-1,m,k);
    ans+=find(n-1,m-1,k-1)*m;
    ans+=find(n-1,m-2,k-2)*m*(m-1)/2;
    ans+=find(n-2,m-1,k-2)*m*(n-1);
    ans%=mod;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M>>K;
    memset(dp,-1,sizeof(dp));
    cout<<find(N,M,K);


    return 0;
}
