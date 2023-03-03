#include<iostream>

using namespace std;

int N,M;
int arr[7][7];
int dp[7][8][3];

void input(){
    cin>>N>>M;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            cin>>arr[i][j];
        }
    }
}

void solution(){
    fill(&dp[0][0][0],&dp[6][7][3],987654321);

    for(int j=1;j<=M;++j){
        dp[1][j][0]=arr[1][j];
        dp[1][j][1]=arr[1][j];
        dp[1][j][2]=arr[1][j];
    }

    for(int i=2;i<=N;++i){
        for(int j=1;j<=M;++j){
            dp[i][j][0] = min(dp[i-1][j+1][1],dp[i-1][j+1][2])+arr[i][j];
            dp[i][j][1] = min(dp[i-1][j][0],dp[i-1][j][2])+arr[i][j];
            dp[i][j][2] = min(dp[i-1][j-1][0],dp[i-1][j-1][1])+arr[i][j];
        }
    }

    int ans=987654321;
    for(int j=1;j<=M;++j){
        ans=min(min(ans,dp[N][j][0]),min(dp[N][j][1],dp[N][j][2]));
    }
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}