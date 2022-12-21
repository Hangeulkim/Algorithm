#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct dat{
    int time,alp,cop;
    
    bool operator<(const struct dat& d) const{
        return time > d.time;
    }
};

    
int mcost[151][151];
int maxalp = 0, maxcop = 0;

int dijkstra(int alp, int cop, vector<vector<int>> problems){
    priority_queue<dat> pq;
    
    fill(&mcost[0][0],&mcost[150][151],87654321);
    
    pq.push({0,alp,cop});
    mcost[alp][cop]=0;
    
    while(!pq.empty()){
        dat d=pq.top();
        
        pq.pop();
        
        if(d.time > mcost[d.alp][d.cop])
            continue;
        
        if(d.alp >= maxalp && d.cop >= maxcop)
            return d.time;
        
        for(int i=0,sz=problems.size();i<sz;++i){
            if(d.alp<problems[i][0]||d.cop<problems[i][1])
                continue;
            
            dat nd = {
                d.time+problems[i][4],
                d.alp+problems[i][2]>maxalp?maxalp:d.alp+problems[i][2],
                d.cop+problems[i][3]>maxcop?maxcop:d.cop+problems[i][3]
            };
            
            if(mcost[nd.alp][nd.cop] <= nd.time)
                continue;
            
            mcost[nd.alp][nd.cop]=nd.time;
            pq.push(nd);
        }
    }
    
    return -1;
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    
    for(int i=0,sz=problems.size();i<sz;++i){
        maxalp=max(maxalp,problems[i][0]);
        maxcop=max(maxcop,problems[i][1]);
    }
    problems.push_back({0,0,1,0,1});
    problems.push_back({0,0,0,1,1});
    
    answer=dijkstra(alp,cop,problems);
    
    return answer;
}