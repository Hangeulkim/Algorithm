#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>

using namespace std;

typedef struct Data{
    int node, cost;
}d;

struct compare{
    bool operator()(d &a, d&b){
        return a.cost > b.cost;
    }
};

int N,M,K;
vector<pair<int, int> > way[10001];
vector<int> market;
int chk[10001];
int dist[5][10001];

void Initialize(){
    fill(&dist[0][0],&dist[4][10001],87654321);
    fill(&chk[0],&chk[10001],-1);
}

void Input(){
    cin>>N>>M>>K;
    
    int a,b,c;
    for(int i=0;i<K;i++){
        cin>>a;
        market.push_back(a);
    }
    sort(market.begin(),market.end());

    for(int i=0;i<K;i++){
        chk[market[i]]=i;
    }

    for(int i=0;i<M;i++){
        cin>>a>>b>>c;
        way[a].push_back({b,c});
        way[b].push_back({a,c});
    }
}

void dijkstra(int idx, int start){
    priority_queue<d, vector<d>, compare> pq;

    dist[idx][start]=0;
    pq.push({start,0});
    
    while(!pq.empty()){
        int node = pq.top().node;
        int cost = pq.top().cost;

        pq.pop();

        if(dist[idx][node] < cost)
            continue;

        for(int i=0;i<way[node].size();i++){
            int next=way[node][i].first;
            int ncost=way[node][i].second+cost;

            if(dist[idx][next] <= ncost)
                continue;

            pq.push({next,ncost});
            dist[idx][next]=ncost;
        }
    }
}

int calc(){
    int ret=INT_MAX;

    for(int i=1;i<=N;i++){
        if(chk[i]!=-1)
            continue;
        
        ret = min(ret, dist[chk[market[0]]][i] + dist[chk[market[K-1]]][i]);
    }

    for(int i=0;i<K-1;i++)
        ret += dist[chk[market[i]]][market[i+1]];
    return ret;
}

void Solution(){
    for(int i=0;i<K;i++){
        dijkstra(i,market[i]);
    }

    int ret = INT_MAX;
    do{
        ret=min(ret,calc());
    }while(next_permutation(market.begin(),market.end()));
    cout<<ret<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Initialize();
    Input();
    Solution();

    return 0;
}