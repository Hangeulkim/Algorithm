#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
queue<int> bfs;
vector<int> way[100001];
int out[100001];
bool visit[100001];

void bfsc(int a){
    visit[a]=true;
    bfs.push(a);
    while(!bfs.empty()){
        int tmp=bfs.front();
        for(int i=0;i<way[tmp].size();i++){
            if(visit[way[tmp][i]]) continue;
            else{
                bfs.push(way[tmp][i]);
                visit[way[tmp][i]]=true;
                out[way[tmp][i]]=tmp;
            }
        }
        bfs.pop();
    }
    for(int i=1;i<100001;i++){
        if(out[i]!=0) cout<<out[i]<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N=0;
    cin>>N;
    int tmp1=0,tmp2=0;
    N-=1;
    while(N--){
        cin>>tmp1>>tmp2;
        way[tmp1].push_back(tmp2);
        way[tmp2].push_back(tmp1);
    }
    for(int i=1;i<100001;i++) sort(way[i].begin(),way[i].end());
    bfsc(1);

    return 0;
}
