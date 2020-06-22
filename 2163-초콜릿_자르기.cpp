#include<iostream>
#include<algorithm>

using namespace std;

int dp[400];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N=0,M=0;
    cin>>N>>M;
    int cnt=0;

    dp[0]=M-1;
    for(int i=1;i<N;i++){
        dp[i] = dp[i-1] + M;
    }
    cout<<dp[N-1]<<'\n';

    return 0;
}
