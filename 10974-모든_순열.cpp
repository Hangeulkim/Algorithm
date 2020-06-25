#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    vector<int> input;
    cin>>N;

    for(int i=1;i<=N;i++){
        input.push_back(i);
    }
    do {
        for(int i=0;i<N;i++){
            cout<<input[i]<<" ";
        }
        cout<<'\n';
    } while(next_permutation(input.begin(),input.end()));

    return 0;
}
