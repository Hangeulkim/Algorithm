#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<pair<int, int> > way[1001];
int dist[1001];
int chk[1001];
int fst,lst;

void dijk(){
    dist[fst]=0;
    chk[fst]=0;
    priority_queue<pair<int, int> > pq;

    pq.push({0,fst});

    while(!pq.empty()){
        int cst=-pq.top().first;
        int now=pq.top().second;

        pq.pop();
        if(dist[now] < cst)
            continue;

        for(auto it : way[now]){
            int ncst = it.second+cst;
            int next = it.first;

            if(dist[next] > ncst){
                chk[next]=now;
                dist[next]=ncst;
                pq.push({-ncst,next});
            }
        }
    }

    cout<<dist[lst]<<'\n';
    stack<int> root;
    int st=lst;
    while(st!=0){
        root.push(st);
        st=chk[st];
    }
    cout<<root.size()<<'\n';
    while(!root.empty()){
        cout<<root.top()<<" ";
        root.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill(&dist[0],&dist[1001],87654321);
    int st,ed,cst;
    cin>>n>>m;
    while(m--){
        cin>>st>>ed>>cst;
        way[st].push_back({ed,cst});
    }
    cin>>fst>>lst;
    dijk();

    return 0;
}