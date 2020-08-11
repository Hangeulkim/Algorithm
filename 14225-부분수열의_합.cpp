#include<bits/stdc++.h>

using namespace std;

bool chk[2000001]={false,};
int N;
int input[21];

void dfs(int idx, int num){
    chk[num]=true;
    if(idx>N)
        return;
    dfs(idx+1,num+input[idx]);
    dfs(idx+1,num);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    int tmp;
    for(int i=1;i<=N;i++){
        cin>>input[i];
    }

    dfs(1,0);

    for(int i=1;i<2000001;i++){
        if(!chk[i]){
            cout<<i<<'\n';
            break;
        }
    }

    return 0;
}
