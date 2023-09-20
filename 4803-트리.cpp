#include<iostream>
#include<vector>

using namespace std;

int n,m;
vector<int> tree[501];
bool chk[501];
int num;
int edge;

void init(){
    num = 0;
    for(int i=0;i<501;++i){
        tree[i].clear();
        chk[i]=false;
    }
}

void input(){
    int a,b;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
}

int dfs(int node){
    int nodes = 1;
    if(chk[node])
        return 0;

    chk[node] = true;
    for(int i=0;i<tree[node].size();++i){
        int next = tree[node][i];
        ++edge;
        if(!chk[next]){
            nodes += dfs(next);
        }
    }

    return nodes;
}

void calc(int idx){

    cout<<"Case "<<idx<<": ";
    if(num==1){
        cout<<"There is one tree.";
    }
    else if(num==0){
        cout<<"No trees.";
    }
    else{
        cout<<"A forest of "<<num<<" trees.";
    }
    cout<<'\n';
}

void solution(){
    int idx=0;

    while(1){
        ++idx;
        cin>>n>>m;

        if(m==0 && n==0)
            break;

        init();
        input();
        for(int i=1;i<=n;++i){
            if(chk[i])
                continue;
            
            edge = 0;
            int nodeNum = dfs(i);

            if(nodeNum - edge/2 == 1)
                ++num;
        }
        calc(idx);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}