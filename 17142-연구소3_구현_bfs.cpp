#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct Dat{
    int y,x,c;
}dat;

int my[4]={0,1,0,-1};
int mx[4]={1,0,-1,0};
int N, M;
int arr[51][51];
int chk[51][51];

int bfs(queue<dat> q, int vr){
    int t=0;

    while(!q.empty()&&vr){
        int y = q.front().y;
        int x = q.front().x;
        int c = q.front().c;

        q.pop();

        for(int m=0;m<4;m++){
            int ny=y+my[m];
            int nx=x+mx[m];

            if(ny<0||nx<0||ny>=N||nx>=N||chk[ny][nx]>=0)
                continue;

            if(chk[ny][nx]==-1)
                vr--;
            q.push({ny,nx,c+1});
            chk[ny][nx]=c+1;
            t=max(t,c+1);
        }
    }

    if(vr)
        t=987654321;

    return t;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ret=987654321;
    int cnt=0;
    vector<int> comb;
    vector<pair<int,int> > virus;

    cin>>N>>M;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
            if(arr[i][j]==2){
                virus.push_back({i,j});
                arr[i][j]=-2;
            }
                
            else if(arr[i][j]==0){
                arr[i][j]=-1;
                cnt++;
            }
        }
    }

    int sz = virus.size();
    for(int i=0;i<sz;i++){
        if(i<M)
            comb.push_back(0);
        else
            comb.push_back(1);
    }

    do
    {   
        int vr=cnt;
        queue<dat> q;
        copy(&arr[0][0],&arr[50][51],&chk[0][0]);
        
        
        for(int i=0;i<sz;i++){
            int y=virus[i].first;
            int x=virus[i].second;
            if(!comb[i]){
                q.push({y,x,0});
                chk[y][x]=0;
            }
                
        }

        int t=bfs(q,vr);

        ret=min(t,ret);

    } while (next_permutation(comb.begin(),comb.end()));
    
    if(ret==987654321)
        ret=-1;
    cout<<ret<<'\n';

    return 0;
}