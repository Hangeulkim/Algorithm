#include<iostream>
#include<vector>

using namespace std;

typedef struct Dat{
    int y,x,m;
}dat;

int N,K;
int my[4]={0,0,-1,1};
int mx[4]={1,-1,0,0};
dat d[15];

vector<int> chess[15][15];
int pan[15][15];

int turn(){
    int cnt=0;
    while(cnt<1001){
        cnt++;

        for(int i=0;i<K;i++){
            int y=d[i].y;
            int x=d[i].x;
            int m=d[i].m;

            if(chess[y][x][0]!=i)
                continue;

            int ny=y+my[m];
            int nx=x+mx[m];

            if(pan[ny][nx]==2||ny<1||nx<1||ny>N||nx>N){
                 if(m==0)
                    m=1;
                else if(m==1)
                    m=0;
                else if(m==2)
                    m=3;
                else
                    m=2;
                
                d[i].m=m;

                ny=y+my[m];
                nx=x+mx[m];

                if(pan[ny][nx]==2||ny<1||nx<1||ny>N||nx>N)
                    continue;

                else if(pan[ny][nx]==0){
                    for(int j=0;j<chess[y][x].size();j++){
                        chess[ny][nx].push_back(chess[y][x][j]);
                        d[chess[y][x][j]].y=ny;
                        d[chess[y][x][j]].x=nx;
                    }
                    chess[y][x].clear();
                }
                else if(pan[ny][nx]==1){
                    for(int j=chess[y][x].size()-1;j>=0;j--){
                        chess[ny][nx].push_back(chess[y][x][j]);
                        d[chess[y][x][j]].y=ny;
                        d[chess[y][x][j]].x=nx;
                    }
                    chess[y][x].clear();
                }
            }
            else if(pan[ny][nx]==0){
                for(int j=0;j<chess[y][x].size();j++){
                    chess[ny][nx].push_back(chess[y][x][j]);
                    d[chess[y][x][j]].y=ny;
                    d[chess[y][x][j]].x=nx;
                }
                chess[y][x].clear();
            }
            else if(pan[ny][nx]==1){
                for(int j=chess[y][x].size()-1;j>=0;j--){
                    chess[ny][nx].push_back(chess[y][x][j]);
                    d[chess[y][x][j]].y=ny;
                    d[chess[y][x][j]].x=nx;
                }
                chess[y][x].clear();
            }

            if(chess[ny][nx].size()>=4)
                return cnt;
        }
    }

    if(cnt>1000)
        return -1;
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>K;

    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin>>pan[i][j];
    int x,y,m;

    for(int i=0;i<K;i++){
        cin>>y>>x>>m;
        d[i]={y,x,m-1};
        chess[y][x].push_back(i);
    }

    cout<<turn()<<'\n';

    return 0;
}