#include<bits/stdc++.h>

using namespace std;

char input[10][10];
int N,M;
int result=0;
int my[4]={1,0,-1,0};
int mx[4]={0,1,0,-1};

void find(){
    char tmp[10][10];
    bool visit[10][10]={false,};
    int cnt=0;

    for(int y=0;y<=N+1;y++){
        for(int x=0;x<=M+1;x++){
            tmp[y][x]=input[y][x];
        }
    }

    for(int y=1;y<=N;y++){
        for(int x=1;x<=M;x++){
            if(!visit[y][x]&&tmp[y][x]=='2'){
                visit[y][x]=true;
                queue<pair<int, int> > q;
                q.push({y,x});
                while(!q.empty()){
                    int wy=q.front().first;
                    int wx=q.front().second;

                    q.pop();

                    for(int i=0;i<4;i++){
                        int ny=wy+my[i];
                        int nx=wx+mx[i];

                        if(!visit[ny][nx]&&tmp[ny][nx]!='1'){
                            visit[ny][nx]=true;
                            tmp[ny][nx]='2';
                            q.push({ny,nx});
                        }
                    }
                }
            }
        }
    }

    for(int y=1;y<=N;y++){
        for(int x=1;x<=M;x++){
            if(tmp[y][x]=='0')
                cnt++;
        }
    }

    result=max(result,cnt);
}

void dfs(int y,int x, int cnt){
    if(cnt==3){
        find();
        return;
    }

    for(int tx=x+1;tx<=M;tx++){
        if(input[y][tx]=='0'){
            input[y][tx]='1';
            dfs(y,tx,cnt+1);
            input[y][tx]='0';
        }
    }

    for(int ty=y+1;ty<=N;ty++){
        for(int tx=1;tx<=M;tx++){
            if(input[ty][tx]=='0'){
                input[ty][tx]='1';
                dfs(ty,tx,cnt+1);
                input[ty][tx]='0';
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    memset(input,'1',sizeof(input));
    for(int y=1;y<=N;y++){
        for(int x=1;x<=M;x++){
            cin>>input[y][x];
        }
    }

    for(int y=1;y<=N;y++){
        for(int x=1;x<=M;x++){
            if(input[y][x]=='0'){
                input[y][x]='1';
                dfs(y,x,1);
                input[y][x]='0';
            }
        }
    }
    cout<<result<<'\n';

    return 0;
}
