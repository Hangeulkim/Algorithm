#include<iostream>
#include<queue>
#include<vector>

using namespace std;

typedef struct Dat{
    int node;
    char sign;
}d;

char chk[50001];
vector<int> way[50001];
int N,M;

void Initialize(){
    fill(&chk[0],&chk[50001],0);
}

void Input(){
    cin>>N>>M;

    int a,b;
    for(int i=0;i<M;i++){
        cin>>a>>b;
        way[a].push_back(b);
        way[b].push_back(a);
    }
}

int bfs(int start){
    int jcnt=0;
    int fcnt=0;
    queue<d> q;

    q.push({start,'J'});
    chk[start]='J';

    while(!q.empty()){
        int node = q.front().node;
        char sign = q.front().sign;

        q.pop();

        if(sign=='F')
            fcnt++;
        else
            jcnt++;

        for(int i=0;i<way[node].size();i++){
            int next = way[node][i];

            if(chk[next]==sign)
                return -1;
            
            if(chk[next])
                continue;
            
            chk[next] = sign=='F'?'J':'F';
            q.push({next,chk[next]});
        }
    }
    return max(jcnt,fcnt);
}

void Solution(){
    int ret=0;
    for(int i=1;i<=N;i++){
        if(chk[i])
            continue;
        int tmp = bfs(i);
        if(tmp == -1){
            cout<<tmp<<'\n';
            return ;
        }
        ret+=tmp;
    }
    
    cout<<ret<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Initialize();
    Input();
    Solution();

    return 0;
}