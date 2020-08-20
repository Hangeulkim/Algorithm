#include<bits/stdc++.h>

using namespace std;

typedef struct Data{
    int y,x,cnt,knight;
}dat;

int K,W,H;
int input[205][205];
bool visit[31][205][205]={false,};

int my[4]={1,0,-1,0};
int mx[4]={0,1,0,-1};
int ky[8]={1,2,2,1,-1,-2,-2,-1};
int kx[8]={-2,-1,1,2,2,1,-1,-2};

int bfs(){
    queue<dat> q;
    q.push({1,1,0,0});
    for(int j=0;j<=K;j++){
        visit[j][1][1]=true;

    }

    while(!q.empty()){
        int y=q.front().y;
        int x=q.front().x;
        int cnt=q.front().cnt;
        int knight=q.front().knight;

        q.pop();

        if(y==H&&x==W)
            return cnt;

        if(knight<K){
            for(int i=0;i<8;i++){
                int ny=y+ky[i];
                int nx=x+kx[i];

                if(ny<1||ny>H||nx<1||nx>W||visit[knight+1][ny][nx]||input[ny][nx]==1)
                    continue;

                q.push({ny,nx,cnt+1,knight+1});
                for(int j=knight+1;j<=K;j++){
                    if(visit[j][ny][nx])
                        break;
                    visit[j][ny][nx]=true;

                }
            }
        }


        for(int i=0;i<4;i++){
            int ny=y+my[i];
            int nx=x+mx[i];

            if(ny<1||ny>H||nx<1||nx>W||visit[knight][ny][nx]||input[ny][nx]==1)
                continue;

            q.push({ny,nx,cnt+1,knight});
            for(int j=knight;j<=K;j++){
                if(visit[j][ny][nx])
                    break;
                visit[j][ny][nx]=true;
            }
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>K>>W>>H;
    memset(visit,false,sizeof(visit));
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin>>input[i][j];
        }
    }

    cout<<bfs();

    return 0;
}
