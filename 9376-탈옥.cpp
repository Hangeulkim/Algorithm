#include<bits/stdc++.h>

using namespace std;

int h,w,T;
char input[101][101];
vector<pair<int, int> > where;
int my[4]={1,-1,0,0};
int mx[4]={0,0,1,-1};
int dist[3][101][101];

void bfs(){
    for(int i=0;i<3;i++){
        int y=where[i].first;
        int x=where[i].second;

        deque<pair<int, int> > dq;
        dq.push_front({y,x});
        dist[i][y][x]=0;
        while(!dq.empty()){
            y=dq.front().first;
            x=dq.front().second;
            dq.pop_front();

            for(int j=0;j<4;j++){
                int ny=y+my[j];
                int nx=x+mx[j];

                if(ny<0||nx<0||ny>h+1||nx>w+1||dist[i][ny][nx]!=-1||input[ny][nx]=='*') continue;
                if(input[ny][nx]=='.'){
                    dist[i][ny][nx]=dist[i][y][x];
                    dq.push_front({ny,nx});
                }
                else if(input[ny][nx]=='#'){
                    dist[i][ny][nx]=dist[i][y][x]+1;
                    dq.push_back({ny,nx});
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>h>>w;
        memset(input,'.',sizeof(input));
        memset(dist,-1,sizeof(dist));
        where.clear();
        where.push_back({0,0});
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                cin>>input[i][j];
                if(input[i][j]=='$'){
                    where.push_back({i,j});
                    input[i][j]='.';
                }
            }
        }
        bfs();
        int result=987654321;

        for(int i=0;i<=h+1;i++){
            for(int j=0;j<=w+1;j++){
                if(input[i][j]=='*') continue;
                int sum=dist[0][i][j]+dist[1][i][j]+dist[2][i][j];
                if(input[i][j]=='#') sum-=2;
                result=min(result,sum);
            }
        }
        cout<<result<<'\n';
    }

    return 0;
}
