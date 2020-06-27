#include<bits/stdc++.h>

using namespace std;

int N,M;
int arr[10];
void dfs(int cnt){
    if(cnt==M){
        for(int i=0;i<M;i++)
            cout<<arr[i]<<" ";
        cout<<'\n';
        return ;
    }
    for(int i=1;i<=N;i++){
        arr[cnt]=i;
        dfs(cnt+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    dfs(0);

    return 0;
}
