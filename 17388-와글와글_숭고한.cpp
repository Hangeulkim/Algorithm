#include<bits/stdc++.h>

using namespace std;

int S,K,H;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>S>>K>>H;

    if(S+K+H>=100) cout<<"OK\n";
    else if(S<K&&S<H) cout<<"Soongsil\n";
    else if(K<S&&K<H) cout<<"Korea\n";
    else cout<<"Hanyang\n";

    return 0;
}
