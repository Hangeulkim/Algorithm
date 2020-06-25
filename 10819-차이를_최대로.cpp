#include<bits/stdc++.h>

using namespace std;
int N;
vector<int> input;

int val(){
    int result=0;
    for(int i=0;i<N-1;i++){
        if(input[i]>input[i+1]){
            result+=input[i]-input[i+1];
        }
        else{
            result+=input[i+1]-input[i];
        }
    }

    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tmp;
    int result=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        input.push_back(tmp);
    }

    sort(input.begin(),input.end(),less<int>());
    do {
        result=max(result,val());
    } while(next_permutation(input.begin(),input.end()));
    cout<<result<<'\n';

    return 0;
}
