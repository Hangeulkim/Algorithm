#include<bits/stdc++.h>

using namespace std;

int N,M,result=0;
vector<int> way[2001];
bool visit[2001]={false,};

void dfs(int idx, int depth){
    visit[idx]=true;
    if(depth==4){
        result=1;
        return ;
    }
    for(int i=0;i<way[idx].size();i++){
        int next=way[idx][i];
        if(!visit[next]){
            dfs(next,depth+1);
            visit[next]=false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tmp1,tmp2;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>tmp1>>tmp2;
        way[tmp1].push_back(tmp2);
        way[tmp2].push_back(tmp1);
    }
    for(int i=0;i<N;i++){
        dfs(i,0);
        visit[i]=false;
        if(result==1)
            break;
    }

    cout<<result;

    return 0;
}
