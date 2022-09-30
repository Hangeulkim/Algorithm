#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<pair<int,int> > W;
int chk[15];
int ret=0;

void Initialize(){
    fill(&chk[0],&chk[15],-1);
}

void Input(){
    int a,b;
    cin>>N;

    for(int i=0;i<N;i++){
        cin>>a>>b;
        W.push_back({a,b});
    }
    sort(W.begin(),W.end());
}

int next_hole(int idx){
    int y = W[idx].second;
    int x = W[idx].first;
    for(int i=0;i<N;i++){
        int ny = W[i].second;
        int nx = W[i].first;
        if(y==ny && x<nx){
            return i;
        }
    }
    return -1;
}

bool calc(int now){
    bool loop[15];
    fill(&loop[0],&loop[15],false);
        
    int next;
    while(true){
        if(loop[now]) break;
        
        loop[now] = true;
        next = chk[now];
        now = next_hole(next);
        if(now==-1) return false;
    }

    return true;
}

void dfs(int idx, int cnt){
    if(cnt==N){
        for(int i=0;i<N;i++){
            if(calc(i)){
                ret++;
                break;
            }
        }
        return ;
    }

    for(int i=idx;i<N;i++){
        if(chk[i]!=-1) continue;
        
        for(int j=i+1;j<N;j++){
            if(chk[j]!=-1) continue;
            chk[i]=j;
            chk[j]=i;

            dfs(i+1,cnt+2);

            chk[i]=chk[j]=-1;
        }
    }
}

void Solution(){
    dfs(0,0);

    cout<<ret<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();
    Initialize();
    Solution();

    return 0;
}