#include<bits/stdc++.h>

using namespace std;

int N,M,K;
char input[101][101];
char mok[101];
int dp[101][101][101];

int my[4]={1,-1,0,0};
int mx[4]={0,0,1,-1};

int dfs(int y,int x, int idx){
    if(dp[y][x][idx]!=-1) return dp[y][x][idx];
    if(idx>=strlen(mok)) return 1;

    dp[y][x][idx]=0;
    for(int i=0;i<4;i++){
        for(int j=1;j<=K;j++){
            int ny=y+my[i]*j;
            int nx=x+mx[i]*j;

            if(ny>0&&nx>0&&ny<=N&&nx<=M&&input[ny][nx]==mok[idx]){
                dp[y][x][idx]=dp[y][x][idx]+dfs(ny,nx,idx+1);
            }
        }
    }

    return dp[y][x][idx];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M>>K;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>input[i][j];
        }
    }
    cin>>mok;

    int cnt=0;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(input[i][j]==mok[0]){
                cnt=cnt+dfs(i,j,1);
            }
        }
    }
    cout<<cnt<<'\n';


    return 0;
}
