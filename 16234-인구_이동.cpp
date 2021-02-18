#include<bits/stdc++.h>

using namespace std;

int N,L,R;
int A[51][51];
bool chk[51][51];
int my[4]={0,1,0,-1};
int mx[4]={1,0,-1,0};
int date=0;

typedef struct Dat{
    int y,x;
}dat;

void bfs(int y, int x, int ny, int nx){
    int sum=A[y][x]+A[ny][nx];
    queue<dat> q;
    queue<dat> chg;

    q.push({y,x});
    q.push({ny,nx});
    chg.push({y,x});
    chg.push({ny,nx});

    while(!q.empty()){
        int nowy=q.front().y;
        int nowx=q.front().x;

        q.pop();

        for(int m=0;m<4;m++){
            int nexty=my[m]+nowy;
            int nextx=mx[m]+nowx;

            if(nexty<0||nextx<0||nexty>=N||nextx>=N||chk[nexty][nextx]) continue;

            int moving=abs(A[nowy][nowx]-A[nexty][nextx]);
            if(moving>=L&&moving<=R){
                chk[nexty][nextx]=true;
                q.push({nexty,nextx});
                chg.push({nexty,nextx});
                sum+=A[nexty][nextx];
            }
        }
    }

    int num=sum/chg.size();
    while(!chg.empty()){
        int nowy=chg.front().y;
        int nowx=chg.front().x;

        chg.pop();

        A[nowy][nowx]=num;
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>L>>R;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>A[i][j];
        }
    }

    while(1){
        int cnt=0;
        date++;
        memset(chk,false,sizeof(chk));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(chk[i][j]) continue;
                for(int m=0;m<4;m++){
                    int ny=my[m]+i;
                    int nx=mx[m]+j;

                    if(ny<0||nx<0||ny>=N||nx>=N||chk[ny][nx]) continue;

                    int moving=abs(A[i][j]-A[ny][nx]);
                    if(moving>=L&&moving<=R){
                        chk[i][j]=true;
                        chk[ny][nx]=true;
                        bfs(i,j,ny,nx);
                        cnt++;
                        break;
                    }
                }
            }
        }
        if(cnt==0){
            date--;
            break;
        }
    }


    cout<<date<<'\n';

    return 0;
}
