#include<bits/stdc++.h>

using namespace std;

int N=0;
vector<int> input,dp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tmp=0;
    cin>>N;
    input.push_back(0);
    for(int i=0;i<N;i++){
        cin>>tmp;
        input.push_back(tmp);
    }

    dp.push_back(0);
    dp.push_back(input[1]);

    if(N>=2){
        dp.push_back(input[1]+input[2]);
        for(int i=3;i<=N;i++){
            dp.push_back(max(dp[i-3]+input[i-1]+input[i],max(dp[i-2]+input[i],dp[i-1])));
        }
    }

    cout<<dp[N]<<'\n';
    return 0;
}
