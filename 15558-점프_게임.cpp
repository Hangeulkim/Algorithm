#include<bits/stdc++.h>

using namespace std;
bool visit[2][200100];
int N,K,t=1;
int input[2][200100];

int bfs(){
    queue<pair<pair<int, int>,int> > q;
    visit[0][1]=true;
    q.push({{0,1},1});

    while(!q.empty()){
        int line=q.front().first.first;
        int where=q.front().first.second;
        int when=q.front().second;


        q.pop();
        if(where>N)
            return 1;

        if(t==when){
            input[0][t]=0;
            input[1][t]=0;
            t++;
        }

        if((!visit[line][where+1]&&input[line][where+1])||where+1>N){
            visit[line][where+1]=true;
            q.push({{line,where+1},when+1});
        }

        if(where>1&&!visit[line][where-1]&&input[line][where-1]){
            visit[line][where-1]=true;
            q.push({{line,where-1},when+1});
        }

        line=line==1?0:1;

        if((!visit[line][where+K]&&input[line][where+K])||where+K>N){
            visit[line][where+K]=true;
            q.push({{line,where+K},when+1});
        }
    }
    return 0;
}

int main(){
    cin>>N>>K;
    for(int i=1;i<=N;i++)
        scanf("%1d",&input[0][i]);
    for(int i=1;i<=N;i++)
        scanf("%1d",&input[1][i]);

    printf("%d\n",bfs());

    return 0;
}
