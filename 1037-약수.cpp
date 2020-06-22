#include<bits/stdc++.h>

using namespace std;
long long int N,tmp;

vector<long long int> input;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        input.push_back(tmp);
    }
    long long int result=0;

    sort(input.begin(),input.end());

    if(N==1){
        result=input[0]*input[0];
    }
    else{
        result=input[0]*input[N-1];
    }
    cout<<result<<'\n';

    return 0;
}
