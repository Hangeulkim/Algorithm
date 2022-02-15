#include<bits/stdc++.h>

using namespace std;

int N,M;
int A,B,C;
vector<pair<int, int> > way[100001];
bool chk[100001];

int prim(){
    priority_queue<pair<int, int> > pq;
    for(auto it : way[1]){
        pq.push({-it.first,it.second});
    }
    chk[1]=true;
    int ans=0;
    int max_num=0;

    while(!pq.empty()){
        int node = pq.top().second;
        int cost = -pq.top().first;

        pq.pop();
        if(chk[node])
            continue;
        chk[node]=true;
        ans+=cost;

        max_num=max(max_num,cost);
        for(auto it : way[node]){
            int next = it.second;
            if(!chk[next])
                pq.push({-it.first,next});

        }
    }

    return ans-max_num;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>A>>B>>C;
        way[A].push_back({C,B});
        way[B].push_back({C,A});
    }

    cout<<prim();


    return 0;
}