#include<bits/stdc++.h>

using namespace std;

int tc,N;
int sy,sx,ey,ex;
bool pan[301][301];

int my[8]={-1,-2,-2,-1,1,2,2,1};
int mx[8]={-2,-1,1,2,-2,-1,1,2};

typedef struct CHS{
    int y;
    int x;
    int cnt;
}chs;

int bfs(){
    queue<chs> chk;
    chk.push({sy,sx,0});
    pan[sy][sx]=true;
    while(!chk.empty()){
        int y=chk.front().y;
        int x=chk.front().x;
        int cnt=chk.front().cnt;

        if(y==ey&&x==ex)
            return cnt;

        chk.pop();

        for(int i=0;i<8;i++){
            int ny=y+my[i];
            int nx=x+mx[i];

            if(ny<0||nx<0||ny>=N||nx>=N||pan[ny][nx])
                continue;

            chk.push({ny,nx,cnt+1});
            pan[ny][nx]=true;
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cin>>N;
        cin>>sy>>sx>>ey>>ex;

        memset(pan,false,sizeof(pan));
        cout<<bfs()<<'\n';
    }

    return 0;
}
