#include<iostream>
#include<vector>

using namespace std;

typedef struct Data{
    int m,s,d;
}dat;

int mv[8][2]={
    {0,-1},
    {1,-1},
    {1,0},
    {1,1},
    {0,1},
    {-1,1},
    {-1,0},
    {-1,-1},
};

int N,M,K;
vector<dat> maps[51][51];

void input(){
    int x,y,m,s,d;
    cin>>N>>M>>K;

    while(M--){
        cin>>y>>x>>m>>s>>d;
        --x;
        --y;
        
        maps[y][x].push_back({m,s,d});
    }
}

void chg_maps(vector<dat> tmps[51][51]){
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            maps[i][j]=tmps[i][j];
        }
    }
}

void move(){
    vector<dat> tmps[51][51];

    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            for(int k=0;k<maps[i][j].size();++k){
                dat d = maps[i][j][k];
                int ny=(i+mv[d.d][1]*d.s+N*1000)%N;
                int nx=(j+mv[d.d][0]*d.s+N*1000)%N;

                tmps[ny][nx].push_back(d);
            }
        }
    }
    chg_maps(tmps);
}

void sumFire(){
    vector<dat> tmps[51][51];

    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(maps[i][j].size()>1){
                int sums=0, summ=0;
                int sumd=maps[i][j][0].d%2;
                for(int k=0;k<maps[i][j].size();++k){
                    dat d = maps[i][j][k];
                    if((sumd==0&&d.d%2==1)||(sumd==1&&d.d%2==0)){
                        sumd=2;
                    }

                    sums+=d.s;
                    summ+=d.m;
                }

                if(summ/5==0)
                    continue;

                
                for(int d=sumd==2?1:0, sz=maps[i][j].size();d<8;d+=2){
                    tmps[i][j].push_back({summ/5,sums/sz,d});
                }
            }
            else{
                tmps[i][j]=maps[i][j];
            }
        }
    }

    chg_maps(tmps);
}

void solution(){
    while(K--){
        move();
        sumFire();
    }

    int summ=0;
    
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            for(int k=0;k<maps[i][j].size();++k){
                summ+=maps[i][j][k].m;
            }
        }
    }
    cout<<summ<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}