#include<bits/stdc++.h>

using namespace std;

int n;
int input[505][505];
int dp[505][505];

int my[4]={0,1,0,-1};
int mx[4]={1,0,-1,0};
int result=-1;

int dfs(int y, int x){
    if(dp[y][x])
        return dp[y][x];


    dp[y][x]=1;
    for(int i=0;i<4;i++){
        int ny=y+my[i];
        int nx=x+mx[i];

        if(input[ny][nx]>input[y][x])
            dp[y][x]=max(dp[y][x],dfs(ny,nx)+1);
    }
    return dp[y][x];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    memset(dp,0,sizeof(dp));
    memset(input,0,sizeof(input));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>input[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            result=max(result,dfs(i,j));
        }
    }
    cout<<result<<'\n';

    return 0;
}
