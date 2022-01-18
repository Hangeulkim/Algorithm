#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int> > way[10001];
int V,E;
bool chk[10001];


long long prim(){
    priority_queue<pair<int, int> > pq;
    
    memset(chk,false,sizeof(chk));
    pq.push({0,1});
    long long tmp=0;

    while(!pq.empty()){
        int node = pq.top().second;
        int cost = -pq.top().first;

        pq.pop();
        if(chk[node])
            continue;
        chk[node]=true;
        tmp+=cost;

        for(auto it : way[node]){
            int next = it.first;
            if(!chk[next])
                pq.push({-it.second,next});

        }
    }

    return tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>V>>E;
    int tmp1,tmp2,tmp3;
    for(int i=1;i<=E;i++){
        cin>>tmp1>>tmp2>>tmp3;
        way[tmp1].push_back({tmp2,tmp3});
        way[tmp2].push_back({tmp1,tmp3});
    }

    cout<<prim()<<'\n';

    return 0;
}