#include<bits/stdc++.h>

using namespace std;

map<int, bool, less<int> > input;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N,tmp;
    cin>>N;
    while(N--){
        cin>>tmp;
        input[tmp]=true;
    }

    for(auto iter = input.begin();iter!=input.end();iter++){
        cout<<iter->first<<" ";
    }

    return 0;
}
