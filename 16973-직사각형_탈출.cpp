#include<bits/stdc++.h>

using namespace std;

int N,M,H,W;
int a[1001][1001];
int sr,sc,fr,fc;

int mv[4][2]={
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};

typedef struct Square{
    int y;
    int x;
    int t;
}sq;

bool chk[1001][1001];

int bfs(){
    queue<sq> q;
    
    q.push({sr,sc,0});
    chk[sr][sc]=true;

    while(!q.empty()){
        int y=q.front().y;
        int x=q.front().x;
        int t=q.front().t;

        q.pop();

        if(y==fr&&x==fc)
            return t;

        for(int i=0;i<4;i++){
            int ny=y+mv[i][0];
            int nx=x+mv[i][1];

            if(chk[ny][nx]||ny<1||nx<1||ny+H-1>N||nx+W-1>M)
                continue;

            chk[ny][nx]=true;
            bool fflag=false;
            if(i<2){//y이동 x축 검사
                if(i==0)
                    ny+=H-1;
                for(int j=0;j<W;j++){
                    if(a[ny][nx+j]==1){
                        fflag=true;
                        break;
                    }
                }
                if(i==0)
                    ny-=H-1;
            }
            else{//x이동 y축 검사
                if(i==2)
                    nx+=W-1;
                for(int j=0;j<H;j++){
                    if(a[ny+j][nx]==1){
                        fflag=true;
                        break;
                    }
                }
                if(i==2)
                    nx-=W-1;
            }
            if(fflag)
                continue;
            q.push({ny,nx,t+1});
        }
    }


    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>a[i][j];
        }
    }
    cin>>H>>W>>sr>>sc>>fr>>fc;

    cout<<bfs();

    return 0;
}