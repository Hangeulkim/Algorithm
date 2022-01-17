#include<bits/stdc++.h>

using namespace std;

int N,tmp;
vector<int> x;
vector<int> input;
map<int,int> id;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    while(N--){
        cin>>tmp;
        x.push_back(tmp);
        input.push_back(tmp);
    }
    sort(input.begin(),input.end());
    input.erase(unique(input.begin(),input.end()),input.end());

    int cnt=0;
    for(auto it : input){
        id[it]=cnt++;
    }

    for(auto it : x)
        cout<<id[it]<<" ";

    return 0;
}