#include<bits/stdc++.h>

using namespace std;

int input[101][101];
long long dp[101][101];
int N;

long long dfs(int y, int x){
    if(y>N||y<1||x>N||x<1)
        return 0;
    else if(dp[y][x]!=-1)
        return dp[y][x];

    long long cnt=input[y][x];
    dp[y][x]++;
    dp[y][x]+=dfs(y,x+cnt);
    dp[y][x]+=dfs(y+cnt,x);

    return dp[y][x];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>input[i][j];
            dp[i][j]=-1;
        }
    }
    dp[N][N]=1;

    cout<<dfs(1,1)<<'\n';

    return 0;
}
