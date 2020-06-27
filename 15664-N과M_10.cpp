#include<bits/stdc++.h>

using namespace std;

int N,M;
int arr[10];
bool chk[10];
vector<int> input;
void dfs(int idx, int cnt){
    if(cnt==M){
        for(int i=0;i<M;i++)
            cout<<arr[i]<<" ";
        cout<<'\n';
        return ;
    }

    bool s[10001]={false,};

    for(int i=idx;i<N;i++){
        if(!s[input[i]]&&!chk[i]){
            chk[i]=true;
            arr[cnt]=input[i];
            dfs(i+1,cnt+1);
            chk[i]=false;
            s[input[i]]=true;
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
        input.push_back(tmp);
        chk[i]=false;
    }
    sort(input.begin(),input.end());
    dfs(0, 0);

    return 0;
}
