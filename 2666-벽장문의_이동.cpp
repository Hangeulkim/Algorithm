#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int N, door1, door2, orders;
vector<int> nums;
int dp[21][21][21];

void input(){
    cin>>N>>door1>>door2;
    
    cin>>orders;
    nums.resize(orders);
    for(int i=0;i<orders;++i){
        cin>>nums[i];
    }
}

int dfs(int idx, int l, int r){
    if(idx >= orders)
        return 0;

    if(dp[idx][l][r] != -1)
        return dp[idx][l][r];

    int mv = nums[idx];

    dp[idx][l][r] = min(abs(mv-l) + dfs(idx+1, mv, r), abs(r-mv) + dfs(idx+1, l, mv));

    return dp[idx][l][r];
}

void solution(){
    fill(&dp[0][0][0],&dp[20][20][21], -1);
    cout<<dfs(0, door1, door2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}