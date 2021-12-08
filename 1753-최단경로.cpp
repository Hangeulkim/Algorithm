#include<bits/stdc++.h>

using namespace std;

int V,E,K;
vector<pair<int, int> > way[20001];
int dist[20001];

void bfs(){
    priority_queue<pair<int, int> > pq;
    
    dist[K]=0;
    pq.push({0,K});

    while(!pq.empty()){
        int dst = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dst > dist[now]) continue;

        for(auto it : way[now]){
            int next = it.first;
            int ndst = dst+it.second;
            if(dist[next]>ndst){
                dist[next]=ndst;
                pq.push({-ndst,next});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>V>>E>>K;
    fill(&dist[0],&dist[20001],87654321);
    int u,v,w;
    for(int i=0;i<E;i++){
        cin>>u>>v>>w;
        way[u].push_back({v,w});
    }
    bfs();
    for(int i=1;i<=V;i++){
        if(dist[i]>=87654321)
            cout<<"INF\n";
        else
            cout<<dist[i]<<'\n';
    }

    return 0;
}