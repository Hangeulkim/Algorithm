#include<bits/stdc++.h>

using namespace std;

long long int N;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long int result=1;
    cin>>N;
    for(int i=2;i<=N;i++){
        result*=i;
    }
    cout<<result;

    return 0;
}
