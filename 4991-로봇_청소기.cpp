#include<bits/stdc++.h>

using namespace std;

typedef struct Data{
    int y;
    int x;
    int cnt;
}dat;

char input[21][21];
int dist[21][21];
int robotdist[11][11];
int my[4]={1,-1,0,0};
int mx[4]={0,0,1,-1};
vector<pair<int, int> > robot;
int h,w;
int munge=0;

void bfs(int sy, int sx){
    queue<dat> q;
    q.push({sy,sx,0});
    dist[sy][sx]=0;

    while(!q.empty()){
        int y=q.front().y;
        int x=q.front().x;
        int cnt=q.front().cnt;

        q.pop();

        for(int i=0;i<4;i++){
            int ny=y+my[i];
            int nx=x+mx[i];

            if(ny<1||nx<1||ny>h||nx>w||dist[ny][nx]!=-1||input[ny][nx]=='x')
                continue;

            q.push({ny,nx,cnt+1});
            dist[ny][nx]=cnt+1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //cout.tie(0);

    while(1){
        cin>>w>>h;
        int tmpy,tmpx;
        if(h==0&&w==0)
            break;

        munge=0;
        robot.clear();
        robot.push_back({0,0});
        for(int y=1;y<=h;y++){
            for(int x=1;x<=w;x++){
                cin>>input[y][x];
                if(input[y][x]=='o'){
                    robot[0]={y,x};
                }
                if(input[y][x]=='*'){
                    robot.push_back({y,x});
                    munge++;
                }
            }
        }

        vector<int> per;
        for(int i=0;i<munge+1;i++){
            memset(dist,-1,sizeof(dist));
            if(i>0)
                per.push_back(i);
            bfs(robot[i].first,robot[i].second);
            for(int j=i;j<munge+1;j++){
                robotdist[i][j]=dist[robot[j].first][robot[j].second];
                robotdist[j][i]=dist[robot[j].first][robot[j].second];
            }
        }

        bool cflag=false;
        int result=987654321;
        do {
            int sum=robotdist[0][per[0]];
            if(sum==-1){
                cflag=true;
                break;
            }
            for(int i=0;i<munge-1;i++){
                sum+=robotdist[per[i]][per[i+1]];
            }
            result=min(result,sum);
        } while(next_permutation(per.begin(),per.end()));
        if(cflag) cout<<-1<<'\n';
        else cout<<result<<'\n';
    }

    return 0;
}
