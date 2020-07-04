#include<bits/stdc++.h>

using namespace std;

int N,K;
string input;
vector<char> arr[51];
bool visit[256];
int result=0;

void dfs(int cnt, int start){
    if(cnt<=0){
        int cnt=0;
        bool chk;
        for(int i=1;i<=N;i++){
            chk=true;
            for(int j=0;j<arr[i].size();j++){
                if(!visit[arr[i][j]]){
                    chk=false;
                    break;
                }
            }
            if(chk)
                cnt++;
        }
        result=max(result,cnt);
        return;
    }

    for(int i=start;i<='z';i++){
        if(i!='n'&&i!='t'&&i!='i'&&i!='c'){
            if(!visit[i]){
                visit[i]=true;
                dfs(cnt-1,i+1);
                visit[i]=false;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>K;
    K-=5;
    visit['a']=true;
    visit['n']=true;
    visit['t']=true;
    visit['i']=true;
    visit['c']=true;
    for(int i=1;i<=N;i++){
        cin>>input;
        for(int j=4;j<input.length()-4;j++){
            arr[i].push_back(input[j]);
        }
        sort(arr[i].begin(),arr[i].end());
        arr[i].erase(unique(arr[i].begin(),arr[i].end()),arr[i].end());
    }
    if(K<0)
        cout<<0<<'\n';
    else{
        dfs(K,'b');
        cout<<result<<'\n';
    }
    return 0;
}
