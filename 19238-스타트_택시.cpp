#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

typedef struct D{
    int y, x, cnt;
}d;

struct compare{
    bool operator()(d &a, d &b){
        if(a.cnt==b.cnt){
            if(a.y==b.y)
                return a.x > b.x;
            return a.y > b.y;
        }
        return a.cnt > b.cnt;
    }
};

int my[4]={-1,0,0,1};
int mx[4]={0,-1,1,0};
int dat[401][2];
int N,M,S;
int arr[21][21];
bool chkarr[21][21];
int ty,tx;
int sy,sx,ey,ex,t;

void show(){
    cout<<S<<'\n';
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
}

void bfs(){
    priority_queue<d, vector<d>, compare> q;
    int c=0;

    q.push({ty,tx,0});

    fill(&chkarr[0][0],&chkarr[20][21],false);
    chkarr[ty][tx]=true;
    while(!q.empty()){
        int y=q.top().y;
        int x=q.top().x;
        int cnt=q.top().cnt;

        q.pop();

        if(arr[y][x]>=10){
            sy=y;
            sx=x;
            ty=y;
            tx=x;
            t=arr[y][x]/10;
            S-=cnt;
            while(!q.empty())
                q.pop();
            break;
        }

        for(int m=0;m<4;m++){
            int ny=y+my[m];
            int nx=x+mx[m];

            if(ny<1||nx<1||ny>N||nx>N||arr[ny][nx]==1||chkarr[ny][nx])
                continue;

            chkarr[ny][nx]=true;
            q.push({ny,nx,cnt+1});
        }
    }

    if(sy==-1)
        S=-1;
    if(S<=0)
        return ;

    fill(&chkarr[0][0],&chkarr[20][21],false);
    q.push({ty,tx,0});
    chkarr[ty][tx]=true;
    while(!q.empty()){
        int y=q.top().y;
        int x=q.top().x;
        int cnt=q.top().cnt;

        q.pop();

        if(dat[t][0]==y&&dat[t][1]==x){
            ey=y;
            ex=x;
            ty=y;
            tx=x;
            S-=cnt;
            c=cnt;
            break;
        }

        for(int m=0;m<4;m++){
            int ny=y+my[m];
            int nx=x+mx[m];

            if(ny<1||nx<1||ny>N||nx>N||arr[ny][nx]==1||chkarr[ny][nx])
                continue;

            chkarr[ny][nx]=true;
            q.push({ny,nx,cnt+1});
        }
    }

    if(ey==-1)
        S=-1;

    if(S<0)
        return ;
    arr[sy][sx]=0;
    S+=c*2;
}

bool chkp(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(arr[i][j]>=10)
                return true;
        }
    }
    return false;
}

bool chk(){
    if(S<0)
        return true;
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(arr[i][j]>=10)
                return true;
        }
    }
    return false;
}

void func(){
    while(S>=1&&chkp()){
        //show();
        sy=sx=ey=ex=-1;
        bfs();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M>>S;
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>arr[i][j];
        }
    }
    cin>>ty>>tx;
    for(int i=1;i<=M;i++){
        cin>>sy>>sx>>ey>>ex;
        arr[sy][sx]=i*10;
        dat[i][0]=ey;
        dat[i][1]=ex;
    }
    
    func();

    if(chk())
        cout<<-1<<'\n';
    else
        cout<<S<<'\n';

    return 0;
}