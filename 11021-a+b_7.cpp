#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testcase=0,a=0,b=0;
    cin>>testcase;
    for(int i=1;i<=testcase;i++){
        cin>>a>>b;
        cout<<"Case #"<<i<<": "<<a+b<<'\n';
    }

    return 0;
}
