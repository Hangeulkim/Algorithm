#include<bits/stdc++.h>

using namespace std;

long long int K,N,tmp;
long long int top,btm=1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>K>>N;
    vector<long long int> input;
    for(int i=0;i<K;i++){
        cin>>tmp;
        input.push_back(tmp);
        top=max(top,input[i]);
    }

    long long result=0;

    while(top>=btm){
        long long mid=(top+btm)/2;
        long long sum=0;

        for(int i=0;i<K;i++)
            sum+=input[i]/mid;

        if(sum>=N){
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
