#include<bits/stdc++.h>

using namespace std;

int N,tmp;
vector<int> input;
long long dp[101][21];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;

    input.push_back(0);
    for(int i=1;i<=N;i++){
        cin>>tmp;
        input.push_back(tmp);
    }

    memset(dp,0,sizeof(dp));
    dp[1][input[1]]=1;
    for(int i=2;i<N;i++){
        for(int j=0;j<=20;j++){
            if(dp[i-1][j]==0)
                continue;
            if(j+input[i]<=20) dp[i][j+input[i]]+=dp[i-1][j];
            if(j-input[i]>=0) dp[i][j-input[i]]+=dp[i-1][j];
        }
    }

    cout<<dp[N-1][input[N]]<<'\n';


    return 0;
}
