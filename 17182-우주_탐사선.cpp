#include<iostream>
#include<algorithm>
#include<queue>
#include<algorithm>

using namespace std;

int t[11][11];
bool chk[11];
int N,K,D;
int ans=987'654'321;

void input(){
    cin>>N>>K;

    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cin>>D;
            t[i][j]=D;
        }
    }
}

void floyd(){    
    for(int k=0;k<N;++k){
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                t[i][j] = min(t[i][j], t[i][k]+t[k][j]);
            }
        }
    }
}

void dfs(int node, int cnt, int ret){
    if(cnt == N){
        ans = min(ans, ret);
        return ;
    }

    for(int next=0; next<N; ++next){
        if(chk[next])
            continue;
        
        chk[next]=true;
        dfs(next, cnt+1, ret+t[node][next]);
        chk[next]=false;
    }
}

void solution(){

    floyd();
    chk[K]=true;
    dfs(K, 1, 0);

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
