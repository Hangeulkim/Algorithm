#include<bits/stdc++.h>

using namespace std;

int L,C;
char mo[5]={'a','e','i','o','u'};
vector<char> input;

void dfs(int idx, int cnt, int m, int j, string dat){
    if(cnt==L){
        if(m>=1&&j>=2)
            cout<<dat<<'\n';
        return;
    }
    if(idx==C) return;
    bool mflag=false;

    for(int i=0;i<5;i++){
        if(mo[i]==input[idx]){
            dat.push_back(input[idx]);
            dfs(idx+1,cnt+1,m+1,j,dat);
            mflag=true;
            break;
        }
    }
    if(!mflag){
        dat.push_back(input[idx]);
        dfs(idx+1,cnt+1,m,j+1,dat);
    }
    dat.pop_back();
    dfs(idx+1,cnt,m,j,dat);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char tmp;
    cin>>L>>C;
    for(int i=0;i<C;i++){
        cin>>tmp;
        input.push_back(tmp);
    }
    sort(input.begin(),input.end());

    dfs(0,0,0,0,"");

    return 0;
}
