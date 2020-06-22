#include<bits/stdc++.h>

using namespace std;

int N,tmp;
vector<int> input;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        input.push_back(tmp);
    }

    int result=0;
    sort(input.begin(),input.end(),less<int>());

    for(int i=0;i<N;i++){
        int tmp=input[i]*(N-i);
        if(tmp>result){
            result=tmp;
        }
    }

    cout<<result<<'\n';

    return 0;
}
