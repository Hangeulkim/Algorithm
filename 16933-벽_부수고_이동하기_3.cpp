#include<bits/stdc++.h>

using namespace std;

int N,M,K;
int input[1001][1001];
bool chk[1001][1001][11];
int my[4]={0,1,0,-1};
int mx[4]={1,0,-1,0};
char tmp;

typedef struct Dat{
    int y,x,cnt,wall,date;
}dat;

int bfs(){
    for(int i=0;i<=K;i++)
        chk[0][0][i]=true;
    queue<dat> q;

    q.push({0,0,1,0,0});

    while(!q.empty()){
        int y=q.front().y;
        int x=q.front().x;
        int cnt=q.front().cnt;
        int wall=q.front().wall;
        int date=q.front().date;

        q.pop();

        if(y==N-1&&x==M-1)
            return cnt;

        for(int m=0;m<4;m++){
            int ny=y+my[m];
            int nx=x+mx[m];

            if(ny<0||nx<0||ny>=N||nx>=M)
                continue;

            if(input[ny][nx]==1){
                if(wall+1>K||chk[ny][nx][wall+1])
                    continue;

                if(date==1){
                    q.push({y,x,cnt+1,wall,0});
                    continue;
                }

                for(int i=wall+1;i<=K;i++)
                    chk[ny][nx][i]=true;
                q.push({ny,nx,cnt+1,wall+1,1});
            }

            else{
                if(chk[ny][nx][wall])
                    continue;
                for(int i=wall;i<=K;i++)
                    chk[ny][nx][i]=true;
                q.push({ny,nx,cnt+1,wall,date==1?0:1});
            }
        }
    }
    return -1;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M>>K;
    memset(chk,false,sizeof(chk));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>tmp;
            input[i][j]=tmp-'0';
        }
    }
    cout<<bfs();

    return 0;
}
