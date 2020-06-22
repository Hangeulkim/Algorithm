#include<bits/stdc++.h>

using namespace std;

int s,j,h;
int cola,soda;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>j>>h;
    cin>>cola>>soda;
    int result=987654321;
    result=min(s,j);
    result=min(result,h);

    if(cola>soda)
        result+=soda;
    else
        result+=cola;
    result-=50;

    cout<<result<<'\n';

    return 0;
}
