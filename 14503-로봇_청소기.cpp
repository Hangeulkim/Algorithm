#include<bits/stdc++.h>

using namespace std;

int input[52][52];
int cnt=0;
int mv[4][2]={{0,-1},
            {1,0},
            {0,1},
            {-1,0}};
int N,M,r,c,d;

void dfs(int y, int x, int m){
    if(input[y][x]==0){
        cnt++;
        input[y][x]=2;
    }

    for(int i=0;i<4;i++){
        int nd=(m+3-i)%4;
        int ny=y+mv[nd][1];
        int nx=x+mv[nd][0];

        if(input[ny][nx]==0){
            dfs(ny,nx,nd);
            return;
        }
    }

    int ny=y-mv[m][1];
    int nx=x-mv[m][0];
    if(input[ny][nx]==1)
        return;
    dfs(ny,nx,m);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0;i<52;i++){
        for(int j=0;j<52;j++){
            input[i][j]=1;
        }
    }

    cin>>N>>M;
    cin>>r>>c>>d;
    r++;
    c++;

    for(int y=1;y<=N;y++){
        for(int x=1;x<=M;x++){
            cin>>input[y][x];
        }
    }

    dfs(r,c,d);
    cout<<cnt<<'\n';

    return 0;
}
