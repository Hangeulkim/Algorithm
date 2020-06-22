#include<bits/stdc++.h>

using namespace std;

int N,M,tmp;
long long btm=1,top;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    vector<int> input(N);
    for(int i=0;i<N;i++){
        cin>>input[i];
    }
    cin>>M;

    sort(input.begin(),input.end());

    long long result=0;
    top=input[N-1];
    while(top>=btm){
        long long mid = (top+btm)/2;
        long long sum=0;

        for(int i=0;i<N;i++){
            if(input[i]<mid){
                sum+=input[i];
            }
            else{
                sum+=mid;
            }
        }

        if(sum<=M){
            btm=mid+1;
            if(mid>result)
                result=mid;
        }
        else
            top=mid-1;
    }

    cout<<result<<'\n';

    return 0;
}
