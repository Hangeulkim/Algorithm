#include<bits/stdc++.h>

using namespace std;

bool chk[500001][2];
int N,K;

typedef struct Dat{
    int x,c,d;
}dat;

int bfs(){
    queue<dat> q;
    q.push({N,0,K});
    chk[N][0]=true;

    while(!q.empty()){
        int x=q.front().x;
        int c=q.front().c;
        int d=q.front().d;

        q.pop();

        if(x==d||chk[d][c%2])
            return c;

        if(d+c+1>500000)
            continue;

        int nx=x+1;
        int num=(c+1)%2;
        if(nx<=500000&&!chk[nx][num]){
            chk[nx][num]=true;
            q.push({nx,c+1,d+c+1});
        }
        nx=x-1;
        if(nx>=0&&!chk[nx][num]){
            chk[nx][num]=true;
            q.push({nx,c+1,d+c+1});
        }
        nx=x*2;
        if(nx<=500000&&!chk[nx][num]){
            chk[nx][num]=true;
            q.push({nx,c+1,d+c+1});
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(chk,false,sizeof(chk));
    cin>>N>>K;
    cout<<bfs();

    return 0;
}
