#include<bits/stdc++.h>

using namespace std;

int N,M;
char input[252][252];
bool visit[252][252];
int my[4]={1,0,-1,0};
int mx[4]={0,1,0,-1};

void bfs(int y, int x){
    visit[y][x]=true;
    queue<pair<int, int> > q;
    vector<pair<int,int> > yang,wolf;

    q.push({y,x});
    while(!q.empty()){
        int nowy=q.front().first;
        int nowx=q.front().second;

        if(input[nowy][nowx]=='o')
            yang.push_back({nowy,nowx});
        else if(input[nowy][nowx]=='v')
            wolf.push_back({nowy,nowx});

        q.pop();

        for(int i=0;i<4;i++){
            int ny=nowy+my[i];
            int nx=nowx+mx[i];

            if(visit[ny][nx]||input[ny][nx]=='#')
                continue;



            visit[ny][nx]=true;
            q.push({ny,nx});
        }
    }

    if(yang.size()>wolf.size()){
        for(auto it : wolf)
            input[it.first][it.second]='.';
    }
    else{
        for(auto it : yang)
            input[it.first][it.second]='.';
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;
    memset(visit,false,sizeof(visit));
    memset(input,'#',sizeof(input));

    for(int y=1;y<=N;y++){
        for(int x=1;x<=M;x++){
            cin>>input[y][x];
        }
    }

    for(int y=1;y<=N;y++){
        for(int x=1;x<=M;x++){
            if(input[y][x]!='#'&&!visit[y][x])
                bfs(y,x);
        }
    }

    int yang=0,wolf=0;
    for(int y=1;y<=N;y++){
        for(int x=1;x<=M;x++){
            if(input[y][x]=='o'){
                yang++;
            }
            else if(input[y][x]=='v'){
                wolf++;
            }
        }
    }
    cout<<yang<<" "<<wolf<<'\n';

    return 0;
}
