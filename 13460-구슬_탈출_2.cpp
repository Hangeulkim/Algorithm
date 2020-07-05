#include<bits/stdc++.h>

using namespace std;

typedef struct Data{
    int Ry,Rx,By,Bx;
    int cnt;
}dat;

int N,M;
char input[11][11];
bool visit[11][11][11][11];
int Ry,Rx,By,Bx;
int my[4]={-1,1,0,0};
int mx[4]={0,0,1,-1};

int bfs(){
    queue<dat> q;
    q.push({Ry,Rx,By,Bx,0});
    visit[Ry][Rx][By][Bx]=true;

    while(!q.empty()){
        int ry=q.front().Ry;
        int rx=q.front().Rx;
        int by=q.front().By;
        int bx=q.front().Bx;
        int cnt=q.front().cnt;

        q.pop();
        if(cnt>=10)
            break;

        for(int i=0;i<4;i++){
            int nry=ry,nrx=rx,nby=by,nbx=bx,r=0,b=0;
            while(input[nry+my[i]][nrx+mx[i]]!='#'&&input[nry][nrx]=='.'){
                nry+=my[i];
                nrx+=mx[i];
                r++;
            }

            while(input[nby+my[i]][nbx+mx[i]]!='#'&&input[nby][nbx]=='.'){
                nby+=my[i];
                nbx+=mx[i];
                b++;
            }

            if(input[nby][nbx]=='O') continue;
            if(input[nry][nrx]=='O'){
                return cnt+1;
            }
            if(nry==nby&&nrx==nbx){
                if(r>b){
                    nry-=my[i];
                    nrx-=mx[i];
                }
                else{
                    nby-=my[i];
                    nbx-=mx[i];
                }
            }
            if(!visit[nry][nrx][nby][nbx]){
                visit[nry][nrx][nby][nbx]=true;
                q.push({nry,nrx,nby,nbx,cnt+1});
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>input[i][j];
            if(input[i][j]=='R'){
                Ry=i;
                Rx=j;
            }
            if(input[i][j]=='B'){
                By=i;
                Bx=j;
            }
        }
    }
    input[Ry][Rx]='.';
    input[By][Bx]='.';
    cout<<bfs()<<'\n';

    return 0;
}
