#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

int N, T=0;
vector<pair<int, int> > cups;

struct sort_queue{
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        return a.second < b.second;
    }
    
};

bool sort_vector(pair<int, int> &a, pair<int, int> &b){
    return a.first > b.first;
}

void input(){
    cin>>N;

    int a,b;
    for(int i=0;i<N;++i){
        cin>>a>>b;
        cups.push_back({a,b});
        T=max(T,a);
    }
}

void solution(){
    priority_queue<pair<int, int>, vector<pair<int, int> >, sort_queue> pq;
    sort(cups.begin(), cups.end(), sort_vector);

    int ans = 0, idx = 0;
    for(;T > 0; --T){
        while(idx < N && cups[idx].first >= T){
            pq.push({cups[idx].first, cups[idx].second});
            ++idx;
        }
        
        if(!pq.empty()){
            ans+=pq.top().second;
            pq.pop();
        }
    }

    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}