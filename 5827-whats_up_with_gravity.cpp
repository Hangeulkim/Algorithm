#include<iostream>
#include<queue>
#include<algorithm>
#include<climits>

using namespace std;

//g는 중력의 방향 c는 flip의 횟수
typedef struct Dat{
    int y,x,g,c;
}d;

struct compare{
    bool operator()(d &a, d&b){
        return a.c > b.c;
    }
};

int md[2]={1,-1};

char map[501][501];
int dist[501][501][2];
int sy,sx;
int N,M;

void initialize(){
    fill(&dist[0][0][0],&dist[500][500][2],INT_MAX);
}

void input(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
            if(map[i][j]=='C'){
                map[i][j]='.';
                sy=i;
                sx=j;
            }
        }
    }
}

int bfs(){
    priority_queue<d,vector<d>,compare> pq;

    while(sy>=0&&sy<N&&map[sy+1][sx]!='#'){
        if(map[sy+1][sx]=='D')
            return 0;
        dist[sy][sx][0]=0;
        ++sy;
    }
    pq.push({sy,sx,0,0});

    while(!pq.empty()){
        int y=pq.top().y;
        int x=pq.top().x;
        int g=pq.top().g;
        int c=pq.top().c;


        pq.pop();

        if(dist[y][x][g] < c)
            continue;

        if(map[y][x]=='D')
            return c;

        int mg=md[g];
        if(y+mg>=0 && y+mg<N && map[y+mg][x]=='#'){
            for(int m=0;m<2;m++){
                int ny=y;
                int nx=x+md[m];

                if(nx<0||nx>=M||map[ny][nx]=='#'||dist[ny][nx][g]<=c)
                    continue;

                dist[ny][nx][g]=c;
                pq.push({ny,nx,g,c});
            }

            int tg = g==0?1:0;
            int ty = y + md[g];
            if(ty<0||ty>N-1||dist[ty][x][tg]<=c+1)
                continue;

            dist[ty][x][tg]=c+1;
            pq.push({ty,x,tg,c+1});
        }

        y = y+mg;
        if(y<0||y>=N||dist[y][x][g]<=c||map[y][x]=='#')
            continue;

        dist[y][x][g]=c;
        pq.push({y,x,g,c});
    }

    return -1;
}

void solution(){
    int ret=bfs();
    cout<<ret<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    initialize();
    input();
    solution();

    return 0;
}