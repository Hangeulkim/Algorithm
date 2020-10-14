#include<bits/stdc++.h>

using namespace std;
long long int a,b,c,d;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>a>>b>>c>>d;
    int tmp=1;
    for(tmp=1;tmp<b;tmp*=10)
        a*=10;
    for(tmp=1;tmp<d;tmp*=10)
        c*=10;
    a+=b;
    c+=d;

    cout<<a+c<<'\n';

    return 0;
}
