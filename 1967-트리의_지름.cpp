#include<bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int> > way[10001];
bool chk[10001];
int ed=1,result=0;

void dfs(int node, int leng){
    if(result < leng){
        ed = node;
        result = leng;
    }

    for(auto it : way[node]){
        int next = it.first;
        int cost = it.second;

        if(chk[next])
            continue;
        
        chk[next]=true;
        dfs(next, leng+cost);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(chk,false,sizeof(chk));
    cin>>n;
    int s,e,l;
    for(int i=1;i<n;i++){
        cin>>s>>e>>l;
        way[s].push_back({e,l});
        way[e].push_back({s,l});
    }

    chk[ed]=true;
    dfs(ed,0);

    memset(chk,false,sizeof(chk));
    chk[ed]=true;
    dfs(ed,0);
    cout<<result;
    return 0;
}