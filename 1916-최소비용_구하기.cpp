#include<bits/stdc++.h>

using namespace std;

int N,M;
int st,ed;
int dist[1001];
vector<pair<int, int> > bus[1001];

void dijkstra(){
    priority_queue<pair<int,int> > pq;

    dist[st]=0;
    pq.push({0,st});

    while(!pq.empty()){
        int s=pq.top().second;
        int t=-pq.top().first;
        pq.pop();

        if(dist[s] < t)
            continue;

        for(auto it : bus[s]){
            int e = it.first;
            int nt = it.second+t;
            if(dist[e] > nt){
                dist[e]=nt;
                pq.push({-nt,e});
            }
        }
        
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    fill(&dist[0],&dist[1001],987654321);
    int s,e,t;
    while(M--){
        cin>>s>>e>>t;
        bus[s].push_back({e,t});
    }
    cin>>st>>ed;
    dijkstra();
    cout<<dist[ed]<<'\n';

    return 0;
}