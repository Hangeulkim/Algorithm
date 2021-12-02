#include<bits/stdc++.h>

using namespace std;

int V;
vector<pair<int, int> > line[100001];
bool chk[100001];
int ret_len=0, ret_node=0;

void dfs(int start, int len){
    if(len > ret_len){
        ret_len = len;
        ret_node = start;
    }

    for(auto it : line[start]){
        int end = it.first;
        int leng = it.second;
        if(chk[end])
            continue;
        chk[end]=true;
        dfs(end,len+leng);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(chk,false,sizeof(chk));
    cin>>V;
    int num, wh, lg;
    for(int i=0;i<V;i++){
        cin>>num;
        while(true){
            cin>>wh;
            if(wh == -1)
                break;
            cin>>lg;
            line[num].push_back({wh,lg});
        }
    }
    chk[1]=true;
    dfs(1,0);
    memset(chk,false,sizeof(chk));
    chk[ret_node]=true;
    dfs(ret_node,0);
    cout<<ret_len;

    return 0;
}