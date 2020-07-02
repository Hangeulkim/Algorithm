#include<bits/stdc++.h>

using namespace std;

int R,C;
int my[4]={1,-1,0,0};
int mx[4]={0,0,1,-1};
bool visit[256]={false,};
char input[21][21];
int result=0;

int dfs(int y, int x, int cnt){
    int tmp=cnt;
    visit[input[y][x]]=true;
    for(int i=0;i<4;i++){
        int ny=y+my[i];
        int nx=x+mx[i];

        if(!visit[input[ny][nx]]&&ny>0&&ny<=R&&nx>0&&nx<=C){
            visit[input[ny][nx]]=true;
            result=max(result,dfs(ny,nx,cnt+1));
            visit[input[ny][nx]]=false;
        }
    }
    result=max(result,cnt);
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>R>>C;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin>>input[i][j];
        }
    }

    dfs(1,1,1);
    cout<<result<<'\n';

    return 0;
}
