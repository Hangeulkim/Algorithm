#include<iostream>
#include<queue>
#include<functional>
#include<algorithm>

using namespace std;
typedef pair<int, int> PII;

int N;
vector<PII> ways[16];
int dp[16][1 << 16];

void input(){
    int a;

    cin>>N;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cin>>a;

            if(a!=0)
                ways[i].push_back({j,a});
        }
    }
}

int dfs(int node, int vst){
    if(dp[node][vst] != -1)
        return dp[node][vst];

    if(vst == (1 << N) - 1){
        for(int i=0;i<ways[node].size();++i){
            int next = ways[node][i].first;

            if(next == 0)
                return ways[node][i].second;
        }
        return 987'654'321;
    }

    dp[node][vst] = 987'654'321;
    for(int i=0;i<ways[node].size();++i){
        int next = ways[node][i].first;

        if(!(vst & 1 << next)){
            dp[node][vst] = min(dp[node][vst], dfs(next, vst | (1 << next)) + ways[node][i].second);
        }
    }

    return dp[node][vst];
}

void solution(){
    fill(&dp[0][0], &dp[15][1<<16], -1);
    cout<<dfs(0,1)<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();

    input();
    solution();

    return 0;
}