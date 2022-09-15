#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int my[4]={-1,1,0,0};
int mx[4]={0,0,-1,1};

int N,K,R;
int road[101][101][4];
int cows[101][101];
bool chk[101][101];
bool meet[101];
int ret=0;

void input(){
    cin>>N>>K>>R;

    int r1,r2,c1,c2;
    for(int i=1;i<=R;i++){
        cin>>r1>>c1>>r2>>c2;
        
        for(int m=0;m<4;m++){
            if(r1+my[m] == r2 && c1+mx[m] == c2){
                road[r1][c1][m]=1;
                switch (m)
                {
                case 0:
                    road[r2][c2][1]=1;
                    break;
                
                case 1:
                    road[r2][c2][0]=1;
                    break;
                
                case 2:
                    road[r2][c2][3]=1;
                    break;
                
                case 3:
                    road[r2][c2][2]=1;
                    break;
                }
            }
        }
    }

    for(int i=1;i<=K;i++){
        cin>>r1>>c1;

        cows[r1][c1]=i;
    }
}

void bfs(int cow, int r, int c){
    fill(&meet[0],&meet[101],false);
    fill(&chk[0][0],&chk[100][101],false);
    queue<pair<int, int> > q;

    chk[r][c]=true;
    meet[cow]=true;
    q.push({r,c});
    ret+=K-1;

    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;

        q.pop();

        for(int m=0;m<4;m++){
            int ny=y+my[m];
            int nx=x+mx[m];

            if(ny<1||nx<1||ny>N||nx>N||road[y][x][m]||chk[ny][nx])
                continue;
            
            if(cows[ny][nx])
                ret--;
            
            chk[ny][nx]=true;
            q.push({ny,nx});
        }
    }
}

void solution(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(cows[i][j]!=0)
                bfs(cows[i][j],i,j);
        }
    }

    cout<<ret/2<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}