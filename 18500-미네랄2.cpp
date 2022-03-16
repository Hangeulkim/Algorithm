#include<vector>
#include<iostream>
#include<queue>

using namespace std;

int C,R,N;
char mr[101][101];
int my[4]={0,1,0,-1};
int mx[4]={1,0,-1,0};
bool chk[101][101];

void sol(){
    queue<pair<int, int> > q;

    fill(&chk[0][0],&chk[100][101],false);
    for(int i=1;i<=R;i++){
        if(mr[1][i]=='x'){
            q.push({1,i});
            chk[1][i]=true;
        }
    }
    
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;

        q.pop();

        for(int m=0;m<4;m++){
            int ny=y+my[m];
            int nx=x+mx[m];

            if(chk[ny][nx]||ny<1||nx<1||ny>C||nx>R||mr[ny][nx]=='.')
                continue;
            
            q.push({ny,nx});
            chk[ny][nx]=true;
        }
    }

    vector<pair<int,int> > badak,all;

    for(int i=2;i<=C;i++){
        for(int j=1;j<=R;j++){
            if(!chk[i][j]&&mr[i][j]=='x'){
                if(mr[i-1][j]=='.'){
                    badak.push_back({i,j});
                }
                all.push_back({i,j});
            }
        }
    }

    int cnt=1,bflag=false;
    while(true&&!badak.empty()){
        for(int i=0;i<badak.size();i++){
            int y=badak[i].first;
            int x=badak[i].second;

            if((mr[y-cnt-1][x]=='x'&&chk[y-cnt-1][x])||y-cnt<=1){
                bflag=true;
                break;
            }
        }
        if(bflag)
            break;
        cnt++;
    }

    for(int i=0;i<all.size();i++){
        int y=all[i].first;
        int x=all[i].second;

        mr[y][x]='.';
        mr[y-cnt][x]='x';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>C>>R;
    for(int i=1;i<=C;i++){
        for(int j=1;j<=R;j++){
            cin>>mr[C-i+1][j];
        }
    }

    cin>>N;
    int f=1,k;
    while(N--){
        cin>>k;

        int x=f==1?1:R;
        while(x>=1&&x<=R){
            if(mr[k][x]=='x'){
                mr[k][x]='.';
                sol();
                break;
            }
            x+=f;
        }

        f=f==1?-1:1;
    }

    for(int i=1;i<=C;i++){
        for(int j=1;j<=R;j++){
            cout<<mr[C-i+1][j];
        }
        cout<<'\n';
    }

    return 0;
}