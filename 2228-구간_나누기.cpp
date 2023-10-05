#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int N,M;
bool chk[101][52];
int dp[101][52];
vector<int> psum;

void input(){
    cin>>N>>M;

    int tmp=0;
    psum.resize(N+1);

    for(int i=1;i<=N;++i){
        cin>>tmp;

        psum[i]=psum[i-1]+tmp;
    }
}

int dfs(int n, int m){
    if(m == 0)
        return 0;

    if(n < 2*m - 1)
        return -987'654'321;

    if(chk[n][m])
        return dp[n][m];

    chk[n][m] = true;
    dp[n][m] = dfs(n-1,m);

    for(int i=n;i>0;--i){
        dp[n][m] = max(dp[n][m], psum[n] - psum[i-1] + dfs(i-2, m-1));
    }

    return dp[n][m];
}

void solution(){
    cout<<dfs(N,M)<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}
