#include<iostream>
#include<vector>
#include<deque>

using namespace std;

typedef struct Dat{
    int y,x,m;
}dat;

vector<dat> wh;
deque<int> m[15][15];

int color[15][15];
int my[5]={0,0,0,-1,1};
int mx[5]={0,1,-1,0,0};

int N,K;

void mv_white(deque<int> dq, int y, int x){
    while(!dq.empty()){
        int n=dq.front();
        dq.pop_front();

        m[y][x].push_back(n);
        wh[n].y=y;
        wh[n].x=x;
    }
}

void mv_red(deque<int> dq, int y, int x){
    while(!dq.empty()){
        int n=dq.back();
        dq.pop_back();

        m[y][x].push_back(n);
        wh[n].y=y;
        wh[n].x=x;
    }
}

bool mv(){
    for(int i=0;i<K;i++){
        int y=wh[i].y;
        int x=wh[i].x;
        int me=wh[i].m;

        deque<int> dq;
        while(m[y][x].back()!=i){
            dq.push_front(m[y][x].back());
            m[y][x].pop_back();
        }
        m[y][x].pop_back();
        dq.push_front(i);

        int ny=y+my[me];
        int nx=x+mx[me];

        if(ny<1||nx<1||ny>N||nx>N||color[ny][nx]==2){//ÆÄ¶û
            if(me==1)
                me=2;
            else if(me==2)
                me=1;
            else if(me==3)
                me=4;
            else if(me==4)
                me=3;
            ny=y+my[me];
            nx=x+mx[me];
            wh[i].m=me;

            if(ny<1||nx<1||ny>N||nx>N||color[ny][nx]==2){//ÆÄ¶û -> ÆÄ¶û
                ny=y;
                nx=x;

                mv_white(dq,ny,nx);
            }
            else if(color[ny][nx]==0){//ÆÄ¶û -> ÇÏ¾ç
                mv_white(dq,ny,nx);
            }
            else if(color[ny][nx]==1){//ÆÄ¶û -> »¡°­
                mv_red(dq,ny,nx);
            }
        }
        else if(color[ny][nx]==0){//ÇÏ¾ç
            mv_white(dq,ny,nx);
        }
        else if(color[ny][nx]==1){//»¡°­
            mv_red(dq,ny,nx);
        }
        

        if(m[ny][nx].size()>=4)
            return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int y,x,me;
    cin>>N>>K;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin>>color[i][j];

    for(int i=0;i<K;i++){
        cin>>y>>x>>me; 
        wh.push_back({y,x,me});
        m[y][x].push_back(i);
    }

    int cnt=0;
    while(++cnt<=1000){
        if(mv())
            break;
    }
    
    if(cnt>1000)
        cout<<-1<<'\n';
    else
        cout<<cnt<<'\n';

    return 0;
}
