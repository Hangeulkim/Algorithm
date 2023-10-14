#include<iostream>
#include<vector>

using namespace std;

int N,M,K;
int dp[301][301];
vector<pair<int,int> > ways[301];
void input(){
    int a,b,c;

    cin>>N>>M>>K;

    for(int i=0;i<K;++i){
        cin>>a>>b>>c;

        if(a >= b || b > N)
            continue;

        ways[a].push_back({b,c});
    }
}

int dfs(int node, int cnt){
    if(dp[cnt][node] != -987'654'321)
        return dp[cnt][node];

    if(cnt > M)
        return -987'654'321;

    if(node == N)
        return dp[cnt][node] = 0;

    for(int i=0;i<ways[node].size();++i){
        int next = ways[node][i].first;
        int ncost = ways[node][i].second;

        dp[cnt][node] = max(dp[cnt][node], dfs(next, cnt+1) + ncost);
    }

    return dp[cnt][node];
}

void solution(){
    fill(&dp[0][0],&dp[300][301],-987'654'321);
    cout<<dfs(1,1)<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}