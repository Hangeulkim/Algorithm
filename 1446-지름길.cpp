#include<iostream>
#include<queue>

using namespace std;

int N,D;

vector<pair<int, int> > ways[10001];
int chk[10001];

void input(){
    cin>>N>>D;

    int a,b,c;
    while(N--){
        cin>>a>>b>>c;

        ways[a].push_back({b,c});
    }
}

int bfs(){
    priority_queue<pair<int, int> > pq;

    pq.push({0,0});
    chk[0] = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int node = pq.top().second;

        pq.pop();

        if(node == D)
            return cost;

        if(chk[node] < cost)
            continue;

        for(int i=0;i<ways[node].size();++i){
            int ncost = ways[node][i].second + cost;
            int next = ways[node][i].first;

            if(chk[next] <= ncost || next > D)
                continue;

            chk[next] = ncost;
            pq.push({-ncost, next});
        }

        if(cost + 1 <= chk[node + 1]){
            chk[node + 1] = cost + 1;
            pq.push({-(cost +1), node + 1});
        }
    }

    return -1;
}

void solution(){
    fill(&chk[0], &chk[10001], 987'654'321);
    cout<<bfs()<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}