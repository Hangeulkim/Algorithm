#include<bits/stdc++.h>

using namespace std;

int M,N;
int input[501][501];
long long dp[501][501];

long long dfs(int y, int x){
    if(y<1||y>M||x<1||x>N)
        return 0;
    else if(dp[y][x]!=-1)
        return dp[y][x];

    dp[y][x]=0;
    if(input[y][x]>input[y-1][x]){
        dp[y][x]+=dfs(y-1,x);
    }
    if(input[y][x]>input[y+1][x]){
        dp[y][x]+=dfs(y+1,x);
    }
    if(input[y][x]>input[y][x-1]){
        dp[y][x]+=dfs(y,x-1);
    }
    if(input[y][x]>input[y][x+1]){
        dp[y][x]+=dfs(y,x+1);
    }
    return dp[y][x];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>M>>N;

    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            cin>>input[i][j];
            dp[i][j]=-1;
        }
    }
    dp[M][N]=1;

    cout<<dfs(1,1);

    return 0;
}
