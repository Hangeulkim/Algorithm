#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int N;
vector<int> dp, nums;

void input(){
    cin>>N;

    dp.resize(N+1);
    nums.resize(N+1);
    for(int i=1;i<=N;++i){
        cin>>nums[i];
    }
}

void solution(){
    int mx,mn;

    dp[0] = 0;
    for(int i=1;i<=N;++i){
        mx = mn = nums[i];
        dp[i] = 0;

        for(int j=i;j>0;--j){
            mx = max(mx, nums[j]);
            mn = min(mn, nums[j]);
            dp[i] = max(dp[i], mx - mn + dp[j-1]);
        }
    }

    cout<<dp[N]<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}