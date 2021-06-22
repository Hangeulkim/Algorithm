#include<bits/stdc++.h>

using namespace std;

char a[10][10];

int mv[9][2]={
    {1,0},
    {1,1},
    {1,-1},
    {-1,0},
    {-1,1},
    {-1,-1},
    {0,1},
    {0,-1},
    {0,0}
};

void move_wall(){
    for(int i=6;i>=0;i--){
        for(int j=0;j<8;j++){
            a[i+1][j]=a[i][j];
        }
    }
}

typedef struct WOOK{
    int t;
    int y;
    int x;
}wook;

bool chk[10][8][8];

int bfs(){
    queue<wook> q;

    q.push({0,7,0});
    chk[0][7][0]=true;
    int ct=0;

    while(!q.empty()){
        int t=q.front().t;
        int y=q.front().y;
        int x=q.front().x;

        q.pop();

        if(t>ct){
            move_wall();
            ct=t;
        }

        if(a[y][x]=='#')
            continue;
        
        if(t>7||(y==0&&x==7))
            return 1;

        for(int i=0;i<9;i++){
            int ny=y+mv[i][0];
            int nx=x+mv[i][1];

            if(ny<0||nx<0||ny>7||nx>7||chk[t+1][ny][nx])
                continue;
            
            if(a[ny][nx]=='#')
                continue;
            
            q.push({t+1,ny,nx});
            chk[t+1][ny][nx]=true;
        }
    }


    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>a[i][j];
        }
    }
    
    cout<<bfs();
    return 0;
}