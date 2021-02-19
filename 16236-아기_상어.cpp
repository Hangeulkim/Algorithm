#include<bits/stdc++.h>

using namespace std;

int N,M;
int sy,sx;
int fish[21][21];
int t=0;
int cnt=0;
int fishsz=2;
bool chk[21][21];
int my[4]={-1,0,0,1};
int mx[4]={0,-1,1,0};

typedef struct Dat{
    int y,x,c;
}dat;

int bfs(){
    queue<dat> q;

    q.push({sy,sx,0});
    chk[sy][sx]=true;

    int ey=987654321,ex=987654321,ec=987654321;
    while(!q.empty()){
        int y=q.front().y;
        int x=q.front().x;
        int c=q.front().c;

        q.pop();

        if(c==ec){
            break;
        }

        for(int i=0;i<4;i++){
            int ny=y+my[i];
            int nx=x+mx[i];

            if(ny<0||nx<0||ny>=N||nx>=N||chk[ny][nx]||fishsz<fish[ny][nx]) continue;

            if(fish[ny][nx]!=0&&fish[ny][nx]<fishsz){
                if(ny<ey||(ny==ey&&nx<ex)){
                    ey=ny;
                    ex=nx;
                    ec=c+1;
                    chk[ny][nx]=true;
                    continue;
                }
            }
            chk[ny][nx]=true;
            q.push({ny,nx,c+1});
        }
    }
    if(ey!=987654321){
        fish[ey][ex]=0;
        sy=ey;
        sx=ex;
        return ec;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>fish[i][j];
            if(fish[i][j]==9){
                fish[i][j]=0;
                sy=i;
                sx=j;
            }
        }
    }

    while(1){
        memset(chk,false,sizeof(chk));
        int num=bfs();
        if(num==0)
            break;
        cnt++;
        if(cnt==fishsz){
            cnt=0;
            fishsz++;
        }
        t+=num;
    }
    cout<<t<<'\n';


    return 0;
}
