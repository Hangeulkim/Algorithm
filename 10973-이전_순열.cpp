#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> input;
    int N,tmp;
    cin>>N;

    for(int i=0;i<N;i++){
        cin>>tmp;
        input.push_back(tmp);
    }

    if(prev_permutation(input.begin(),input.end()))
        for(int i=0;i<N;i++)
            cout<<input[i]<<" ";
    else
        cout<<-1;

    return 0;
}
