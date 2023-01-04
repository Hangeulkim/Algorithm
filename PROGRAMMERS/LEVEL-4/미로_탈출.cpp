#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<tuple<int, int, bool> > way[1001];
int dist[1001][1<<11];
int trapper[1001];

struct dat{
  int cost, node, vst_trap;
    
    bool operator<(const struct dat& d) const{
        return cost > d.cost;
    }
};

bool cmp(vector<int>& a, vector<int>& b){
    return a[2] < b[2];
}

int dijkstra(int start,int end){
    priority_queue<dat> pq;
    
    dist[start][0]=0;
    pq.push({0,start,0});
    
    while(!pq.empty()){
        int node=pq.top().node;
        int cost=pq.top().cost;
        int vst_trap=pq.top().vst_trap;
        
        pq.pop();
        
        if(dist[node][vst_trap] < cost)
            continue;
        
        if(node == end)
            return cost;
        
        for(int i=0,sz=way[node].size();i<sz;++i){
            int next,ncost;
            int nstate = vst_trap;
            bool can_vst;
            
            tie(next,ncost,can_vst) = way[node][i];
            ncost+=cost;
            can_vst = can_vst == ((1 & nstate >> trapper[next]) == (1 & nstate >> trapper[node]));
            if(trapper[next])
                nstate = (1 & nstate >> trapper[next]) ? (nstate - (1 << trapper[next])) : (nstate | 1 << trapper[next]);
            
            
            if(dist[next][nstate] <= ncost || !can_vst)
                continue;
            
            dist[next][nstate]=ncost;
            pq.push({ncost,next,nstate});
        }
    }
    return -1;
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 0;
    
    fill(&dist[0][0],&dist[n][1<<11],987'654'321);
    sort(roads.begin(),roads.end(), cmp);
    for(int i=0,sz=traps.size();i<sz;++i){
        trapper[traps[i]]=i+1;
    }
    for(int i=0,sz=roads.size();i<sz;++i){
        int st = roads[i][0];
        int ed = roads[i][1];
        int cost = roads[i][2];
        
        way[st].push_back({ed,cost,true});
        if(trapper[st] || trapper[ed])
            way[ed].push_back({st,cost,false});
    }
    
    answer=dijkstra(start,end);
    
    return answer;
}