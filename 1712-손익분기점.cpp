#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b,c,profit;

    cin>>a>>b>>c;
    profit=c-b;
    if(profit<=0) cout<<-1;
    else cout<<a/profit+1;

    return 0;
}
