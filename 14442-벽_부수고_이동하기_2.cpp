#include<bits/stdc++.h>

using namespace std;

typedef struct Data{
    int y,x,cnt,lock;
}dat;

int N,M,K;
bool visit[1001][1001][11];
char input[1001][1001];
int my[4]={1,0,-1,0};
int mx[4]={0,1,0,-1};

int bfs(){
    queue<dat> q;
    q.push({1,1,1,0});

    for(int i=0;i<=K;i++){
        visit[1][1][i]=true;
    }

    while(!q.empty()){
        int y=q.front().y;
        int x=q.front().x;
        int cnt=q.front().cnt;
        int lock=q.front().lock;

        q.pop();

        if(y==N&&x==M)
            return cnt;

        for(int i=0;i<4;i++){
            int ny=y+my[i];
            int nx=x+mx[i];
            if(ny<1||nx<1||ny>N||nx>M)
                continue;

            if(visit[ny][nx][lock]||(input[ny][nx]=='1'&&(visit[ny][nx][lock+1]||lock+1>K)))
                continue;

            if(input[ny][nx]=='1'){
                q.push({ny,nx,cnt+1,lock+1});
                for(int k=lock+1;k<=K;k++)
                    visit[ny][nx][k]=true;
            }
            else{
                q.push({ny,nx,cnt+1,lock});
                for(int k=lock;k<=K;k++)
                    visit[ny][nx][k]=true;
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(visit,false,sizeof(visit));
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>input[i][j];
        }
    }
    cout<<bfs();

    return 0;
}
