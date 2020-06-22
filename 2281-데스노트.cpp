#include<bits/stdc++.h>

using namespace std;

int n,m;
int dp[1001][1001];
int input[1001];

int dfs(int idx, int cnt){
    if(idx==n) return 0;
    int &ans=dp[idx][cnt];
    if(ans!=-1) return ans;
    int cost=pow(m-cnt+1,2);
    ans=dfs(idx+1,input[idx]+1)+cost;
    if(cnt+input[idx]<=m){
        int tmp=dfs(idx+1,cnt+1+input[idx]);
        ans=min(tmp,ans);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<dfs(1,input[0]+1)<<'\n';

    return 0;
}
