#include<bits/stdc++.h>

using namespace std;

typedef struct Data{
    int fy,fx,sy,sx,cnt;
}dat;

int N,M;
char input[22][22];
int f1y=0,f1x=0,f2y=0,f2x=0;
int my[4]={1,0,-1,0};
int mx[4]={0,1,0,-1};
bool visit[22][22][22][22];

bool chk(int fy, int fx, int sy, int sx){
    if((fy<1||fx<1||fy>N||fx>M)&&(sy>=1&&sy<=N&&sx>=1&&sx<=M)){
        return true;
    }
    if((sy<1||sx<1||sy>N||sx>M)&&(fy>=1&&fy<=N&&fx>=1&&fx<=M)){
        return true;
    }
    return false;
}

int bfs(){
    queue<dat> q;
    q.push({f1y,f1x,f2y,f2x,0});
    visit[f1y][f1x][f2y][f2x]=true;

    while(!q.empty()){
        int fy=q.front().fy;
        int fx=q.front().fx;
        int sy=q.front().sy;
        int sx=q.front().sx;
        int cnt=q.front().cnt;

        q.pop();

        if(cnt>10)
            return -1;
        if(chk(fy,fx,sy,sx))
            return cnt;

         for(int i=0;i<4;i++){
             int nfy=fy+my[i];
             int nfx=fx+mx[i];
             int nsy=sy+my[i];
             int nsx=sx+mx[i];

             if(input[nfy][nfx]=='#'){
                 nfy-=my[i];
                 nfx-=mx[i];
             }
             if(input[nsy][nsx]=='#'){
                 nsy-=my[i];
                 nsx-=mx[i];
             }

             if(visit[nfy][nfx][nsy][nsx]||((nsy<1||nsx<1||nsy>N||nsx>M)&&(nfy<1||nfx<1||nfy>N||nfx>M)))
                continue;
            if(nfy<0||nfx<0||nsy<0||nsx<0||nfy>N+1||nsy>N+1||nfx>M+1||nsx>M+1)
                continue;

            visit[nfy][nfx][nsy][nsx]=true;
            q.push({nfy,nfx,nsy,nsx,cnt+1});
         }
    }

    return -1;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(input,'.',sizeof(input));
    memset(visit,false,sizeof(visit));
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>input[i][j];
            if(input[i][j]=='o'){
                if(f1y==0){
                    f1y=i;
                    f1x=j;
                }
                else{
                    f2y=i;
                    f2x=j;
                }
            }
        }
    }

    cout<<bfs();

    return 0;
}
