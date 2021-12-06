#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int> > way[2][1001];
int dist[2][1001];
int result=1;

int N,M,X;

void bfs(int f){
    priority_queue<pair<int, int> > pq;

    pq.push({0,X});
    dist[f][X]=0;


    while(!pq.empty()){
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dist[f][now] < cost) continue;

        for(auto it : way[f][now]){
            int next = it.second;
            int ncost = it.first+cost;

            if(dist[f][next] > ncost){
                dist[f][next] = ncost;
                pq.push({-ncost,next});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M>>X;
    int st,ed,t;
    for(int i=0;i<M;i++){
        cin>>st>>ed>>t;
        way[0][st].push_back({t,ed});
        way[1][ed].push_back({t,st});
    }

    fill(&dist[0][0],&dist[1][1001],987654321);

    bfs(0);
    bfs(1);

    for(int i=1;i<=N;i++){
        result = max(result,dist[0][i]+dist[1][i]);
    }
    cout<<result<<'\n';

    return 0;
}