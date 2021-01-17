#include<bits/stdc++.h>

using namespace std;

int N;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=2;i*i<=N;i++){
        if(N%i==0){
            cout<<i<<'\n';
            N/=i;
            i--;
        }
    }
    if(N!=1)
        cout<<N<<'\n';

    return 0;
}
