#include<bits/stdc++.h>

using namespace std;

int N,M;
char input[32][32];
bool visit[32][32];
int my[4]={0,1,0,-1};
int mx[4]={1,0,-1,0};
int num=0,result=0,who=0;

void dfs(int y, int x, int vs, int cnt){
    if(vs==num){
        result=min(result,cnt);
        return ;
    }
    for(int i=0;i<4;i++){
        int ny=y+my[i];
        int nx=x+mx[i];
        int mc=0;

        if(visit[ny][nx]||input[ny][nx]=='*')
            continue;
        vector<pair<int, int> > m;
        while(!visit[ny][nx]&&input[ny][nx]=='.'){
            m.push_back({ny,nx});
            visit[ny][nx]=true;
            mc++;
            ny+=my[i];
            nx+=mx[i];
        }
        dfs(ny-my[i],nx-mx[i],vs+mc,cnt+1);
        for(auto it : m){
            visit[it.first][it.second]=false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin>>N>>M){
        who++;
        memset(input,'*',sizeof(input));
        memset(visit,false,sizeof(visit));
        num=0,result=987654321;

        for(int y=1;y<=N;y++){
            for(int x=1;x<=M;x++){
                cin>>input[y][x];
                if(input[y][x]=='.')
                    num++;
            }
        }

        for(int y=1;y<=N;y++){
            for(int x=1;x<=M;x++){
                if(input[y][x]=='.'){
                    visit[y][x]=true;
                    dfs(y,x,1,0);
                    visit[y][x]=false;
                }
            }
        }

        cout<<"Case "<<who<<": ";
        if(result==987654321)
            cout<<-1<<'\n';
        else
            cout<<result<<'\n';
    }


    return 0;
}
