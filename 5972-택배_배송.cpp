#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N,M;
int dp[50001];
vector<pair<int, int> > ways[50001];

void input(){
    int a,b,c;

    cin>>N>>M;

    for(int i=0;i<M;++i){
        cin>>a>>b>>c;

        ways[a].push_back({b,c});
        ways[b].push_back({a,c});
    }
}

int dijkstra(){
    priority_queue<pair<int, int> > pq;

    pq.push({0,1});
    dp[1] = 0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int node = pq.top().second;

        pq.pop();

        if(dp[node] < cost)
            continue;

        for(int i=0;i<ways[node].size();++i){
            int next = ways[node][i].first;
            int ncost = ways[node][i].second + cost;

            if(dp[next] <= ncost)
                continue;
            
            pq.push({-ncost,next});
            dp[next] = ncost;
        }
    }


    return dp[N];
}

void solution(){
    fill(&dp[0], &dp[50001], 987'654'321);

    cout<<dijkstra()<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}