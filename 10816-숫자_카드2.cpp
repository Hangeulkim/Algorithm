#include<bits/stdc++.h>

using namespace std;

map<int, int> input;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N,M,tmp;

    cin>>N;
    while(N--){
        cin>>tmp;
        auto iter = input.find(tmp);
        if(iter==input.end()){
            input[tmp]=1;
        }
        else{
            input[tmp]++;
        }
    }

    cin>>M;
    while(M--){
        cin>>tmp;
        auto iter = input.find(tmp);
        if(iter==input.end()){
            cout<<"0 ";
        }
        else{
            cout<<iter->second<<" ";
        }
    }

    return 0;
}
