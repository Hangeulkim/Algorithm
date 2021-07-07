#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> input[100001];
int a,b;
queue<int> vis;
bool chk[100001];

void dfs(int num){
    if(vis.empty())
        return ;
    set<int> s;
    for(auto it : input[num]){
        if(chk[it])
            continue;
        s.insert(it);
    }

    int sz = s.size();
    for(int i=0;i<sz;i++){
        int tmp=vis.front();
        if(s.find(tmp)==s.end())
            return ;

        vis.pop();
        chk[tmp]=true;
        dfs(tmp);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=0;i<N-1;i++){
        cin>>a>>b;
        input[a].push_back(b);
        input[b].push_back(a);
    }

    for(int i=0;i<N;i++){
        cin>>a;
        vis.push(a);
    }

    int num=vis.front();
    if(num==1){
        chk[1]=true;
        vis.pop();
        dfs(1);
    }
    
    
    if(vis.empty())
        cout<<1;
    else
        cout<<0;

    return 0;
}