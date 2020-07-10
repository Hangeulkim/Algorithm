#include<bits/stdc++.h>

using namespace std;

int N,K;
long long ret=0,last=98765321;
int visit[100011];

void bfs(){
    memset(visit,-1,sizeof(visit));
    queue<pair<int, int> > q;
    visit[N]=0;
    q.push({N,0});

    while(!q.empty()){
        int num=q.front().first;
        int cnt=q.front().second;

        q.pop();

        if(cnt>last){
            return ;
        }

        if(num==K){
            ret++;
            last=cnt;
        }

        if(num+1<100010&&(visit[num+1]>cnt||visit[num+1]==-1)){
            q.push({num+1,cnt+1});
            visit[num+1]=cnt+1;
        }
        if(num-1>=0&&(visit[num-1]>cnt||visit[num-1]==-1)){
            q.push({num-1,cnt+1});
            visit[num-1]=cnt+1;
        }
        if(num*2<100010&&(visit[num*2]>cnt||visit[num*2]==-1)){
            q.push({num*2,cnt+1});
            visit[num*2]=cnt+1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>K;
    bfs();
    cout<<last<<'\n'<<ret<<'\n';

    return 0;
}
