#include<bits/stdc++.h>

using namespace std;

typedef struct St{
    int z;
    int y;
    int x;
    int day;
}st;

int N,M,H,max_num;
int input[101][101][101];
int test[101][101][101];
queue<st> bfs_arr;
bool chk[101][101][101]={false,};
int move_y[6]={1,-1,0,0,0,0};
int move_x[6]={0,0,1,-1,0,0};
int move_z[6]={0,0,0,0,1,-1};

int bfs(){
    while(!bfs_arr.empty()){
        int y=bfs_arr.front().y;
        int x=bfs_arr.front().x;
        int z=bfs_arr.front().z;
        int day=bfs_arr.front().day;

        if(bfs_arr.size()==1) max_num=day;

        for(int i=0;i<6;i++){
            int ny=y+move_y[i];
            int nx=x+move_x[i];
            int nz=z+move_z[i];

            if(ny>=1&&ny<=N&&nx>=1&&nx<=M&&nz>=1&&nz<=H&&!chk[nz][ny][nx]){
                chk[nz][ny][nx]=true;
                bfs_arr.push({nz,ny,nx,day+1});
                input[nz][ny][nx]=1;
                test[nz][ny][nx]=day+1;
            }
        }
        bfs_arr.pop();
    }

    for(int i=1;i<=H;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=M;k++){
                if(input[i][j][k]==0) return -1;
            }
        }
    }
    return max_num;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>M>>N>>H;

    for(int i=1;i<=H;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=M;k++){
                cin>>input[i][j][k];
                if(input[i][j][k]==1){
                    bfs_arr.push({i,j,k,0});
                    chk[i][j][k]=true;
                }
                else if(input[i][j][k]==-1) chk[i][j][k]=true;
            }
        }
    }

    cout<<bfs()<<'\n';

    return 0;
}
