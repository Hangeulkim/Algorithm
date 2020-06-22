#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b,v;
    cin>>a>>b>>v;


    if(a>=v) cout<<1<<'\n';
    else{
        cout<<(int)ceil((double)(v-a)/(a-b))+1;
    }

    return 0;
}
