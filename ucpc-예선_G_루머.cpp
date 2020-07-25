#include<bits/stdc++.h>

using namespace std;

int N,tmp,T;
vector<int> input[200001];
vector<int> start;
int know[200001];
int who[200001];

void bfs(){
    memset(know,-1,sizeof(know));
    memset(who,0,sizeof(who));
    queue<int> q;
    for(int i=0;i<T;i++){
        q.push(start[i]);
        know[start[i]]=0;
    }

    while(!q.empty()){
        int where=q.front();
        int cnt=know[where];

        q.pop();

        int sz=input[where].size();
        for(int i=0;i<sz;i++){
            int next=input[where][i];
            who[next]++;

            if(know[next]!=-1) continue;

            if(who[next]*2>=input[next].size())
                know[next]=cnt+1;
            else
                continue;
            q.push(next);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=1;i<=N;i++){
        while(1){
            cin>>tmp;
            if(tmp==0) break;
            input[i].push_back(tmp);
        }
    }
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>tmp;
        start.push_back(tmp);
    }
    bfs();
    for(int i=1;i<=N;i++){
        cout<<know[i]<<" ";
    }

    return 0;
}
