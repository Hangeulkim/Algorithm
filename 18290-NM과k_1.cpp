#include<iostream>

using namespace std;

int N,M,K;
int input[15][15];
bool chk[15][15];
int ret=-87654321;
int my[4]={1,0,-1,0};
int mx[4]={0,1,0,-1};

bool chka(int y, int x){
    for(int m=0;m<4;m++){
        int ny=y+my[m];
        int nx=x+mx[m];

        if(chk[ny][nx])
            return true;
    }
    return chk[y][x];
}

void dfs(int y, int x, int cnt, int num){
    if(cnt==K){
        ret=max(ret,num);
        return;
    }

    for(int i=y;i<=N;i++){   
        if(i==y){
            for(int j=x;j<=M;j++){
                if(!chka(i,j)){
                    chk[i][j]=true;
                    dfs(i,j,cnt+1,num+input[i][j]);
                    chk[i][j]=false;
                }
            }
        }
        else{
            for(int j=1;j<=M;j++){
                if(!chka(i,j)){
                    chk[i][j]=true;
                    dfs(i,j,cnt+1,num+input[i][j]);
                    chk[i][j]=false;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M>>K;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>input[i][j];
        }
    }

    dfs(1,1,0,0);
    cout<<ret<<'\n';

    return 0;
}