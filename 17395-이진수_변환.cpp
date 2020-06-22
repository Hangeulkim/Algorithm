#include<bits/stdc++.h>

using namespace std;

long long int input,tmpin;
int arr[1001];
vector<long long> result;
int N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>input>>N;
    tmpin=input;

    int i=0;
    int cnt=0;
    for(i=0;input!=0;i++){
        arr[i]=input%2;
        input/=2;
    }
    for(;i>=0;i--){
        if(arr[i]==1){
            tmpin-=(long long)1<<i;
            result.push_back(tmpin);
        }
    }
    if(N>result.size()) cout<<-1<<'\n';
    else{
        for(int i=0;i<N-1;i++){
            cout<<result[i]<<" ";
        }
        cout<<0<<'\n';
    }

    return 0;
}
