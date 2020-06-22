#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> result;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n=0,fi=0;
    cin>>n>>fi;
    int nin=0,nout=0;
    result.push_back(fi);
    for(int i=0;i<n;i++){
        cin>>nin>>nout;
        result.push_back(result[i]+nin-nout);
    }
    if(*min_element(result.begin(),result.end())<0) cout<<0<<'\n';
    else cout<<*max_element(result.begin(),result.end())<<'\n';

    return 0;
}
