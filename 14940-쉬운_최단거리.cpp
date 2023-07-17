#include<iostream>
#include<queue>

using namespace std;

int sy,sx, n, m;
bool ground[1001][1001];
int chk[1001][1001];
int my[4] = {0,1,0,-1};
int mx[4] = {1,0,-1,0};

typedef struct data{
    int y, x, cnt;
}d;

void input(){
    int a;
    cin>>n>>m;

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>a;

            chk[i][j] = -1;
            if(a == 2){
                sy = i;
                sx = j;
            }

            ground[i][j] = a > 0;
        }
    }
}

void bfs(){
    queue<d> q;

    q.push({sy,sx,0});
    chk[sy][sx]=0;

    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int cnt = q.front().cnt;

        q.pop();

        for(int i=0;i<4;++i){
            int ny = y+my[i];
            int nx = x+mx[i];

            if(ny<0||nx<0||ny>=n||nx>=m||chk[ny][nx] != -1||!ground[ny][nx])
                continue;
            
            chk[ny][nx] = cnt+1;
            q.push({ny,nx,cnt+1});
        }
    }
}

void solution(){
    bfs();

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(!ground[i][j])
                cout<<ground[i][j]<<" ";
            else
                cout<<chk[i][j]<<" ";
        }
        cout<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}