#include<bits/stdc++.h>

using namespace std;

int N,M;
int arr[10];
set<int> input;
void dfs(set<int>::iterator iter, int cnt){
    if(cnt==M){
        for(int i=0;i<M;i++)
            cout<<arr[i]<<" ";
        cout<<'\n';
        return ;
    }

    for(auto it=iter;it!=input.end();it++){
        arr[cnt]=*it;
        dfs(it,cnt+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tmp;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>tmp;
        input.insert(tmp);
    }

    dfs(input.begin(),0);

    return 0;
}
