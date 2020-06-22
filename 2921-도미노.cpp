#include<bits/stdc++.h>

using namespace std;

int N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;

    long long result=0;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=i;j++){
            result+=i+j;
        }
    }
    cout<<result<<'\n';
    return 0;
}
