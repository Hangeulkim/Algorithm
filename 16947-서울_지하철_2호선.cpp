#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> input[3001];
int d[3001];
int chk[3001];
int to,from;
queue<int> q;

int dfs(int now, int prev){
    if(chk[now]==1) return now;
    chk[now]=true;

    int sz=input[now].size();
    for(int i=0;i<sz;i++){
        int next=input[now][i];
        if(next!=prev){
            int ret=dfs(next,now);
            if(ret==-2) return -2;
            else if(ret>=0){
                chk[now]=2;
                if(now==ret) return -2;
                else return ret;
            }
        }
    }
    return -1;
}

void bfs(){
    while(!q.empty()){
        int now=q.front();

        q.pop();

        int sz=input[now].size();
        for(int i=0;i<sz;i++){
            int next=input[now][i];
            if(d[next]==-1){
                q.push(next);
                d[next]=d[now]+1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(chk,-1,sizeof(chk));
    memset(d,-1,sizeof(d));
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>to>>from;
        input[to].push_back(from);
        input[from].push_back(to);
    }

    dfs(1,-1);

    for(int i=1;i<=N;i++){
        if(chk[i]==2){
            d[i]=0;
            q.push(i);
        }
    }

    bfs();
    for (int i = 1; i <= N; i++)
		cout << d[i] << ' ';

    return 0;
}
