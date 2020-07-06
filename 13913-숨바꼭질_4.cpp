#include<bits/stdc++.h>

using namespace std;

typedef struct Data{
    int cnt;
    int where;
}dat;

int N,K;
int visit[200001];
queue<dat> q;

void bfs(){
    q.push({0,N});
    visit[N]=N;

    while(!q.empty()){
        int cnt=q.front().cnt;
        int where=q.front().where;

        if(where==K){
            return ;
        }
        q.pop();

        if(where*2<=100100&&visit[where*2]==-1){
            q.push({cnt+1,where*2});
            visit[where*2]=where;
        }
        if(where+1<=100000&&visit[where+1]==-1){
            q.push({cnt+1,where+1});
            visit[where+1]=where;
        }
        if(where-1>=0&&visit[where-1]==-1){
            q.push({cnt+1,where-1});
            visit[where-1]=where;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int rcnt,rwh;
    stack<int> r;
    cin>>N>>K;

    memset(visit,-1,sizeof(visit));
    bfs();
    rcnt=q.front().cnt;
    rwh=q.front().where;

    cout<<rcnt<<'\n';
    while(rwh!=visit[rwh]){
        r.push(rwh);
        rwh=visit[rwh];
    }
    cout<<N<<" ";
    while(!r.empty()){
        cout<<r.top()<<" ";
        r.pop();
    }

    return 0;
}
