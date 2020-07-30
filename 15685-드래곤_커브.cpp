#include<bits/stdc++.h>

using namespace std;

typedef struct Data{
    int y;
    int x;
    int d;
}dat;

int mp[101][101];
vector<dat> dragon[21];
int N,y,x,d,g;
int cnt=0;

int my[4]={0,-1,0,1};
int mx[4]={1,0,-1,0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(mp,0,sizeof(mp));
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>x>>y>>d>>g;

        dragon[i].push_back({y,x,d});
        dragon[i].push_back({y+my[d],x+mx[d],d});
        for(int j=1;j<=g;j++){
             for(int sz=dragon[i].size()-1;sz>=1;sz--){
                 int nd=(dragon[i][sz].d+1)%4;
                 int ny=dragon[i][dragon[i].size()-1].y+my[nd];
                 int nx=dragon[i][dragon[i].size()-1].x+mx[nd];

                 dragon[i].push_back({ny,nx,nd});
             }
        }

        for(auto it : dragon[i]){
            mp[it.y][it.x]=1;
        }
    }

    for(y=0;y<100;y++){
        for(x=0;x<100;x++){
            if(mp[y][x]&&mp[y+1][x]&&mp[y][x+1]&&mp[y+1][x+1])
                cnt++;
        }
    }
    cout<<cnt<<'\n';

    return 0;
}
