#include<bits/stdc++.h>

using namespace std;

int N,K,W,V;
int result;
int dp[101][100001];
vector<pair<int, int> > input;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>K;
    input.push_back({0,0});
    for(int i=0;i<N;i++){
        cin>>W>>V;
        input.push_back({W,V});
    }
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=N;i++){
        int w=input[i].first;
        int v=input[i].second;
        for(int j=0;j<=K;j++){
            if(j<w)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w]+v);
        }
    }
    cout<<dp[N][K]<<'\n';

    return 0;
}
