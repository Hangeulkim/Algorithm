#include<bits/stdc++.h>

using namespace std;

typedef struct Data{
    int y;
    int x;
    int cnt;
    bool where;
}dat;

int w,h;
char input[101][101];
bool visit[101][101];
int sy,sx,dy,dx;
int my[4]={1,-1,0,0};
int mx[4]={0,0,1,-1};

int bfs(){
    memset(visit,false,sizeof(visit));
    queue<dat> q;
    q.push({sy,sx,-1,true});//이전에 세로로 이동
    q.push({sy,sx,-1,false});//이전에 가로로 이동
    visit[sy][sx]=true;

    while(!q.empty()){
        int y=q.front().y;
        int x=q.front().x;
        int cnt=q.front().cnt;
        bool where=q.front().where;

        q.pop();

        if(y==dy&&x==dx)
            return cnt;

        if(where){
            for(int i=2;i<4;i++){
                int ny=y;
                int nx=x;

                while(ny<=h&&nx<=w){
                    ny+=my[i];
                    nx+=mx[i];

                    if(ny<1||nx<1||ny>h||nx>w||input[ny][nx]=='*')
                        break;

                    if(!visit[ny][nx]){
                        q.push({ny,nx,cnt+1,false});
                        visit[ny][nx]=true;
                    }
                }
            }
        }
        else{
            for(int i=0;i<2;i++){
                int ny=y;
                int nx=x;

                while(ny<=h&&nx<=w){
                    ny+=my[i];
                    nx+=mx[i];

                    if(ny<1||nx<1||ny>h||nx>w||input[ny][nx]=='*')
                        break;

                    if(!visit[ny][nx]){
                        q.push({ny,nx,cnt+1,true});
                        visit[ny][nx]=true;
                    }
                }
            }
        }

    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>w>>h;
    for(int y=1;y<=h;y++){
        for(int x=1;x<=w;x++){
            cin>>input[y][x];
            if(input[y][x]=='C'){
                if(sy==0){
                    sy=y;
                    sx=x;
                }
                else{
                    dy=y;
                    dx=x;
                }
            }
        }
    }
    cout<<bfs()<<'\n';


    return 0;
}
