#include<bits/stdc++.h>

using namespace std;

char input[51][51];
int fy,fx;
int my[4]={0,1,0,-1};
int mx[4]={1,0,-1,0};
int chk[51][51];
int sy,sx;

bool dfs(int y, int x, char alp, int cnt){
    for(int m=0;m<4;m++){
        int ny=y+my[m];
        int nx=x+mx[m];

        if(ny<0||nx<0||ny>=fy||nx>=fx||alp!=input[ny][nx])
            continue;

        if(chk[ny][nx]==-1){
            chk[ny][nx]=m;
            bool ret=dfs(ny,nx,alp,cnt+1);
            chk[ny][nx]=-1;
            if(ret)
                return ret;
            continue;
        }

        if(sy==ny&&sx==nx&&cnt>=4)
            return true;
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(chk,-1,sizeof(chk));

    cin>>fy>>fx;
    for(int i=0;i<fy;i++){
        for(int j=0;j<fx;j++){
            cin>>input[i][j];
        }
    }

    for(int i=0;i<fy;i++){
        for(int j=0;j<fx;j++){
            chk[i][j]=0;
            sy=i;
            sx=j;
            if(dfs(i,j,input[i][j],1)){
                cout<<"Yes";
                return 0;
            }
        }
    }

    cout<<"No";
    return 0;
}
