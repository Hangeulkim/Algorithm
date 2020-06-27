#include<bits/stdc++.h>

using namespace std;

int N,M;

void dfs(int num, int cnt, string dat){
    if(num>N+1)
        return;
    if(cnt==M){
        if(num<=N+1)
            cout<<dat<<'\n';
        return ;
    }

    dfs(num+1,cnt+1,dat+to_string(num)+" ");
    dfs(num+1,cnt,dat);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    dfs(1,0,"");

    return 0;
}
