#include<iostream>
#include<queue>
#include<functional>

using namespace std;
typedef pair<int, int> pii;
typedef pair<long long, int> pli;

int N;
long long M;
vector<pii> ways[100001];
long long dp[100001];

struct compare{
    bool operator()(pli &a, pli &b){
        if(a.first == b.first)
            a.second > b.second;
        return a.first > b.first;
    }
};

void input(){
    int a,b;

    cin>>N>>M;
    for(int i=0;i<M;++i){
        cin>>a>>b;

        ways[a].push_back({b,i});
        ways[b].push_back({a,i});
    }
}

long long calc(long long cost, int ni){
    if(cost < ni)
        return ni + 1;
    
    else if((cost - ni) % M == 0)
        return (cost - ni)/M*M + ni + 1;
    else
        return ((cost - ni)/M + 1)*M + ni + 1;
}

long long bfs(){
    priority_queue<pli, vector<pli>, compare> pq;

    pq.push({0,1});
    dp[1] = 0;
    while(!pq.empty()){
        long long cost = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        if(node == N)
            return cost;

        if(dp[node] < cost)
            continue;
        
        for(int i=0;i<ways[node].size();++i){
            int next = ways[node][i].first;
            int ni = ways[node][i].second;
            long long ncost = calc(cost, ni);

            if(dp[next] <= ncost)
                continue;
            
            dp[next] = ncost;
            pq.push({ncost, next});
        }
    }
    return -1;
}

void solution(){
    fill(&dp[0], &dp[100001], 123'456'123'456'123'456);
    cout<<bfs()<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}