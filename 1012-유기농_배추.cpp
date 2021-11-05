#include<bits/stdc++.h>

using namespace std;

int T;
int M,N,K;
int input[51][51];
bool vst[51][51];
int cnt=0;
int y,x;

int my[4]={0,1,0,-1};
int mx[4]={1,0,-1,0};

void dfs(int ky, int kx){
    vst[ky][kx]=true;

    for(int i=0;i<4;i++){
        int ny=ky+my[i];
        int nx=kx+mx[i];

        if(ny<0||nx<0||ny>=N||nx>=M||input[ny][nx]==0||vst[ny][nx])
            continue;
        
        dfs(ny,nx);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        memset(input,0,sizeof(input));
        memset(vst,false,sizeof(vst));
        cnt=0;
        cin>>M>>N>>K;
        while(K--){
            cin>>x>>y;
            input[y][x]=1;
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(!vst[i][j]&&input[i][j]==1){
                    dfs(i,j);
                    cnt++;
                }
            }
        }


        cout<<cnt<<'\n';
    }
    


    return 0;
}