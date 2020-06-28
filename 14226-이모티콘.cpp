#include<bits/stdc++.h>

using namespace std;

typedef struct Data{
    int clip;
    int emoge;
    int time;
}data;

int S;
bool visit[1001][1001]={false,};
int bfs(){
    queue<data> q;

    q.push({0,1,0});
    visit[1][0]=true;
    while(!q.empty()){
        int clip=q.front().clip;
        int emoge=q.front().emoge;
        int time=q.front().time;

        q.pop();
        if(emoge==S)
            return time;

        if(emoge>0&&emoge<1001){
            if(!visit[emoge][emoge]){
                q.push({emoge,emoge,time+1});
                visit[emoge][emoge]=true;
            }

            if(!visit[emoge-1][clip]){
                q.push({clip,emoge-1,time+1});
                visit[emoge-1][clip]=true;
            }

            if(!visit[emoge+clip][clip]&&clip>0&&emoge+clip<1001){
                q.push({clip,emoge+clip,time+1});
                visit[emoge+clip][clip]=true;
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>S;

    cout<<bfs()<<'\n';

    return 0;
}
