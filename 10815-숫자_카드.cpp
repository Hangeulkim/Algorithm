#include<bits/stdc++.h>

using namespace std;

map<int, bool> have;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N,M,tmp=0;

    cin>>N;
    while(N--){
        cin>>tmp;
        have[tmp]=true;
    }

    cin>>M;
    while(M--){
        cin>>tmp;
        if(have.find(tmp)==have.end()){
            cout<<0<<" ";
        }
        else{
            cout<<1<<" ";
        }
    }

    return 0;
}
