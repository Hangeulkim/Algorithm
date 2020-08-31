#include<bits/stdc++.h>

using namespace std;

int N,M;
int input[51][51];
bool visit[51][51];
int rnum=0,ret=0;

int my[4]={0,-1,0,1};
int mx[4]={-1,0,1,0};

int bfs(int y, int x){
    int sz=1;
    queue<pair<int,int> > q;
    q.push({y,x});
    visit[y][x]=true;

    while(!q.empty()){
        int ty=q.front().first;
        int tx=q.front().second;

        q.pop();

        for(int i=0;i<4;i++){
            int ny=ty+my[i];
            int nx=tx+mx[i];

            if((1<<i)&input[ty][tx])
                continue;
            if(ny<1||nx<1||ny>N||nx>M||visit[ny][nx])
                continue;

            visit[ny][nx]=true;
            sz++;
            q.push({ny,nx});
        }
    }


    return sz;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(visit,false,sizeof(visit));
    cin>>M>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>input[i][j];
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(!visit[i][j]){
                rnum++;
                ret=max(ret,bfs(i,j));
            }
        }
    }
    cout<<rnum<<'\n';
    cout<<ret<<'\n';

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            for(int k=0;k<4;k++){
                memset(visit,false,sizeof(visit));
                int num=(1<<k);
                input[i][j]-=num;
                ret=max(ret,bfs(i,j));
                input[i][j]+=num;
            }
        }
    }
    cout<<ret<<'\n';

    return 0;
}
