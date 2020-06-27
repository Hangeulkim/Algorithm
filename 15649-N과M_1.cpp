#include<bits/stdc++.h>

using namespace std;

int N,M;
int visit[10];
int dat[10];

void dfs(int cnt){
    if(cnt==M){
        for(int i=0;i<M;i++){
            cout<<dat[i]<<" ";
        }
        cout<<'\n';
        return ;
    }

    for(int i=1;i<=N;i++){
        if(visit[i]==0){
            visit[i]=1;
            dat[cnt]=i;
            dfs(cnt+1);
            visit[i]=0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    memset(visit,0,sizeof(visit));
    dfs(0);

    return 0;
}
