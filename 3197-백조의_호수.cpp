#include<bits/stdc++.h>

using namespace std;

int R,C;
char input[1502][1502];
bool visit[1502][1502], ivisit[1502][1502];
int ly1=0,lx1=0,ly2=0,lx2=0;
int my[4]={1,0,-1,0};
int mx[4]={0,1,0,-1};
queue<pair<int, int> > ice,nq,q;

bool bfs(){
    q=nq;

    while(!nq.empty())
        nq.pop();
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;

        q.pop();

        if(y==ly2&&x==lx2)
            return true;

        for(int i=0;i<4;i++){
            int ny=y+my[i];
            int nx=x+mx[i];

            if(ny<1||nx<1||ny>R||nx>C||visit[ny][nx])
                continue;

            visit[ny][nx]=true;

            if(input[ny][nx]=='X'){
                nq.push({ny,nx});
                continue;
            }

            q.push({ny,nx});

        }
    }


    return false;
}

void water(){
    int isz=ice.size();
    while(isz--){
        int y=ice.front().first;
        int x=ice.front().second;

        ice.pop();

        for(int i=0;i<4;i++){
            int ny=y+my[i];
            int nx=x+mx[i];

            if(ny<1||nx<1||ny>R||nx>C||ivisit[ny][nx])
                continue;

            if(input[ny][nx]=='X'){
                ice.push({ny,nx});
                ivisit[ny][nx]=true;
            }
        }
        input[y][x]='.';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(visit,false,sizeof(visit));
    memset(ivisit,false,sizeof(ivisit));
    cin>>R>>C;
    for(int y=1;y<=R;y++){
        for(int x=1;x<=C;x++){
            cin>>input[y][x];
            if(input[y][x]=='L'){
                if(ly1==0){
                    ly1=y;
                    lx1=x;
                    input[y][x]='.';
                }
                else{
                    ly2=y;
                    lx2=x;
                    input[y][x]='.';
                }
            }
        }
    }

    for(int y=1;y<=R;y++){
        for(int x=1;x<=C;x++){
            if(input[y][x]=='X'){
                for(int i=0;i<4;i++){
                    int ny=y+my[i];
                    int nx=x+mx[i];

                    if(ny<1||nx<1||ny>R||nx>C)
                        continue;

                    if(input[ny][nx]=='.'){
                        ice.push({y,x});
                        ivisit[y][x]=true;
                        break;
                    }
                }
            }
        }
    }

    int cnt=1;
    nq.push({ly1,lx1});
    visit[ly1][lx1]=true;
    while(1){
        water();
        if(bfs()){
            cout<<cnt<<'\n';
            break;
        }
        cnt++;
    }


    return 0;
}
