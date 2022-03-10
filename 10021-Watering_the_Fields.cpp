#include<iostream>
#include<vector>
#include<cmath>
#include<queue>

using namespace std;

typedef struct Dat{
    int e;
    int dst;
    bool operator<(const Dat &b)const{
        return dst>b.dst;
    }
}dat;

int N,C;
vector<pair<int,int> > pipes;
vector<dat> way[2001];
bool chk[2001];
int prim(){
    priority_queue<dat> pq;
    int ret=0;

    pq.push({1,0});
    while(!pq.empty()){
        int now=pq.top().e;
        int cost=pq.top().dst;

        pq.pop();

        if(chk[now])
            continue;

        chk[now]=true;
        ret+=cost;

        for(int i=0;i<way[now].size();i++){
            int next=way[now][i].e;
            int ncost=way[now][i].dst;

            if(!chk[next]){
                pq.push({next,ncost});
            }
        }
    }

    for(int i=0;i<N;i++)
        if(!chk[i])
            return -1;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int y,x;
    cin>>N>>C;
    for(int i=0;i<N;i++){
        cin>>y>>x;
        for(int j=0;j<i;j++){
            int cost=pow(pipes[j].first-y,2)+pow(pipes[j].second-x,2);
            if(cost>=C){
                way[i].push_back({j,cost});
                way[j].push_back({i,cost});
            }
                
        }
        pipes.push_back({y,x});
    }

    cout<<prim()<<'\n';

    return 0;
}