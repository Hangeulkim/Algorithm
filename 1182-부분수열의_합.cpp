#include<bits/stdc++.h>

using namespace std;

vector<int> input;
int N,S,tmp,cnt=0;

void dfs(int sum,int num){
    for(int i=num;i<N;i++){
        if(sum+input[i]==S){
            cnt++;
        }
        dfs(sum+input[i],i+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>S;

    for(int i=0;i<N;i++){
        cin>>tmp;
        input.push_back(tmp);
    }

    dfs(0,0);

    cout<<cnt<<'\n';

    return 0;
}
