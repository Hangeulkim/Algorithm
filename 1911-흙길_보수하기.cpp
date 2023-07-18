#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
typedef pair<int,int> PII;

int N, L;
vector<PII> swamp;

void input(){
    int a,b;
    cin>>N>>L;

    for(int i=0;i<N;++i){
        cin>>a>>b;
        swamp.push_back({a,b});
    }
    sort(swamp.begin(),swamp.end());
}

void solution(){
    int ans = 0, now = 0;
    for(int i=0;i<swamp.size();++i){
        if(now < swamp[i].first)
            now = swamp[i].first;

        int next = swamp[i].second;

        int num = ceil((double)(next-now)/L);
        ans += num;
        now += num * L;
    }
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();

    input();
    solution();

    return 0;
}