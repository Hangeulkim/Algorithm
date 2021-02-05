#include<bits/stdc++.h>

using namespace std;

int N;
int r1,c1,r2,c2;

int mr[6]={-2,-2,0,0,2,2};
int mc[6]={-1,1,-2,2,-1,1};

bool chk[201][201];

typedef struct Dat{
    int r,c,cnt;
}dat;

int bfs(){
    queue<dat> q;
    chk[r1][c1]=true;
    q.push({r1,c1,0});

    while(!q.empty()){
        int r=q.front().r;
        int c=q.front().c;
        int cnt=q.front().cnt;

        q.pop();

        for(int i=0;i<6;i++){
            int nr=r+mr[i];
            int nc=c+mc[i];

            if(nr<0||nc<0||nr>=N||nc>=N||chk[nr][nc])    continue;
            if(nr==r2&&nc==c2) return cnt+1;
            q.push({nr,nc,cnt+1});
            chk[nr][nc]=true;
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(chk,false,sizeof(chk));
    cin>>N;
    cin>>r1>>c1>>r2>>c2;
    cout<<bfs();
}
