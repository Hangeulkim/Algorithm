#include<bits/stdc++.h>

using namespace std;

int N;
long long dp[100001];
vector<int> input;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=1;i*i<=200001;i++){
        input.push_back(i*i);
    }

    for(int i=1;i<=N;i++){
        dp[i]=9876543210;
        for(int j=0;i>=input[j];j++){
            dp[i]=min(dp[i],dp[i-input[j]]+1);
        }
    }
    cout<<dp[N];

    return 0;
}
