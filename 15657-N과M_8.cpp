#include<bits/stdc++.h>

using namespace std;

int N,M;
int arr[10];
vector<int> input;
void dfs(int idx, int cnt){
    if(cnt==M){
        for(int i=0;i<M;i++)
            cout<<arr[i]<<" ";
        cout<<'\n';
        return ;
    }
    for(int i=idx;i<N;i++){
        arr[cnt]=input[i];
        dfs(i,cnt+1);
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
        input.push_back(tmp);
    }
    sort(input.begin(),input.end());
    dfs(0,0);

    return 0;
}
