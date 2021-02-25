#include<bits/stdc++.h>

using namespace std;

int castle[10];
int S[10];
int ret[10];
int N,M,P;
char input[1001][1001];
bool chk[1001][1001];
int my[4]={0,1,0,-1};
int mx[4]={1,0,-1,0};

typedef struct Dat{
    int y,x,cnt;
}dat;

queue<dat> q[10];

void bfs(int num){
    char alp=num+'0';
    queue<dat> tmp;

    while(!q[num].empty()){
        int y=q[num].front().y;
        int x=q[num].front().x;
        int cnt=q[num].front().cnt;

        q[num].pop();

        if(cnt==S[num])
            continue;

        for(int m=0;m<4;m++){
            int ny=y+my[m];
            int nx=x+mx[m];
            int nc=cnt+1;

            if(ny<0||nx<0||ny>=N||nx>=M||input[ny][nx]!='.'||chk[ny][nx])
                continue;

            chk[ny][nx]=true;
            tmp.push({ny,nx,0});
            q[num].push({ny,nx,nc});
            input[ny][nx]=alp;
        }
    }

    while(!tmp.empty()){
        int y=tmp.front().y;
        int x=tmp.front().x;
        int cnt=tmp.front().cnt;

        tmp.pop();

        q[num].push({y,x,cnt});
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(chk,false,sizeof(chk));
    cin>>N>>M>>P;
    for(int i=1;i<=P;i++)
        cin>>S[i];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>input[i][j];
            if(input[i][j]!='.'&&input[i][j]!='#'){
                chk[i][j]=true;
                q[input[i][j]-'0'].push({i,j,0});
            }
        }
    }

    while(1){
        for(int i=1;i<=P;i++){
            bfs(i);
        }
        bool rflag=true;
        for(int i=1;i<=P;i++){
            if(!q[i].empty()){
                rflag=false;
                break;
            }
        }
        if(rflag)
            break;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(input[i][j]!='#'){
                ret[input[i][j]-'0']++;
            }
        }
    }
    for(int i=1;i<=P;i++){
        cout<<ret[i]<<" ";
    }

    return 0;
}
