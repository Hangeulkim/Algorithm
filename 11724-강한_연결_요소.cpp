#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

int cnt=0;
vector<int> way[1001];
bool visit[1001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N=0,M=0;
    int u=0,v=0;
    cin>>N>>M;
    while(M--){
        cin>>u>>v;
        way[u].push_back(v);
        way[v].push_back(u);
    }


    return 0;
}
