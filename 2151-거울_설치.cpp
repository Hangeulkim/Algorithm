#include<bits/stdc++.h>

using namespace std;

typedef struct Data{
    int y,x,m,cnt;
}dat;

int N;
char room[52][52];
int visit[52][52][4];
int my[4]={1,0,-1,0};
int mx[4]={0,-1,0,1};

int bfs(){
    queue<dat> q;

    bool fflag=false;
    for(int y=1;y<=N;y++){
        for(int x=1;x<=N;x++){
            if(room[y][x]=='#'){
                for(int m=0;m<4;m++){
                    int ny=y+my[m];
                    int nx=x+mx[m];

                    if(room[ny][nx]!='*')
                        q.push({y,x,m,0});
                    visit[y][x][m]=0;
                }
                fflag=true;
                break;
            }
        }
        if(fflag)
            break;
    }

    while(!q.empty()){
        int y=q.front().y;
        int x=q.front().x;
        int m=q.front().m;
        int cnt=q.front().cnt;

        q.pop();

        int ny=y+my[m];
        int nx=x+mx[m];

        while(visit[ny][nx][m]>cnt&&room[ny][nx]!='*'){
            visit[ny][nx][m]=true;
            visit[ny][nx][(m+2)%4]=true;
            if(room[ny][nx]=='#')
                return cnt;

            if(room[ny][nx]=='!'){
                q.push({ny,nx,(m+1)%4,cnt+1});
                q.push({ny,nx,(m+3)%4,cnt+1});
                visit[ny][nx][(m+1)%4]=cnt+1;
                visit[ny][nx][(m+2)%4]=cnt+1;
                visit[ny][nx][(m+3)%4]=cnt+1;
            }

            ny+=my[m];
            nx+=mx[m];
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(room,'*',sizeof(room));
    memset(visit,1,sizeof(visit));
    cin>>N;
    for(int y=1;y<=N;y++){
        for(int x=1;x<=N;x++){
            cin>>room[y][x];
        }
    }
    cout<<bfs();

    return 0;
}
