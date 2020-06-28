#include<bits/stdc++.h>

using namespace std;

typedef struct Data{
    int where;
    int time;
}data;

int N,K;
bool visit[100001]={false,};
int bfs(){
    deque<data> dq;

    dq.push_front({N,0});
    visit[N]=true;
    while(!dq.empty()){
        int where=dq.front().where;
        int time=dq.front().time;

        dq.pop_front();
        if(where==K)
            return time;


        if(2*where<100001&&!visit[2*where]){
            visit[2*where]=true;
            dq.push_front({2*where,time});
        }
        if(where-1>=0&&!visit[where-1]){
            visit[where-1]=true;
            dq.push_back({where-1,time+1});
        }
        if(where+1<100001&&!visit[where+1]){
            visit[where+1]=true;
            dq.push_back({where+1,time+1});
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>K;

    cout<<bfs()<<'\n';

    return 0;
}
