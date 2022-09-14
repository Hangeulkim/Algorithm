#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;

int N,K,P;
int dist[1001];
vector<pair<int,int> > way[1001];

typedef struct Dat{
    int cnt,now;
}D;

struct compare{
    bool operator()(D &A, D &B){
        return A.cnt > B.cnt;
    }
};

void Initialize(){
    for(int i=0;i<1001;i++)
        dist[i]=INT_MAX;
}

void Input(){
    cin>>N>>P>>K;

    int a,b,c;    
    for(int i=0;i<P;i++){
        cin>>a>>b>>c;
        way[a].push_back({b,c});
        way[b].push_back({a,c});
    }
}

bool dijkstra(int mid){
    priority_queue<D, vector<D>, compare> pq;

    pq.push({0,1});

    while(!pq.empty()){
        int now = pq.top().now;
        int cnt = pq.top().cnt;

        pq.pop();

        if(dist[now]<cnt)
            continue;

        for(int i=0;i<way[now].size();i++){
            int next=way[now][i].first;
            int ncost=way[now][i].second;
            
            int ncnt=cnt;
            if(ncost>mid)
                ncnt++;

            if(dist[next]>ncnt){
                dist[next]=ncnt;
                pq.push({ncnt,next});
            }
        }
    }

    return dist[N] <= K;

}

void Solution(){
    int l=0,r=1000001,mid,ans=-1;

    while(l<=r){
        mid=(l+r)/2;
        Initialize();
        dist[1]=0;

        if(dijkstra(mid)){
            r = mid-1;
            ans = mid;
        }
        else{
            l = mid+1;
        }
    }

    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();
    Solution();

    return 0;
}