#include<bits/stdc++.h>

using namespace std;

int N,M;
int dp[1001][1001][3];
int mars[1001][1001];
bool chk[1001][1001];
int my[3]={0,0,1};
int mx[3]={1,-1,0};

int find(int y, int x, int dir){
    if(y==N&&x==M) return mars[y][x];
    if(dp[y][x][dir]!=-987654321) return dp[y][x][dir];

    chk[y][x]=true;

    int ret=-987654321;
    for(int i=0;i<3;i++){
        int ny=y+my[i];
        int nx=x+mx[i];
        if(ny<1||nx<1||ny>N||nx>M||chk[ny][nx])
            continue;
        ret=max(ret,find(ny,nx,i));
    }
    chk[y][x]=false;
    dp[y][x][dir]=mars[y][x]+ret;

    return dp[y][x][dir];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill(&dp[0][0][0],&dp[1000][1000][3],-987654321);
    memset(chk,false,sizeof(chk));
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>mars[i][j];
        }
    }



    cout<<find(1,1,0)<<'\n';

    return 0;
}
