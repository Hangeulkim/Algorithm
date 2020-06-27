#include<bits/stdc++.h>

using namespace std;

int N,M;
int arr[10];
bool visit[10];
vector<int> input;
void dfs(int idx,int cnt){
    if(cnt==M){
        for(int i=0;i<M;i++)
            cout<<arr[i]<<" ";
        cout<<'\n';
        return ;
    }
    for(int i=0;i<N;i++){
        if(visit[i]==false){
            visit[i]=true;
            arr[cnt]=input[i];
            dfs(i+1,cnt+1);
            visit[i]=false;
        }
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
        visit[i]=false;
        input.push_back(tmp);
    }
    sort(input.begin(),input.end());
    dfs(0,0);

    return 0;
}
