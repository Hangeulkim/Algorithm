#include<iostream>
#include<queue>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;

vector<int> way[1001];
bool visit[1001];
vector<int> out;
queue<int> outbfs;

void dfs(int a){
    out.push_back(a);
    visit[a]=true;
    for(int i=0;i<way[a].size();i++){
        if(visit[way[a][i]]) continue;
        else dfs(way[a][i]);
    }
}

void bfs(int a){
    fill(visit,visit+1001,0);
    outbfs.push(a);
    visit[a]=true;
    while(!outbfs.empty()){
        int tmp=outbfs.front();
        for(int i=0;i<way[tmp].size();i++){
            if(visit[way[tmp][i]]) continue;
            else{
                outbfs.push(way[tmp][i]);
                visit[way[tmp][i]]=true;
            }
        }
        cout<<outbfs.front()<<" ";
        outbfs.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N=0,M=0,V=0;
    int tmp1=0,tmp2=0;
    cin>>N>>M>>V;
    while(M--){
        cin>>tmp1>>tmp2;
        way[tmp1].push_back(tmp2);
        way[tmp2].push_back(tmp1);
    }
    for(int i=1;i<1001;i++){
        sort(way[i].begin(),way[i].end());
    }

    dfs(V);
    for(auto it : out) cout<<it<<" ";
    cout<<'\n';
    bfs(V);
    return 0;
}
