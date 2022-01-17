#include<bits/stdc++.h>

using namespace std;

int N,M;
map<string,string> m;
string net,pass;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    while(N--){
        cin>>net>>pass;
        m[net]=pass;
    }
    while(M--){
        cin>>net;
        cout<<m[net]<<'\n';
    }

    return 0;
}