#include<bits/stdc++.h>

using namespace std;

typedef struct Data{
    int y;
    int x;
    int t;
}data;

int R,C;
char input[101][101];
bool visit[101][101];
vector<pair<int, int> > w;
int my[4]={1,-1,0,0};
int mx[4]={0,0,1,-1};

void water(){
    vector<pair<int, int> > wa;
    for(auto it : w){
        for(int i=0;i<4;i++){
            int ny=it.first+my[i];
            int nx=it.second+mx[i];

            if(ny>0&&nx>0&&ny<=R&&nx<=C&&input[ny][nx]=='.'){
                input[ny][nx]='*';
                wa.push_back({ny,nx});
            }
        }
    }
    w.assign(wa.begin(),wa.end());
}

int bfs(int sy, int sx, int dy, int dx){
    queue<data> q;

    int cnt=0;
    q.push({sy,sx,0});
    visit[sy][sx]=true;
    water();

    while(!q.empty()){
        int y=q.front().y;
        int x=q.front().x;
        int t=q.front().t;

        q.pop();

        if(y==dy&&x==dx){
            return t;
        }

        if(t>cnt){
            water();
            cnt=t;
        }

        for(int i=0;i<4;i++){
            int ny=y+my[i];
            int nx=x+mx[i];

            if(ny>0&&nx>0&&ny<=R&&nx<=C&&(input[ny][nx]=='.'||input[ny][nx]=='D')&&!visit[ny][nx]){
                visit[ny][nx]=true;
                q.push({ny,nx,t+1});
            }
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>R>>C;
    int sy,sx,dy,dx,result;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin>>input[i][j];
            visit[i][j]=false;
            if(input[i][j]=='S'){
                sy=i;
                sx=j;
            }

            if(input[i][j]=='D'){
                dy=i;
                dx=j;
            }

            if(input[i][j]=='*'){
                w.push_back({i,j});
            }
        }
    }
    result=bfs(sy,sx,dy,dx);

    if(result==-1)
        cout<<"KAKTUS"<<'\n';
    else
        cout<<result<<'\n';

    return 0;
}
