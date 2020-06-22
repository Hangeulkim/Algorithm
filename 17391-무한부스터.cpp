#include<bits/stdc++.h>

using namespace std;

typedef struct St{
    int y;
    int x;
    int cnt;
}st;

int N,M,tmp;
int boost[301][301];
queue<st> bfs_arr;
bool chk[301][301];

int bfs(){
    bfs_arr.push({1,1,0});
    chk[1][1]=true;
    while(!bfs_arr.empty()){
        int y=bfs_arr.front().y;
        int x=bfs_arr.front().x;
        int cnt=bfs_arr.front().cnt;

        chk[y][x]=true;
        if(y==N&&x==M){
            return cnt;
        }

        for(int i=1;i<=boost[y][x];i++){
            int ny=y+i;
            int nx=x+i;
            if(ny<=N&&!chk[ny][x]){
                chk[ny][x]=true;
                bfs_arr.push({ny,x,cnt+1});
            }
            if(nx<=M&&!chk[y][nx]){
                chk[y][nx]=true;
                bfs_arr.push({y,nx,cnt+1});
            }
        }

        bfs_arr.pop();
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>tmp;
            boost[i][j]=tmp;
        }
    }

    cout<<bfs()<<'\n';

    return 0;
}
