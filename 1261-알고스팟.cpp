#include<bits/stdc++.h>

using namespace std;

typedef struct Data{
    int y;
    int x;
}data;

int N,M;
int input[101][101];
int visit[101][101];
int my[4]={1,-1,0,0};
int mx[4]={0,0,1,-1};

void bfs(){
    queue<data> q;

    q.push({1,1});
    visit[1][1]=0;
    while(!q.empty()){
        int y=q.front().y;
        int x=q.front().x;

        q.pop();

        for(int i=0;i<4;i++){
            int ny=y+my[i];
            int nx=x+mx[i];

            if(nx>0&&ny>0&&ny<=N&&nx<=M){
                if(visit[ny][nx]>visit[y][x]+input[ny][nx]){
                    visit[ny][nx]=visit[y][x]+input[ny][nx];
                    q.push({ny,nx});
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>M>>N;
    for(int i=1;i<=N;i++){
        string a;
        cin>>a;
        for(int j=1;j<=M;j++){
            input[i][j]=a[j-1]-'0';
            visit[i][j]=10001;
        }
    }
    bfs();
    cout<<visit[N][M]<<'\n';

    return 0;
}
