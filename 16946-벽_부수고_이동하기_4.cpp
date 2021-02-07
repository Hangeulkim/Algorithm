#include<bits/stdc++.h>

using namespace std;

int N,M;
int input[1001][1001];
int maps[1001][1001];
int result[1001][1001];
int chk[1001][1001];
bool vsk[1000001];
int my[4]={0,1,0,-1};
int mx[4]={1,0,-1,0};
char tmp;
int cnt=0;

typedef struct Dat{
    int y,x;
}dat;

void bfs(int i, int j){
    chk[i][j]=cnt;
    queue<dat> q,where;

    q.push({i,j});
    where.push({i,j});


    while(!q.empty()){
        int y=q.front().y;
        int x=q.front().x;

        q.pop();
        for(int m=0;m<4;m++){
            int ny=y+my[m];
            int nx=x+mx[m];

            if(ny<0||nx<0||ny>=N||nx>=M||chk[ny][nx]!=-1||input[ny][nx]==1)
                continue;

            chk[ny][nx]=cnt;
            q.push({ny,nx});
            where.push({ny,nx});
        }
    }

    int sz=where.size();
    while(!where.empty()){
        int y=where.front().y;
        int x=where.front().x;

        maps[y][x]=sz;
        where.pop();
    }

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    memset(maps,-1,sizeof(maps));
    memset(result,0,sizeof(result));
    memset(chk,-1,sizeof(chk));
    memset(vsk,false,sizeof(vsk));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>tmp;
            input[i][j]=tmp-'0';
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(input[i][j]==0&&maps[i][j]==-1){
                bfs(i,j);
                cnt++;
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(input[i][j]==1){
                for(int m=0;m<4;m++){
                    int ny=i+my[m];
                    int nx=j+mx[m];

                    if(ny<0||nx<0||ny>=N||nx>=M||maps[ny][nx]==-1||vsk[chk[ny][nx]])
                        continue;

                    vsk[chk[ny][nx]]=true;
                    result[i][j]+=maps[ny][nx];
                }
                result[i][j]=(result[i][j]+1)%10;
                for(int m=0;m<4;m++){
                    int ny=i+my[m];
                    int nx=j+mx[m];

                    if(ny<0||nx<0||ny>=N||nx>=M||maps[ny][nx]==-1)
                        continue;

                    vsk[chk[ny][nx]]=false;
                }
            }
            cout<<result[i][j];
        }
        cout<<'\n';
    }

    return 0;
}
