#include<bits/stdc++.h>

using namespace std;

int N,tmp;
vector<int> input;
int dp[1001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    input.push_back(0);

    for(int i=1;i<=N;i++){
        cin>>tmp;

        input.push_back(tmp);
        for(int j=0;j<i;j++){
            dp[i]=max(dp[i],dp[j]+input[i-j]);
        }
    }

    cout<<dp[N]<<'\n';

    return 0;
}
