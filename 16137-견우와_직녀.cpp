#include<bits/stdc++.h>

using namespace std;

typedef struct Data{
    int y,x,cnt,jmp;
}dat;

int N,M;
int input[12][12];

int my[4]={1,0,-1,0};
int mx[4]={0,1,0,-1};
int visit[12][12][2];

int bfs(){
    queue<dat> q;
    q.push({1,1,0,0});
    visit[1][1][0]=0;

    while(!q.empty()){
        int y=q.front().y;
        int x=q.front().x;
        int cnt=q.front().cnt;
        int jmp=q.front().jmp;

        q.pop();

        for(int i=0;i<4;i++){
            int ny=y+my[i];
            int nx=x+mx[i];

            if(ny<1||nx<1||ny>N||nx>N||input[ny][nx]==-1)
                continue;
            if(input[ny][nx]!=1&&input[y][x]!=1)
                continue;
            if(input[ny][nx]==0&&jmp)
                continue;

            int tmpc=0;
            if(input[ny][nx]==0){
                tmpc=(cnt/M+1)*M;
                if(visit[ny][nx][1]<=tmpc)
                    continue;
                q.push({ny,nx,tmpc,1});
                visit[ny][nx][1]=tmpc;
            }
            else if(input[ny][nx]>=2){
                tmpc=(cnt/input[ny][nx]+1)*input[ny][nx];
                if(visit[ny][nx][jmp]<=tmpc)
                    continue;
                q.push({ny,nx,tmpc,jmp});
                visit[ny][nx][jmp]=tmpc;
            }
            else if(input[ny][nx]==1){
                tmpc=cnt+1;
                if(visit[ny][nx][jmp]<=tmpc)
                    continue;
                q.push({ny,nx,cnt+1,jmp});
                visit[ny][nx][jmp]=cnt+1;
                if(jmp==0)
                    visit[ny][nx][1]=min(tmpc,visit[ny][nx][1]);
            }
        }
    }
    return visit[N][N][1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    fill(input[0],input[0]+sizeof(input)/sizeof(int),1);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>input[i][j];
            visit[i][j][0]=987654321;
            visit[i][j][1]=987654321;
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(input[i][j]==0){
                if((input[i+1][j]!=1||input[i-1][j]!=1)&&(input[i][j+1]!=1||input[i][j-1]!=1))
                    input[i][j]=-1;
            }
        }
    }

    cout<<bfs()<<'\n';


    return 0;
}
