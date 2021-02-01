#include<bits/stdc++.h>

using namespace std;

typedef struct Dat{
    int where;
    int cnt;
}dat;

int chk[101];
int sadari[101];
int snake[101];
int N,M;
int x,y;

int bfs(){
    queue<dat> q;
    q.push({1,0});
    chk[1]=0;

    while(!q.empty()){
        int cnt=q.front().cnt;
        int where=q.front().where;

        q.pop();

        for(int i=1;i<7;i++){
            int nn=where+i;
            if(chk[nn]!=-1) continue;

            if(sadari[nn]!=-1){
                nn=sadari[nn];
                if(chk[nn]!=-1) continue;
            }
            else if(snake[nn]!=-1){
                nn=snake[nn];
                if(chk[nn]!=-1) continue;
            }
            if(nn>=100)
                return cnt+1;
            chk[nn]=cnt+1;
            q.push({nn,cnt+1});
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(chk,-1,sizeof(chk));
    memset(sadari,-1,sizeof(sadari));
    memset(snake,-1,sizeof(snake));
    cin>>N>>M;

    while(N--){
        cin>>x>>y;
        sadari[x]=y;
    }
    while(M--){
        cin>>x>>y;
        snake[x]=y;
    }

    cout<<bfs();

    return 0;
}
