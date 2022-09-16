#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

typedef struct Data{
    int y,x,cost;
}d;

struct compare{
    bool operator()(d &a, d &b){
        return a.cost > b.cost;
    }
};

int my[4]={0,1,0,-1};
int mx[4]={1,0,-1,0};

int R,C;
char map[55][55];
int chk[1 << 17][20];
int visit_map[55][55];
int dist[20][20];
int cnt=1;

void input(){
    cin>>R>>C;

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>map[i][j];
        }
    }
}

void make_island(int y, int x, int num){
    map[y][x]=num;
    for(int m=0;m<4;m++){
        int ny=y+my[m];
        int nx=x+mx[m];

        if(ny<0||nx<0||ny>=R||nx>=C||map[ny][nx]!='X')
            continue;
        
        make_island(ny,nx,num);
    }
}

void connect_island(){
    fill(&dist[1][0],&dist[19][20],INT_MAX);
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(map[i][j]=='X'){
                make_island(i,j,cnt);
                cnt++;
            }
        }
    }
}

void make_map(int sy, int sx, int cow){
    fill(&visit_map[0][0],&visit_map[54][55],INT_MAX);
    priority_queue<d, vector<d>, compare> q;

    visit_map[sy][sx]=0;
    dist[cow][cow]=0;
    q.push({sy,sx,0});

    while(!q.empty()){
        int y = q.top().y;
        int x = q.top().x;
        int cost = q.top().cost;

        q.pop();

        if(visit_map[y][x] < cost)
            continue;

        if(map[y][x] < cnt)
            dist[cow][map[y][x]] = min(cost, dist[cow][map[y][x]]);

        for(int m=0;m<4;m++){
            int ny = y+my[m];
            int nx = x+mx[m];

            if(ny<0||nx<0||ny>=R||nx>=C||map[ny][nx]=='.')
                continue;

            int ncost = cost + (map[ny][nx] == 'S');

            if(visit_map[ny][nx] > ncost){
                visit_map[ny][nx] = ncost;
                q.push({ny,nx,ncost});
            }
        }
    }
}

int tsp(int vst, int now){
    if(chk[vst][now] != 0 ) return chk[vst][now];
    if(vst == (1 << cnt) -1) return chk[vst][now] = 0;

    int ret = INT_MAX;
    for(int i=1;i<cnt;i++){
        if(vst & (1 << i)) continue;
        ret = min(ret, tsp((vst | (1 << i)), i) + dist[now][i]);
    }

    return chk[vst][now] = ret;
}

void solution(){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(map[i][j]<cnt && dist[map[i][j]][map[i][j]]!=0){
                make_map(i,j,map[i][j]);
            }
        }
    }


    cout<<tsp(1,0)<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    connect_island();
    solution();

    return 0;
}