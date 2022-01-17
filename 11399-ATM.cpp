#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> input;
int tmp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        input.push_back(tmp);
    }
    sort(input.begin(),input.end(),greater<>());
    int ret=0;
    for(int i=N;i>0;i--){
        ret+=input[i-1]*i;
    }
    cout<<ret<<'\n';


    return 0;
}