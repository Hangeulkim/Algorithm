#include<bits/stdc++.h>

using namespace std;

int N,M;
int input[1001][1001];
int arr[1001][1001];
int ret=0;
int my[4]={0,1,0,-1};
int mx[4]={1,0,-1,0};
bool chk[1001][1001];

typedef struct Dat{
    int y,x;
}dat;

void bfs(int y,int x){
    queue<dat> q,tmp;

    q.push({y,x});

    while(!q.empty()){
        int y=q.front().y;
        int x=q.front().x;

        q.pop();

        for(int m=0;m<4;m++){
            int ny=y+my[m];
            int nx=x+mx[m];

            if(ny<0||nx<0||ny>=N||nx>=M||chk[ny][nx]||input[ny][nx]==0)
                continue;

            q.push({ny,nx});
            tmp.push({ny,nx});
            chk[ny][nx]=true;
        }
    }

    int sz=tmp.size()+1;
    ret=max(ret,sz);

    while(!tmp.empty()){
        int y=tmp.front().y;
        int x=tmp.front().x;

        tmp.pop();
        chk[y][x]=false;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(arr,-1,sizeof(arr));
    memset(chk,false,sizeof(chk));
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>input[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(input[i][j]==0){
                chk[i][j]=true;
                bfs(i,j);
            }
        }
    }

    cout<<ret<<'\n';

    return 0;
}
