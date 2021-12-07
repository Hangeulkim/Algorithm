#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int> > way[801];

int N,E;
int v1,v2;
int dist[3][801];
int result=87654321;

void bfs(int f, int dot){
    priority_queue<pair<int, int> > pq;

    dist[f][dot]=0;
    pq.push({0,dot});

    while(!pq.empty()){
        int cnt = -pq.top().first;
        int st = pq.top().second;

        pq.pop();
        if(dist[f][st] < cnt) continue;

        for(auto it : way[st]){
            int ed = it.second;
            int ncnt = cnt+it.first;

            if(dist[f][ed] > ncnt){
                dist[f][ed]=ncnt;
                pq.push({-ncnt,ed});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>E;
    int a,b,c;
    for(int i=0;i<E;i++){
        cin>>a>>b>>c;
        way[a].push_back({c,b});
        way[b].push_back({c,a});
    }

    cin>>v1>>v2;
    fill(&dist[0][0],&dist[2][801],87654321);
    bfs(0,1);
    bfs(1,v1);
    bfs(2,v2);

    result=min(result,dist[0][v1]+dist[1][v2]+dist[2][N]);
    result=min(result,dist[2][v1]+dist[0][v2]+dist[1][N]);
    if(result>=87654321)
        result=-1;

    cout<<result;
    return 0;
}