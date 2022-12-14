#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<pair<int, int> > ways[50001];
bool peaks[50001];
int dist[50001];

void init(vector<vector<int>> paths, vector<int> summits){
    for(int i=0, sz=paths.size();i<sz;++i){
        int a = paths[i][0];
        int b = paths[i][1];
        int cost = paths[i][2];
        
        ways[a].push_back({b,cost});
        ways[b].push_back({a,cost});
    }
    
    fill(&peaks[0],&peaks[50001],false);
    for(int i=0, sz=summits.size();i<sz;++i){
        peaks[summits[i]]=true;
    }
    
    fill(&dist[0],&dist[50001],987654321);
}

vector<int> calc(int n, vector<int> gates){
    priority_queue<pair<int, int> > pq;
    
    for(int i=0, sz=gates.size();i<sz;++i){
        pq.push({0,gates[i]});
        dist[gates[i]] = 0;
    }
    
    while(!pq.empty()){
        int st=pq.top().second;
        int cost=-pq.top().first;
        
        pq.pop();
        
        if(dist[st]<cost)
            continue;
        
        for(int i=0, sz=ways[st].size();i<sz;++i){
            int next = ways[st][i].first;
            int ncost = ways[st][i].second>cost?ways[st][i].second:cost;
            
            if(dist[next] <= ncost)
                continue;
            
            dist[next] = ncost;
            
            if(!peaks[next])
                pq.push({-ncost,next});
        }
    }
    
    vector<int> answer;
    int gate=0;
    for(int i=0;i<=n;++i){
        if(peaks[i]&&dist[i]<dist[gate])
            gate=i;
    }
    
    answer.push_back(gate);
    answer.push_back(dist[gate]);
    return answer;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    
    init(paths, summits);
    answer=calc(n, gates);
    
    return answer;
}