#include<bits/stdc++.h>

using namespace std;

int N;
int a[11][11];
int sy,sx;

typedef struct Dat{
    int y;
    int x;
    int mal;
    int t;
    int num;
}Dat;

queue<Dat> dat;

int knight[8][2]={
    {2,-1},
    {2,1},
    {-2,1},
    {-2,-1},
    {1,2},
    {1,-2},
    {-1,2},
    {-1,-2}    
};

int bishop[4][2]={
    {1,1},
    {1,-1},
    {-1,1},
    {-1,-1}
};

int rook[4][2]={
    {1,0},
    {0,1},
    {-1,0},
    {0,-1}
};

bool chk[111][11][11][3];

int bfs(){
    dat.push({sy,sx,0,0,1});
    dat.push({sy,sx,1,0,1});
    dat.push({sy,sx,2,0,1});

    chk[1][sy][sx][0]=true;
    chk[1][sy][sx][1]=true;
    chk[1][sy][sx][2]=true;

    while(!dat.empty()){
        int y=dat.front().y;
        int x=dat.front().x;
        int mal=dat.front().mal;
        int t=dat.front().t;
        int num=dat.front().num;

        dat.pop();

        if(num==N*N)
            return t;

        int ny,nx,nn;

        for(int i=0;i<3;i++){
            if(chk[num][y][x][i])
                continue;
            dat.push({y,x,i,t+1,num});
            chk[num][y][x][i]=true;
        }

        if(mal==0){
            for(int i=0;i<8;i++){
                ny=y+knight[i][0];
                nx=x+knight[i][1];

                if(ny<0 || ny>=N || nx<0 || nx>=N)
                    continue;

                if(chk[num][ny][nx][mal])
                    continue;

                nn=a[ny][nx];
                if(nn==num+1){
                    dat.push({ny,nx,mal,t+1,nn});
                    chk[nn][ny][nx][mal]=true;
                }
                else{
                    dat.push({ny,nx,mal,t+1,num});
                    chk[num][ny][nx][mal]=true;
                }
            }

        }
        
        else if(mal==1){
            for(int i=0;i<4;i++){
                ny=y;
                nx=x;
                for(int j=0;;j++){
                    ny+=bishop[i][0];
                    nx+=bishop[i][1];
                    if(ny<0 || ny>=N || nx<0 || nx>=N)
                        break;

                    if(chk[num][ny][nx][mal])
                        continue;

                    nn=a[ny][nx];
                    if(nn==num+1){
                        dat.push({ny,nx,mal,t+1,nn});
                        chk[nn][ny][nx][mal]=true;
                        break;
                    }
                    else{
                        dat.push({ny,nx,mal,t+1,num});
                        chk[num][ny][nx][mal]=true;
                    }
                }
            }
        }
        
        else{
            for(int i=0;i<4;i++){
                ny=y;
                nx=x;
                for(int j=0;;j++){
                    ny+=rook[i][0];
                    nx+=rook[i][1];
                    if(ny<0||ny>=N||nx<0||nx>=N)
                        break;

                    if(chk[num][ny][nx][mal])
                        continue;

                    nn=a[ny][nx];
                    if(nn==num+1){
                        dat.push({ny,nx,mal,t+1,nn});
                        chk[nn][ny][nx][mal]=true;
                        break;
                    }
                    else{
                        dat.push({ny,nx,mal,t+1,num});
                        chk[num][ny][nx][mal]=true;
                    }
                }
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>a[i][j];
            if(a[i][j]==1){
                sy=i;
                sx=j;
            }
        }
    }

    cout<<bfs()<<'\n';

    return 0;
}