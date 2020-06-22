#include<bits/stdc++.h>

using namespace std;

int M,N,tmp;
unsigned long long  btm=1,top;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    vector<unsigned long long> input(N);
    for(int i=0;i<N;i++){
        cin>>input[i];
    }
    sort(input.begin(),input.end());

    unsigned long long result=0;
    top=input[N-1]*M;
    while(btm<=top){
        unsigned long long mid=(btm+top)/2;
        unsigned long long sum=0;

        for(int i=0;i<N;i++){
            sum+=mid/input[i];
        }
        if(sum>=M){
            top=mid-1;
            result=mid;
        }
        else
            btm=mid+1;
    }
    cout<<result<<'\n';

    return 0;
}
