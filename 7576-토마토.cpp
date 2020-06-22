#include<bits/stdc++.h>

using namespace std;

typedef struct St{
    int y;
    int x;
    int day;
}st;

int N,M,max_num;
int input[1001][1001];
int test[1001][1001];
queue<st> bfs_arr;
bool chk[1001][1001]={false,};
int move_y[4]={1,-1,0,0};
int move_x[4]={0,0,1,-1};

int bfs(){
    while(!bfs_arr.empty()){
        int y=bfs_arr.front().y;
        int x=bfs_arr.front().x;
        int day=bfs_arr.front().day;

        if(bfs_arr.size()==1) max_num=day;

        for(int i=0;i<4;i++){
            int ny=y+move_y[i];
            int nx=x+move_x[i];

            if(ny>=1&&ny<=N&&nx>=1&&nx<=M&&input[ny][nx]==0&&!chk[ny][nx]){
                chk[ny][nx]=true;
                bfs_arr.push({ny,nx,day+1});
                input[ny][nx]=1;
                test[ny][nx]=day+1;
            }
        }
        bfs_arr.pop();
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(input[i][j]==0) return -1;
        }
    }
    return max_num;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>M>>N;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>input[i][j];
            if(input[i][j]==1){
                bfs_arr.push({i,j,0});
                chk[i][j]=true;
            }
            else if(input[i][j]==-1) chk[i][j]=true;
        }
    }

    cout<<bfs()<<'\n';

    return 0;
}
