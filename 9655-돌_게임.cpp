#include<iostream>

using namespace std;

int N;
int dp[1001][2];

int dfs(int cnt, int who){
    if(dp[cnt][who])
        return dp[cnt][who];

    int wflag = who?1:-1;
    int fflag = who?-1:1;

    if(cnt==N)
        return fflag;
    
    if(cnt+3<=N)
        dp[cnt+3][who] = dfs(cnt+3,who?0:1);
    dp[cnt+1][who] = dfs(cnt+1,who?0:1);

    return dp[cnt][who] = (dp[cnt+1][who]==wflag || dp[cnt+3][who]==wflag)?wflag:fflag;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    if(dfs(0,1)==1)
        cout<<"SK"<<'\n';
    else
        cout<<"CY"<<'\n';

    return 0;
}