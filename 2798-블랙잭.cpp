#include<bits/stdc++.h>

using namespace std;

int N;
int M;
vector<int> input;
int ret=0;
bool chk[101];

void dfs(int cnt, int sum){
    if(sum>M)
        return;
    if(cnt==3){
        ret=max(ret,sum);
        return;
    }


    for(int i=0;i<N;i++){
        if(chk[i])
            continue;
        else{
            chk[i]=true;
            dfs(cnt+1,sum+input[i]);
            chk[i]=false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(chk,false,sizeof(chk));
    cin>>N>>M;

    int tmp;
    for (int i = 0; i < N; i++) {
        cin>>tmp;
        input.push_back(tmp);
    }
    dfs(0,0);
    cout<<ret;

    return 0;
}
