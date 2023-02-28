#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int N,M;
string tmp;
map<string, int> vocalist;

void input(){
    cin>>N>>M;
    while(N--){
        cin>>tmp;
        
        if(tmp.length() < M)
            continue;

        if(vocalist.find(tmp) == vocalist.end()){
            vocalist[tmp]=1;
        }
        else{
            ++vocalist[tmp];
        }
    }
}

bool cussort(pair<string, int> &a, pair<string, int> &b){
    if(a.second == b.second){
        if(a.first.length()==b.first.length())
            return a.first < b.first;
        return a.first.length() > b.first.length();
    }
    return a.second > b.second;
}

void solution(){
    vector<pair<string, int> > ans (vocalist.begin(), vocalist.end());
    sort(ans.begin(),ans.end(),cussort);
    for(int i=0,len=ans.size();i<len;++i){
        cout<<ans[i].first<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}