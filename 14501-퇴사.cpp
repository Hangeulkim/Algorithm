#include<bits/stdc++.h>

using namespace std;

int N,result=0;
vector<pair<int, int> > input;

void dfs(int idx, int sum){
    if(idx>=N) {
        result=max(result,sum);
        return ;
    }

    dfs(idx+1,sum);
    if(idx+input[idx].first<=N){
        dfs(idx+input[idx].first,sum+input[idx].second);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tmp1,tmp2;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp1>>tmp2;
        input.push_back({tmp1,tmp2});
    }

    dfs(0,0);
    cout<<result<<'\n';

    return 0;
}
