#include<bits/stdc++.h>

using namespace std;

int N;
int result=0,tmp;
vector<int> input;

void dfs(int cnt, int s){
    if(cnt<=2){
        result=max(result,s);
        return;
    }

    for(int i=2;i<cnt;i++){
        int num=input[i];
        input.erase(input.begin()+i);
        dfs(cnt-1,s+input[i-1]*input[i]);
        input.insert(input.begin()+i,num);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    input.push_back(0);
    for(int i=1;i<=N;i++){
        cin>>tmp;
        input.push_back(tmp);
    }
    dfs(N,0);
    cout<<result<<'\n';

    return 0;
}
