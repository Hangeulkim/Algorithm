#include<bits/stdc++.h>

using namespace std;

int F,S,G,U,D;
int result=-1;
bool visit[2000001];

bool bfs(){
    queue<pair<int,int> > q;
    q.push({S,0});
    visit[S]=true;
    while(!q.empty()){
        int cnt=q.front().second;
        int stair=q.front().first;

        q.pop();

        if(stair==G){
            result=cnt;
            return true;
        }

        int ns=stair+U;
        if(!visit[ns]&&ns<=F){
            visit[ns]=true;
            q.push({ns,cnt+1});
        }
        ns=stair-D;
        if(!visit[ns]&&ns>=1){
            visit[ns]=true;
            q.push({ns,cnt+1});
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(visit,false,sizeof(visit));
    cin>>F>>S>>G>>U>>D;
    if(bfs())
        cout<<result;
    else
        cout<<"use the stairs";

    return 0;
}
