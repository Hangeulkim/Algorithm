#include<bits/stdc++.h>

using namespace std;

int N;
char input[102][102];
int all,n;
int my[4]={1,0,-1,0};
int mx[4]={0,-1,0,1};

void bfsall(){
    bool visit[102][102];
    memset(visit,false,sizeof(visit));

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(!visit[i][j]){
                queue<pair<int, int> > q;
                q.push({i,j});
                visit[i][j]=true;

                while (!q.empty()) {
                    int y=q.front().first;
                    int x=q.front().second;

                    q.pop();

                    for(int num=0;num<4;num++){
                        int ny=y+my[num];
                        int nx=x+mx[num];

                        if(!visit[ny][nx]&&input[ny][nx]==input[i][j]){
                            visit[ny][nx]=true;
                            q.push({ny,nx});
                        }
                    }
                }
                all++;
            }
        }
    }
}

void bfsnot(){
    bool visit[102][102];
    memset(visit,false,sizeof(visit));

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(!visit[i][j]){
                queue<pair<int, int> > q;
                q.push({i,j});
                visit[i][j]=true;

                while (!q.empty()) {
                    int y=q.front().first;
                    int x=q.front().second;

                    q.pop();

                    for(int num=0;num<4;num++){
                        int ny=y+my[num];
                        int nx=x+mx[num];

                        if(!visit[ny][nx]){
                            if((input[ny][nx]=='B'&&input[i][j]=='B')||((input[ny][nx]=='R'||input[ny][nx]=='G')&&(input[i][j]=='R'||input[i][j]=='G'))){
                                visit[ny][nx]=true;
                                q.push({ny,nx});
                            }
                        }
                    }
                }
                n++;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(input,' ',sizeof(input));
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>input[i][j];
        }
    }
    bfsall();
    bfsnot();
    cout<<all<<" "<<n<<'\n';

    return 0;
}
