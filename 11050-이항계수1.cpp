#include<bits/stdc++.h>

using namespace std;

int N,K;
int mo=1,ja=1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>K;
    for(int i=0;i<K;i++){
        mo*=(N-i);
        ja*=(i+1);
    }
    cout<<mo/ja<<'\n';

    return 0;
}
