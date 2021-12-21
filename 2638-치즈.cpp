#include<bits/stdc++.h>

using namespace std;

int n,m;
int input[101][101];
int my[4]={0,1,0,-1};
int mx[4]={1,0,-1,0};
int chk[101][101];
int cnt=0;

bool allchk(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(input[i][j])
                return true;
        }
    }
    return false;
}

void bfs(){
    cnt++;
    queue<pair<int, int> > q;
    memset(chk,0,sizeof(chk));

    q.push({1,1});

    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;

        q.pop();

        for(int i=0;i<4;i++){
            int ny=y+my[i];
            int nx=x+mx[i];

            if(ny<1||nx<1||ny>n||nx>m||(input[ny][nx]==0&&chk[ny][nx]))
                continue;

            chk[ny][nx]++;

            if(input[ny][nx])
                continue;
            
            q.push({ny,nx});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(input[i][j]&&chk[i][j]>=2)
                input[i][j]=0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>input[i][j];
        }
    }
    while(allchk())
        bfs();
    cout<<cnt;


    return 0;
}