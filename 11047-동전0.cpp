#include<bits/stdc++.h>

using namespace std;
int N,K;
vector<int> input;
int result;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>K;
    int tmp;
    for(int i=0;i<N;i++){
        cin>>tmp;
        input.push_back(tmp);
    }

    for(int i=N-1;i>=0&&K!=0;i--){
        if(K/input[i]!=0){
            result+=K/input[i];
            K%=input[i];
        }
    }
    cout<<result<<'\n';

    return 0;
}
