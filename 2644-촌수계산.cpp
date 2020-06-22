#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> input[101];
bool check[101],cflag=false;
void dfs(int start,int end,bool check[101],int cnt){
    if(start==end){
        cout<<cnt<<'\n';
        cflag=true;
        return ;
    }
    check[start]=true;
    cnt++;
    for(int i=0;i<input[start].size();i++){
        if(!check[input[start][i]]){
            dfs(input[start][i],end,check,cnt);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill(check,check+101,false);
    int n,start,end;
    cin>>n>>start>>end;
    int testcase,a,b;
    cin>>testcase;
    while(testcase--){
        cin>>a>>b;
        input[a].push_back(b);
        input[b].push_back(a);
    }
    dfs(start,end,check,0);
    if(!cflag) cout<<"-1"<<'\n';

    return 0;
}
