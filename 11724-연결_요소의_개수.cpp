#include<bits/stdc++.h>

using namespace std;

int N,M;
int cnt=0;
bool visit[1001]={false,};
vector<int> input[1001];


void dfs(int idx){
    visit[idx]=true;

    for(int i=0;i<input[idx].size();i++){
        int next=input[idx][i];
        if(!visit[next])
            dfs(next);
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
        input[tmp1].push_back(tmp2);
        input[tmp2].push_back(tmp1);
    }
    for(int i=1;i<=N;i++){
        if(!visit[i]){
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt<<'\n';

    return 0;
}
